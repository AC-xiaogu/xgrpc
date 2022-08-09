#pragma once

#include <google/protobuf/service.h>
#include <google/protobuf/stubs/callback.h>

#include <string>

// 继承自虚基类RpcController，必须重写重现其所有的成员函数
class XgrpcController : public google::protobuf::RpcController {
  public:
    XgrpcController();
    void Reset() override;
    bool Failed() const override;
    std::string ErrorText() const override;
    void SetFailed(const std::string& reason) override;

    // 不需要，空实现即可
    void StartCancel() override;
    bool IsCanceled() const override;
    void NotifyOnCancel(google::protobuf::Closure* callback) override;

  private:
    bool m_failed;            // RPC执行过程中的状态
    std::string m_errorText;  // RPC方法执行过程中的错误信息
};
