#pragma once

#include <zookeeper/zookeeper.h>
#include <string>

class ZkClient {
  public:
    ZkClient();
    ~ZkClient();

    // 启动客户端，连接zkserver
    void Start();
    // 在zkserver上根据指定的path创建znode节点
    void Create(const char* path, const char* value, int valuelen, int flags = 0);
    // 根据指定的path，获取znode节点的值
    std::string GetValue(const char* path);

    // zookeeper_init的watcher_fn回调函数
    static void WatcherFunc(zhandle_t *zh, int type, int state, const char *path,void *watcherCtx);

  private:
    // zk的客户端句柄(标识), 通过这个句柄可以去操作zkserver
    zhandle_t *m_zhandle;
};
