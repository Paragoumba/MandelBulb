project(OpenGL)
add_executable(proto.OpenGL ../../lib/glad.c main.cpp Shader.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglfw -lGL -ldl")