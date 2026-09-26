file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) #搜索cmake之后所在路径CMakeLists.txt目录中src目录的cpp文件

add_executable(app ${src}) #生成可执行程序app

include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/lib/include) #指定头文件所在目录

link_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/build) #指定库文件路径

link_libraries(app calc) #链接动态库