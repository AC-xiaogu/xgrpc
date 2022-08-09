#include <iostream>

#include "application.h"
#include "channel.h"
#include "controller.h"
#include "friendslist.pb.h"
#include "user.pb.h"

int main(int argc, char **argv) {
    // Xgrp框架初始化
    XgrpcApplication::Init(argc, argv);

    user::UserServiceRpc_Stub userStub(new XgrpcChannel());

    // ---------------------------------------------------------------------------------------------------
    // 登录和注册同属于【用户服务】：user service
    // login
    user::LoginRequest loginRequest;
    loginRequest.set_name("gucheng");
    loginRequest.set_pwd("123456");

    user::LoginResponse loginResponse;
    userStub.Login(nullptr, &loginRequest, &loginResponse, nullptr);

    if (0 == loginResponse.result().errcode())
        std::cout << "rpc login response success:" << loginResponse.success() << std::endl;
    else
        std::cout << "rpc login response error : " << loginResponse.result().errmsg() << std::endl;

    // register
    user::RegisterRequest registerRequest;
    registerRequest.set_id(1806909741);
    registerRequest.set_name("minbao");
    registerRequest.set_pwd("233333");

    user::RegisterResponse registerResponse;

    userStub.Register(nullptr, &registerRequest, &registerResponse, nullptr);

    if (0 == registerResponse.result().errcode())
        std::cout << "rpc register response success:" << registerResponse.success() << std::endl;
    else
        std::cout << "rpc register response error : " << registerResponse.result().errmsg() << std::endl;

    // ---------------------------------------------------------------------------------------------------
    // get friends list
    // 由于获取好友列表属于【好友管理rpc服务】，故需要使用不同的stub
    friends::FriendServiceRpc_Stub friendStub(new XgrpcChannel());

    friends::GetFriendsListRequest getFriendsListRequest;
    getFriendsListRequest.set_userid(19980505);

    friends::GetFriendsListResponse getFriendsListResponse;
    XgrpcController controller;

    friendStub.GetFriendsList(&controller, &getFriendsListRequest, &getFriendsListResponse, nullptr);

    if (controller.Failed()) {
        std::cout << controller.ErrorText() << std::endl;
    } else {
        if (0 == getFriendsListResponse.result().errcode()) {
            std::cout << "rpc GetFriendsList response success!" << std::endl;
            int size = getFriendsListResponse.friends_size();  //获取好友的个数
            for (int i = 0; i < size; ++i)                     //变量，打印
            {
                std::cout << "index:" << (i + 1) << " name:" << getFriendsListResponse.friends(i) << std::endl;
            }
        } else {
            std::cout << "rpc GetFriendsList response error : " << getFriendsListResponse.result().errmsg() << std::endl;
        }
    }

    return 0;
}
