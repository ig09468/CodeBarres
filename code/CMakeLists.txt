cmake_minimum_required(VERSION 3.13)
project(CodeBarres)

set(OpenCV_INCLUDE_DIR /usr/local/include/opencv4/opencv2)

find_package(OpenCV REQUIRED)


set(CMAKE_CXX_STANDARD 14)

add_executable(CodeBarres main.cpp PreProcess.cpp PreProcess.h)


include_directories(${OpenCV_INCLUDE_DIR})
target_link_libraries(CodeBarres ${OpenCV_LIBS})