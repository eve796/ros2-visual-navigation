cmake_minimum_required(VERSION 3.16)

project(ros2_visual_navigation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(image_loader 
    src/image_loader.cpp
    src/image_processor.cpp
    )

target_include_directories(image_loader PRIVATE include)

target_link_libraries(image_loader ${OpenCV_LIBS})