#include "provider.h"

#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpServer.h>

#include <cstring>
#include <string>

#include "application.h"
#include "logger.h"
#include "rpcheader.pb.h"
#include "zkclient.h"

/*
    Register an RPC service
    往本服务器的服务表中注册一个新的服务信息：<service_name，service_info>
    参数service为protobuf中的服务，现在需要把其中的信息提取出来，储存到本机的哈希表中
*/
void XgrpcProvider::NotifyService(google::protobuf::Service* service) {
    // 先获取该服务的描述信息
    const google::protobuf::ServiceDescriptor* pserviceDesc = service->GetDescriptor();

    // 从描述信息中获取service_name
    std::string service_name = pserviceDesc->name();
    LOG_INFO("service_name:%s", service_name.c_str());

    // 从描述信息中提取信息并构造serviceInfo
    ServiceInfo serviceInfo;  // struct{service, methodMap<method_name, methodDesc>}
    serviceInfo.m_service = service;
    int methodCount = pserviceDesc->method_count();
    for (int i = 0; i < methodCount; ++i) {
        const google::protobuf::MethodDescriptor* pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        serviceInfo.m_methodMap.insert({method_name, pmethodDesc});
        LOG_INFO("method_name:%s", method_name.c_str());
    }

    // 将<service_name，service_info>记录插入到serviceMap中
    m_serviceMap.insert({service_name, serviceInfo});
}

/*
    start RPC service
    创建一个TcpServer对象，准备监听网络请求
    连接zookeeper，并向zk中注册服务
    开启服务器服务，epoll_wait
*/
void XgrpcProvider::Run() {
    // 读取配置文件中的本rpcserver的信息，并创建muduo Tcpserver对象
    std::string ip = XgrpcApplication::GetConfig().Load("rpcserverip");
    uint16_t port = std::stoi(XgrpcApplication::GetConfig().Load("rpcserverport"));
    muduo::net::InetAddress address(ip, port);
    muduo::net::TcpServer server(&m_eventLoop, address, "RpcProvider");

    // 绑定连接回调和消息读写回调函数
    server.setConnectionCallback(std::bind(&XgrpcProvider::OnConnection, this,
                                           std::placeholders::_1));
    server.setMessageCallback(std::bind(&XgrpcProvider::OnMessage, this,
                                        std::placeholders::_1,
                                        std::placeholders::_2,
                                        std::placeholders::_3));

    // 设置muduo库的线程数量, 1个I/O线程，3个工作线程
    server.setThreadNum(4);

    // 连接zookeeper，把当前rpc节点上要发布的服务全部注册到zk上面
    // 注：注册的服务名为永久节点（默认），注册的方法名为临时节点（ACL = ZOO_EPHEMERAL）
    ZkClient zkClient;
    zkClient.Start();
    for (auto& srvname_srvinfo : m_serviceMap) {
        // create server_name znode
        std::string serverpath = '/' + srvname_srvinfo.first;
        zkClient.Create(serverpath.c_str(), nullptr, 0);
        // crate method_names znode
        for (auto& mtname_mtdesc : srvname_srvinfo.second.m_methodMap) {
            std::string methodpath = serverpath + '/' + mtname_mtdesc.first;
            char methodpath_value[128] = {0};
            sprintf(methodpath_value, "%s:%d", ip.c_str(), port);
            zkClient.Create(methodpath.c_str(), methodpath_value, strlen(methodpath_value),
                            ZOO_EPHEMERAL);
        }
    }
    // 开启RPC服务器服务，epoll_wait
    std::cout << "RPC Provider service started at " << ip << ':' << port << std::endl;
    server.start();
    m_eventLoop.loop();
}

// 发生新的TCP连接请求时调用的回调函数
void XgrpcProvider::OnConnection(const muduo::net::TcpConnectionPtr& conn) {
    // 如果未能连接成功，则关闭本次连接的文件描述符
    if (!conn->connected())
        conn->shutdown();
}

