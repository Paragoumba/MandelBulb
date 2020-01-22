add_executable(Tests main.cpp ../lib/glad.c ../src/engine/Camera.cpp ../src/engine/Transformation.cpp
        ../src/engine/Object.cpp ../src/engine/WindowOpenGL.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest -lgtest_main -lglfw -ldl -lGL")