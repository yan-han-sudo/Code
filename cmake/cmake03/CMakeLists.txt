cmake_minimum_required(VERSION 4.0)

project(test)

#set(src add.cpp sub.cpp main.cpp) #定义src变量存储项目源文件
#aux_source_directory(${PROJECT_SOURCE_DIR}/src src) #搜索项目根目录里CMakeLists.txt路径中src目录所有的源文件
file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp) #搜索cmake之后所在路径CMakeLists.txt目录中src目录的cpp文件

#set(EXECUTABLE_OUTPUT_PATH /home/yan-han/Code/a/b/c) #指定app生成的绝对路径

include_directories(${PROJECT_SOURCE_DIR}/include) #指定头文件所在目录

#set(CMAKE_CXX_STANDARD 11) #指定c++编译标准

#link_libraries(calc) #链接静态库 本质是链接源文件
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib1) #指定库文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib2) #指定库文件路径

add_executable(app ${src}) #生成可执行程序app

target_link_libraries(app calc) #链接动态库