cmake_minimum_required(VERSION 3.16)

project(MyProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build) #把可执行文件输出到构建目录里的build
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build) #把动态文件输出到构建目录里的build

add_subdirectory(lib) #执行lib里的 CMakeLists.txt
add_subdirectory(app) #执行app里的 CMakeLists.txt