
#include "application.h"

#include <unistd.h>

#include <iostream>
#include <string>

#include "config.h"

// 全局配置类对象的（声明）
XgrpcConfig XgrpcApplication::m_config;

void XgrpcApplication::Init(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " -c configfile" << std::endl;
        exit(EXIT_FAILURE);
    }

    int opt = 0;
    std::string cfgFilename;
    while ((opt = getopt(argc, argv, "c:")) != -1) {
        switch (opt) {
            case 'c':
                cfgFilename = optarg;
                break;
            case '?':
                //出现了不希望出现的参数，我们指定必须出现i
                std::cout << "Usage: " << argv[0] << " -c configfile" << std::endl;
                exit(EXIT_FAILURE);
            case ':':
                //出现了-i,但是没有参数
                std::cout << "Usage: " << argv[0] << " -c configfile" << std::endl;
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }
    m_config.LoadConfigFile(cfgFilename);

    // test
    std::cout << "rpcserverip:" << m_config.Load("rpcserverip") << std::endl;
    std::cout << "rpcserverport:" << m_config.Load("rpcserverport") << std::endl;
    std::cout << "zookeeperip:" << m_config.Load("zookeeperip") << std::endl;
    std::cout << "zookeeperport:" << m_config.Load("zookeeperport") << std::endl;
}

XgrpcApplication& XgrpcApplication::GetInstance() {
    static XgrpcApplication app;
    return app;
}

XgrpcConfig& XgrpcApplication::GetConfig() {
    return m_config;
}
