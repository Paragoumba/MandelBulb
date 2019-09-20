cmake_minimum_required(VERSION 3.13)
project(MandelBulb)

set(CMAKE_CXX_STANDARD 17)

add_executable(MandelBulb main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2")