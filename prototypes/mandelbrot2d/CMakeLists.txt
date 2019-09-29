cmake_minimum_required(VERSION 3.13)
project(MandelBrot2D)

set(CMAKE_CXX_STANDARD 17)

add_executable(MandelBrot2D main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2")