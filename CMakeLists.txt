cmake_minimum_required(VERSION 3.10)
project(PTUT)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${PROJECT_SOURCE_DIR}/src" "${PROJECT_SOURCE_DIR}/src/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/prototypes/mandelbrot2d" "${PROJECT_SOURCE_DIR}/prototypes/mandelbrot2d/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/prototypes/opengl" "${PROJECT_SOURCE_DIR}/prototypes/opengl/cmake-build-debug")
add_subdirectory("${PROJECT_SOURCE_DIR}/prototypes/translation" "${PROJECT_SOURCE_DIR}/prototypes/translation/cmake-build-debug")