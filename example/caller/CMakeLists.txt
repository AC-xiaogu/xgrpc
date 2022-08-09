find_package(Protobuf REQUIRED)

# -------------------------------
# 由于muduo的CMakeLists比较老旧，没有target的相关属性
# 故需要额外创建target并配置有关属性，后续即可
find_package(Threads)
# Stupid, does not support multi-thread compiling
if(NOT TARGET muduo::base)
  add_library(muduo::base UNKNOWN IMPORTED)
  set_target_properties(muduo::base PROPERTIES
    IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
    IMPORTED_LOCATION "/usr/local/lib/libmuduo_base.a"
    INTERFACE_INCLUDE_DIRECTORIES "/usr/local/include/muduo/base"
  )
endif()

if(NOT TARGET muduo::net)
  add_library(muduo::net UNKNOWN IMPORTED)
  set_target_properties(muduo::net PROPERTIES
    IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
    IMPORTED_LOCATION "/usr/local/lib/libmuduo_net.a"
    INTERFACE_INCLUDE_DIRECTORIES "/usr/local/include/muduo/net"
  )
endif()
# -------------------------------

add_executable(consumer
  calluserservice.cc
  ../user.pb.cc
  ../friendslist.pb.cc
)

target_include_directories(consumer
  PRIVATE ../
)

target_link_libraries(consumer
  PRIVATE protobuf::libprotobuf

  PUBLIC muduo::base
  PUBLIC muduo::net

  PRIVATE xgrpc::xgrpc
)
