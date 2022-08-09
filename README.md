# XiaoGu-RPC
在provider.cc中：
```C++
service->CallMethod(method, nullptr, request, response, done);
```
这个`CallMethod`根据多态其实是调用我们服务端相应的ServiceRpc中重写的`CallMethod`函数（protobuf帮我们自动生成了，比如在`user.pb.cc`中重写了）。

在这个重写的`CallMethod`函数中，会`switch(method)`，调用相应的RPC方法，并传入相应的参数。

调用这个RPC方法，根据多态，其实也是调用我们自己重写实现的RPC方法(如Login)。

在我们重写的RPC方法中，会进行request参数解析，调用相应的本地方法，并将本地方法的结果，写回response中，然后调用`done->Run()`

文档中提到：`"done" will be called when the method is complete.`
这个done其实是一开始在`service->CallMethod`中传入的回调函数，用于RPC方法执行完毕后，需要回复响应给对端。done是一个`google::protobuf::Closure`类型的对象
在框架中，我们为done设置了回调函数`XgrpcProvider::SendRpcResponse`，调用`done->Run()`其实会内部调用我们定义好的回调`XgrpcProvider::SendRpcResponse`，在`SendRpcResponse`中我们实现了**回复响应**的功能！至此，服务端一次RPC服务完成。
