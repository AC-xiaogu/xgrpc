#include <iostream>
#include <string>
#include <vector>

#include "application.h"
#include "provider.h"
#include "user.pb.h"
#include "friendslist.pb.h"

class UserService : public user::UserServiceRpc {
  public:
    /* ------------ 服务器上的本地业务 ------------ */
    // 登录
    bool LocalLogin(std::string name, std::string pwd) {
        std::cout << "doing local service: Login" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "pwd: " << pwd << std::endl;
        return true;
    }

    // 注册
    bool LocalRegister(uint32_t id, std::string name, std::string pwd) {
        std::cout << "doing local service: Register" << std::endl;
        std::cout << "id: " << id << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "pwd: " << pwd << std::endl;
        return true;
    }
    /* --------------------------------------------- */

    /* 重写基类UserServiceRpc的虚函数，使得框架UserServiceRpc对象能够调用我们定义的方法 */
    void Login(google::protobuf::RpcController* controller,
               const ::user::LoginRequest* request,
               ::user::LoginResponse* response,
               ::google::protobuf::Closure* done) override {
        // 从request中取出Login所需参数
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 调用本地Login方法
        bool login_result = LocalLogin(name, pwd);

        /*
            message ResultCode
            {
                int32 errcode = 1;
                bytes errmsg = 2;
            }

            message LoginResponse
            {
                ResultCode result = 1;
                bool success = 2;
            }
        */
        // 根据user.proto协议，将LocalLogin调用结果写进LoginResponse对象中
        user::ResultCode* presult_code = response->mutable_result();
        presult_code->set_errcode(0);
        presult_code->set_errmsg("");
        response->set_success(login_result);

        // 执行done回调，返回rpc响应给客户端
        done->Run();
    }

    void Register(::google::protobuf::RpcController* controller,
                  const ::user::RegisterRequest* request,
                  ::user::RegisterResponse* response,
                  ::google::protobuf::Closure* done) override {
        // 从request中取出Register所需参数
        uint32_t id = request->id();
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 调用本地Register方法
        bool register_result = LocalRegister(id, name, pwd);

        user::ResultCode* presult_code = response->mutable_result();
        presult_code->set_errcode(0);
        presult_code->set_errmsg("");
        response->set_success(register_result);

        // 执行done回调，返回rpc响应给客户端
        done->Run();
    }
};

class FriendsService : public friends::FriendServiceRpc {
  public:
    /* ------------ 服务器上的本地业务 ------------ */
    // 获取好友列表
    std::vector<std::string> LocalGetFriendsList(uint32_t userid) {
        std::cout << "do GetFriendsList service! userid:" << userid << std::endl;
        return {"xiaogu", "minbao", "baobao"};
    }
    /* --------------------------------------------- */

    void GetFriendsList(::google::protobuf::RpcController* controller,
                        const ::friends::GetFriendsListRequest* request,
                        ::friends::GetFriendsListResponse* response,
                        ::google::protobuf::Closure* done) {
        // 从request中取出Register所需参数: userid
        uint32_t userid = request->userid();

        // 调用本地方法查询好友列表
        std::vector<std::string> friendslist = LocalGetFriendsList(userid);

        // 写回响应中
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        for (const std::string& friend_name : friendslist) {
            std::string* pfriend = response->add_friends();
            *pfriend = friend_name;
        }

        // 执行done回调，返回rpc响应给客户端
        done->Run();
    }
};

int main(int argc, char** argv) {
    // xgrpc框架的初始化
    XgrpcApplication::Init(argc, argv);

    // 定义一个rpc网络的服务对象
    XgrpcProvider provider;

    // 发布一个rpc服务
    provider.NotifyService(new UserService);
    provider.NotifyService(new FriendsService);

    // 启动rpc服务
    provider.Run();

    // Run以后，进程进入阻塞状态，等待远程的rpc调用请求

    return 0;
}
