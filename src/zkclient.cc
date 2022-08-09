#include "zkclient.h"

#include <semaphore.h>
#include <zookeeper/zookeeper.h>

#include <iostream>
#include <string>

#include "application.h"

ZkClient::ZkClient() : m_zhandle(nullptr) {}

ZkClient::~ZkClient() {
    if (m_zhandle != nullptr)
        zookeeper_close(m_zhandle);
}

// 启动客户端，连接zkserver
void ZkClient::Start() {
    // 获取zookeeper配置信息
    std::string zkip = XgrpcApplication::GetConfig().Load("zookeeperip");
    std::string zkport = XgrpcApplication::GetConfig().Load("zookeeperport");
    std::string host_str = zkip + ':' + zkport;

    /*
        注：
        zookeeper_mt：多线程版本
        zookeeper的API客户端程序提供了三个线程：
        API调用线程 也就是当前线程 也就是调用的线程 zookeeper_init
        网络I/O线程  zookeeper_init调用了pthread_create  poll专门连接网络
        watcher回调线程 当客户端接收到zkserver的响应，再次调用pthread_create，产生watcher回调线程
        */
    //返回的就是句柄，会话的创建是【异步】的
    // 并不是返回成功了就是表示连接成功的，等回调函数真正接收到zkserver响应进行回调
    // recv_timeout 为客户端所期望的session超时时间，单位为毫秒，下面设为30000ms，即30s
    m_zhandle = zookeeper_init(host_str.c_str(), ZkClient::WatcherFunc, 30000, nullptr, nullptr, 0);
    if (nullptr == m_zhandle) {
        std::cout << "zookeeper_init error!" << std::endl;
        exit(EXIT_FAILURE);
    }

    sem_t sem;  // 定义一个用于等待zkserver响应的信号量
    sem_init(&sem, 0, 0);
    zoo_set_context(m_zhandle, &sem);  // 向句柄资源上设置上下文，添加额外的信息
    sem_wait(&sem);                    // 阻塞等待zkserver的响应（等sem>0的信号）

    std::cout << "zookeeper_init success!" << std::endl;
}

// 在zkserver上根据指定的path创建znode节点
void ZkClient::Create(const char* path, const char* value, int valuelen, int flags) {
    int code;
    code = zoo_exists(m_zhandle, path, 0, nullptr);
    if (ZNONODE == code) {
        // 没有，则创建
        code = zoo_create(m_zhandle, path, value, valuelen,
                          &ZOO_OPEN_ACL_UNSAFE, flags, nullptr, 0);
        if (ZOK == code) {
            std::cout << "znode create success... path: " << path << std::endl;
        } else {
            std::cout << "znode create error... path: " << path << std::endl;
            std::cout << "zoo_create() returned: " << code << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

// 根据指定的path，获取znode节点的值
std::string ZkClient::GetValue(const char* path) {
    char buffer[128];
    int bufferlen = sizeof(buffer);
    int retcode = zoo_get(m_zhandle, path, 0, buffer, &bufferlen, nullptr);
    if (retcode != ZOK) {
        std::cout << "znode get error... path: " << path << std::endl;
        std::cout << "zoo_get() returned: " << retcode << std::endl;
        return "";
    } else
        return buffer;
}

void ZkClient::WatcherFunc(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx) {
    if (type == ZOO_SESSION_EVENT && state == ZOO_CONNECTED_STATE) {
        // sem_t *sem = (sem_t*)zoo_get_context(zh);    // C风格强制类型转换

        // const void* --> const sem_t* --> sem_t*
        sem_t* sem = const_cast<sem_t*>(static_cast<const sem_t*>(zoo_get_context(zh)));
        sem_post(sem);  // 信号量资源sem++
    }
}
