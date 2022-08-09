#pragma once

#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/Callbacks.h>
#include <muduo/net/EventLoop.h>

#include <string>
#include <unordered_map>

// 一个服务的有关信息
struct ServiceInfo {
    // 保存protobuf服务对象
    google::protobuf::Service* m_service;
    // 保存服务方法的哈希表: <方法名，方法信息>
    std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> m_methodMap;
};

// 框架提供的专门发布rpc服务的网络对象类
class XgrpcProvider {
  public:
    // Register an RPC service
    // 往本服务器的服务表中注册一个新的服务信息：{服务名称，服务信息}
    void NotifyService(google::protobuf::Service* service);

    // start RPC service
    // 开启RPC网络监听
    void Run();

  private:
    // muduo网络事件监听循环对象
    muduo::net::EventLoop m_eventLoop;

    // 存储注册成功的服务对象和其服务方法的所有信息的哈希表: <服务名，服务信息>
    std::unordered_map<std::string, ServiceInfo> m_serviceMap;

    // 发生新的TCP连接请求时调用的回调函数
    void OnConnection(const muduo::net::TcpConnectionPtr& conn);

    // 处理已有TCP连接的回调函数
    void OnMessage(const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buffer, muduo::Timestamp);

    // Closure的回调操作(done)，用于序列化rpc的响应和网络发送
    void SendRpcResponse(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message* response);
};
