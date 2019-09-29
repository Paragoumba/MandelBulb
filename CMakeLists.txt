cmake_minimum_required(VERSION 3.13)
project(MandelBulb)

add_subdirectory("${PROJECT_SOURCE_DIR}/prototypes/mandelbrot2d" "${PROJECT_SOURCE_DIR}/prototypes/mandelbrot2d/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/prototypes/vulkan" "${PROJECT_SOURCE_DIR}/prototypes/vulkan/cmake-build-debug")

add_executable(MandelBulb main.cpp)