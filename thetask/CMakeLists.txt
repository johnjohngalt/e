cmake_minimum_required(VERSION 3.0)

project(TASK) 

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(include)


add_executable(project main.cpp Detector.cpp)

target_link_libraries(project ${OpenCV_LIBS})

