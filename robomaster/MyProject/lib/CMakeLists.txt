file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) #搜索cmake之后所在路径CMakeLists.txt目录中src目录的cpp文件

add_library(calc SHARED ${src}) #生成动态库，本质是二进制源文件

target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) #指定头文件所在目录