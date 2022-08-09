cmake_minimum_required(VERSION 3.0)
project(xgrpc)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置项目可执行文件输出的路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 设置项目库输出路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) # shared libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) # static libraries

add_subdirectory(src)
# add_subdirectory(test)
add_subdirectory(example)
