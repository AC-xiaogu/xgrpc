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

# add_custom_command(
#   OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/rpcheader.pb.cc"
#          "${CMAKE_CURRENT_SOURCE_DIR}/rpcheader.pb.h"
#   DEPENDS protobuf::protoc "./rpcheader.proto"
#   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#   COMMAND ${CMAKE_BINARY_DIR}/output/protoc -I=. --cpp_out=. rpcheader.proto
#   COMMENT "Running C++ protocol buffer compiler on rpcheader.proto"
#   VERBATIM
# )

add_library(xgrpc
  application.cc 
  config.cc 
  rpcheader.pb.cc 
  provider.cc 
  channel.cc
  controller.cc   
  logger.cc
  zkclient.cc
)

target_include_directories(xgrpc
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(xgrpc
  PRIVATE protobuf::libprotobuf
  PUBLIC muduo::base
  PUBLIC muduo::net
  PRIVATE Threads::Threads
  PRIVATE zookeeper_mt
)

add_library(xgrpc::xgrpc ALIAS xgrpc)
