cmake_minimum_required(VERSION 4.0)

project(test)

set(root "/opt/MVS")

add_executable(hike main.cpp)

target_include_directories(hike PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${root}/include
)

target_link_directories(hike PRIVATE ${root}/lib/64)

target_link_libraries(hike PRIVATE MvCameraControl)