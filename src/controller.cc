#include "controller.h"

#include <google/protobuf/service.h>
#include <google/protobuf/stubs/callback.h>

#include <string>

XgrpcController::XgrpcController() {
    m_failed = false;
    m_errorText = "";
}

void XgrpcController::Reset() {
    m_failed = false;
    m_errorText = "";
}

bool XgrpcController::Failed() const {
    return m_failed;
}

std::string XgrpcController::ErrorText() const {
    return m_errorText;
}

void XgrpcController::SetFailed(const std::string& reason) {
    std::cout << "SetFailed begin" << std::endl;
    m_failed = true;
    m_errorText = reason;
    std::cout << "SetFailed return" << std::endl;
}

// 不需要，空实现即可
void XgrpcController::StartCancel() {}
bool XgrpcController::IsCanceled() const { return false; }
void XgrpcController::NotifyOnCancel(google::protobuf::Closure* callback) {}
