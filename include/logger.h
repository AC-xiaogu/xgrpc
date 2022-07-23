#pragma once
#include <string>

#include "lockqueue.h"

/*
    定义宏 LOG_INFO("xxx %d %s", 20, "xxxx")
    可变参，提供给用户更轻松的使用logger
    snprintf， 缓冲区，缓冲区的长度，写的格式化字符串， ##__VA_ARGS__。
        ##__VA_ARGS__含义：
        ##表示连接它左右两端的操作符变成一个操作符
        只有一个参数时，只使用__VA_ARGS__会报错，报错的原因是后面多加了一个逗号
        当使用 ##__VA_ARGS 时，当一端没有符号时可以不做连接处理，
        同时去除逗号，以保证程序可以编译执行。
    代表了可变参的参数列表，填到缓冲区当中，然后 logger.Log(c)

    do while(0)结构可防止宏函数在编译展开时编译出错
    参考：https://www.zhihu.com/question/24386599/answer/1297723714
*/
#define LOG_INFO(logmsgformat, ...)                     \
    do {                                                \
        Logger &logger = Logger::GetInstance();         \
        logger.SetLogLevel(INFO);                       \
        char c[1024] = {0};                             \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c);                                  \
    } while (0)

#define LOG_ERR(logmsgformat, ...)                      \
    do {                                                \
        Logger &logger = Logger::GetInstance();         \
        logger.SetLogLevel(ERROR);                      \
        char c[1024] = {0};                             \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c);                                  \
    } while (0)

enum LogLevel {
    INFO,
    ERROR,
};

class Logger {
  public:
    static Logger &GetInstance();
    void SetLogLevel(LogLevel level);
    void Log(std::string msg);

  private:
    int m_loglevel;
    LockQueue<std::string> m_lckQue;

    // Singleton
    Logger();
    Logger(const Logger &) = delete;
    Logger(Logger &&) = delete;
};
