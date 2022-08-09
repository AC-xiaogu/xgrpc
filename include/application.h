#pragma once
#include "config.h"

// xgrpc框架的基础类，负责框架的一些初始化操作
class XgrpcApplication {
  public:
    static void Init(int argc, char** argv);  // 初始化
    static XgrpcApplication& GetInstance();   // 单例模式
    static XgrpcConfig& GetConfig();

  private:
    static XgrpcConfig m_config;                         // 全局配置类对象
    XgrpcApplication() {}                                // 构造函数
    XgrpcApplication(const XgrpcApplication&) = delete;  // 禁用拷贝构造函数
    XgrpcApplication(XgrpcApplication&&) = delete;       // 禁用移动构造函数
};