// 处理已有TCP连接的回调函数，处理并响应RPC
void XgrpcProvider::OnMessage(const muduo::net::TcpConnectionPtr& conn,
                              muduo::net::Buffer* buffer,
                              muduo::Timestamp) {
    /*
      从receive buffer中读取字符流recvbuffer
        recbuffer组成：
        前4字节为头部长度                       header_length
        然后是长度为header_length的头部         rpcheader(service_name+method_name+args_length)
        最后是长度为args_length的参数序列       args
    */
    std::string recvbuffer = buffer->retrieveAllAsString();
    // 1. 先提取前4字节的头部长度字段
    uint32_t header_length = 0;
    recvbuffer.copy((char*)(&header_length), 4, 0);  // 从0下标位置拷贝4个字节的内容到header_size

    // 2. 提取头部字符序列，并反序列化（解析）字符序列，提取出头部信息
    std::string rpc_header_str = recvbuffer.substr(4, header_length);
    xgrpc::RpcHeader rpcHeader;
    std::string service_name;
    std::string method_name;
    uint32_t args_length;
    if (rpcHeader.ParseFromString(rpc_header_str)) {
        service_name = rpcHeader.service_name();
        method_name = rpcHeader.method_name();
        args_length = rpcHeader.args_length();
    } else {
        // rpc_header_str反序列化失败
        std::cout << "rpc_header_str parse error!" << std::endl;
        std::cout << "rpc_header_str: " << rpc_header_str << std::endl;
        return;
    }

    // 3. 提取rpc请求的参数信息
    std::string args_str = recvbuffer.substr(4 + header_length, args_length);

    /* -------- 打印调试信息 -------- */
    std::cout << "============================================" << std::endl;
    std::cout << "header_length: " << header_length << std::endl;
    std::cout << "rpc_header_str: " << rpc_header_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "============================================" << std::endl;

    /* -------- 根据请求的参数，调用本机中对应的服务，并返回响应 --------- */
    // 1. 找service
    auto sit = m_serviceMap.find(service_name);
    if (sit == m_serviceMap.end()) {
        std::cout << service_name << " is not exist!" << std::endl;
        return;
    }

    // 2. 找method
    auto mit = sit->second.m_methodMap.find(method_name);
    if (mit == sit->second.m_methodMap.end()) {
        std::cout << service_name << ':' << method_name << " is not exist!" << std::endl;
        return;
    }

    // 3. 通过protobuf::Service对象进行CallMethod()，调用当前rpc节点上发布是方法
    google::protobuf::Service* service = sit->second.m_service;      // 获取服务对象
    const google::protobuf::MethodDescriptor* method = mit->second;  // 获取方法对象

    google::protobuf::Message* request = service->GetRequestPrototype(method).New();  // 新建请求
    if (!request->ParseFromString(args_str)) {                                        // 解析请求字符串到请求对象中
        std::cout << "request parse error!" << std::endl;
        std::cout << "args: " << args_str << std::endl;
        return;
    }
    google::protobuf::Message* response = service->GetResponsePrototype(method).New();  // 新建响应

    // "done" will be called when the method is complete.
    google::protobuf::Closure* done = google::protobuf::NewCallback \
    <XgrpcProvider, const muduo::net::TcpConnectionPtr&, google::protobuf::Message*> \
    (this, &XgrpcProvider::SendRpcResponse, conn, response);

    // 在框架上根据远端rpc请求，调用当前rpc节点上发布的方法
    service->CallMethod(method, nullptr, request, response, done);
    /*
        注：
        protobuf会为每个service生成相应的ServiceRpc类
        在ServiceRpc类中会重写纯虚函数CallMethod
        服务端从m_serviceMap中取出相应的service对象
        调用CallMethod，根据多态的性质，会调用UserServiceRpc的CallMethod()方法
        进而调用CallMethod()参数中的method方法，request为请求参数，
        response为调用响应值，done为调用完成后的回调函数，
    */
}

// Closure的回调操作(done)，当服务器执行完本地方法后自动调用的回调函数
// 用于序列化rpc的响应和网络发送
// 将本地执行结果（响应），序列化，并发送给相应的对端
void XgrpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr& conn,
                                    google::protobuf::Message* response) {
    std::string response_str;
    if (response->SerializeToString(&response_str))
        conn->send(response_str);
    else {
        std::cout << "serialize response_str error!" << std::endl;
        std::cout << "response_str: " << response_str << std::endl;
    }
    conn->shutdown();  // 模拟http的短连接服务，由rpcprovider主动断开连接，给更多的rpc调用方提供服务
}
