#include "channel.h"

#include <arpa/inet.h>
#include <errno.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <google/protobuf/service.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdio>
#include <string>

#include "rpcheader.pb.h"
#include "zkclient.h"

/*
    客户端打包请求并统一发送RPC请求给服务端
    消息的格式是：[header_length] + [service_name method_name args_length] + [args]
    所有通过stub代理对象(客户端)调用的rpc方法，都走到这里了
    统一做rpc方法调用的数据数据序列化和网络发送
*/
void XgrpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
                              google::protobuf::RpcController* controller,
                              const google::protobuf::Message* request,
                              google::protobuf::Message* response,
                              google::protobuf::Closure* done) {
    // 根据method描述信息，获取service_name及method_name
    std::string service_name = method->service()->name();
    std::string method_name = method->name();

    // 获取请求（参数）序列化后的字符串长度
    uint32_t args_length = 0;
    std::string args_str = "";
    if (request->SerializeToString(&args_str)) {
        args_length = args_str.length();
    } else {
        controller->SetFailed("serialize request error!");
        return;
    }

    // 打包RPC请求消息:
    // send_rpc_str: [header_length] + [service_name method_name args_length] + [args]
    //                                 [             rpcHeader              ]
    xgrpc::RpcHeader rpcHeader;
    rpcHeader.set_service_name(service_name);
    rpcHeader.set_method_name(method_name);
    rpcHeader.set_args_length(args_length);

    uint32_t header_length = 0;
    std::string rpcHeader_str;
    if (rpcHeader.SerializeToString(&rpcHeader_str)) {
        header_length = rpcHeader_str.length();
    } else {
        controller->SetFailed("serialize rpc header error!");
        return;
    }

    std::string send_rpc_str = "";
    // send_rpc_str的前4字节，是header_length
    send_rpc_str += (std::string((char*)&header_length, 4)) + rpcHeader_str + args_str;

    //打印调试信息
    std::cout << "============================================" << std::endl;
    std::cout << "header_size: " << header_length << std::endl;
    std::cout << "rpc_header_str: " << rpcHeader_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "============================================" << std::endl;

    /*
        因为是客户端，消费者，不需要高并发
        以下直接使用普通的socket TCP网络编程实现
        完成rpc方法的远程调用
    */
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == clientfd) {
        char errorText[128] = {0};
        sprintf(errorText, "create socket error! errno: %d", errno);
        controller->SetFailed(errorText);
        return;
    }

    // 启动zookeeper客户端，连接zkServer，查该服务所在host（ip:port）信息
    ZkClient zkClient;
    zkClient.Start();  // Start()中会连接zkServer，进行zk的init
    std::string method_path = '/' + service_name + '/' + method_name;
    std::string method_host = zkClient.GetValue(method_path.c_str());
    if ("" == method_host) {
        controller->SetFailed(method_path + " is not exist!");
        return;
    }

    std::size_t pos = method_host.find(':');
    if (pos == std::string::npos) {
        controller->SetFailed(method_path + " address is invalid!");
        return;
    }
    std::string method_ip = method_host.substr(0, pos);
    uint16_t method_port = stoi(method_host.substr(pos + 1));

    // 注册一个用于连接远程rpc服务器的地址结构体
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(method_ip.c_str());
    server_addr.sin_port = htons(method_port);
    // 上处一定要记得将本地字节序转化成网络字节序！！！否则连不上服务器！

    // connect
    if (-1 == connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr))) {
        close(clientfd);
        char errorText[128] = {0};
        sprintf(errorText, "connect error! errno: %d", errno);
        controller->SetFailed(errorText);
        return;
    }

    // send send_rpc_str
    if (-1 == send(clientfd, send_rpc_str.c_str(), send_rpc_str.size(), 0)) {
        close(clientfd);
        char errorText[128] = {0};
        sprintf(errorText, "send error! errno: %d", errno);
        controller->SetFailed(errorText);
        return;
    }

    // recv response data
    char recv_buf[1024] = {0};
    int recv_size = 0;
    if (-1 == (recv_size = recv(clientfd, recv_buf, sizeof(recv_buf), 0))) {
        close(clientfd);
        char errorText[128] = {0};
        sprintf(errorText, "recv error! errno: %d", errno);
        controller->SetFailed(errorText);
        return;
    }

    // parse response data
    if (!response->ParseFromArray(recv_buf, recv_size)) {
        close(clientfd);
        char errorText[1152] = {0};
        sprintf(errorText, "parse error! recv_buf: %s", recv_buf);
        controller->SetFailed(errorText);
        return;
    }

    close(clientfd);
}
