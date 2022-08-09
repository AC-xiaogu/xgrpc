#include "config.h"

#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

void XgrpcConfig::LoadConfigFile(const std::string& config_filename) {
    // open configfile
    std::fstream cfgFile;
    cfgFile.open(config_filename, std::ios::in);  // read-only, auto close
    if (!cfgFile.is_open()) {
        std::cout << config_filename << " is not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // parse configfile
    while (!cfgFile.eof()) {  // 一行的读取并解析，直到读到EOF
        char lineBuf[512] = {0};
        cfgFile.getline(lineBuf, sizeof(lineBuf));

        // 去掉字符串前后多余的空格
        std::string lineStr(lineBuf);
        Trim(lineStr);

        // 忽略'#'开头的注释或空行
        if (lineStr[0] == '#' || lineStr.empty())
            continue;

        // 解析配置项 eg: "serverip = 127.0.0.1\n"
        std::size_t equalsSignPos = lineStr.find('=');  //找到=的下标
        if (equalsSignPos == std::string::npos)
            continue;  // 忽略不合法的配置行
        std::size_t endPos = lineStr.find('\n');

        std::string key, value;
        key = lineStr.substr(0, equalsSignPos);
        Trim(key);
        value = lineStr.substr(equalsSignPos + 1, endPos - equalsSignPos - 1);
        Trim(value);

        m_configMap.insert({key, value});
    }
    std::cout << "Load config file finished!"<< std::endl;
}

std::string XgrpcConfig::Load(const std::string& key) {
    auto it = m_configMap.find(key);
    if (it != m_configMap.end())
        return it->second;
    else
        return "";
}

// 去掉字符串前后的空格
void XgrpcConfig::Trim(std::string& str) {
    int idx = str.find_first_not_of(' ');
    if (idx != -1) {
        // 说明字符串前面有空格
        str = str.substr(idx, str.size() - idx);
    }
    idx = str.find_last_not_of(' ');
    if (idx != -1) {
        // 说明字符串后面有空格
        str = str.substr(0, idx + 1);
    }
}
