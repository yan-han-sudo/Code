cmake_minimum_required(VERSION 4.0)

project(test)

add_executable(hike 
    main.cpp
    camera.cpp
    )

target_include_directories(hike PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    /opt/MVS/include
    )

target_link_directories(hike PRIVATE /opt/MVS/lib/64)

target_link_libraries(hike PRIVATE MvCameraControl)