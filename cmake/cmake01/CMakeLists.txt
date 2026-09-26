cmake_minimum_required(VERSION 4.0)

project(test)

#set(src add.cpp sub.cpp main.cpp) #定义src变量存储项目源文件
#aux_source_directory(${PROJECT_SOURCE_DIR}/src src) #搜索项目根目录里CMakeLists.txt路径中src目录所有的源文件
file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) #搜索cmake之后所在路径CMakeLists.txt目录中src目录的cpp文件

#set(EXECUTABLE_OUTPUT_PATH /home/yan-han/Code/a/b/c) #指定app生成的绝对路径

include_directories(${PROJECT_SOURCE_DIR}/include) #指定头文件所在目录

#set(CMAKE_CXX_STANDARD 11) #指定c++编译标准

#add_executable(app ${src}) #生成可执行程序app
set(LIBRARY_OUTPUT_PATH /home/yan-han/Code/abcd) #指定库文件生成路径
add_library(calc SHARED ${src}) #生成动态库，本质是二进制源文件
#add_library(calc STATIC ${src}) #生成静态库