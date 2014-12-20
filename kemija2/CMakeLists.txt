cmake_minimum_required(VERSION 2.8.4)
project(kemija2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(kemija2 ${SOURCE_FILES})