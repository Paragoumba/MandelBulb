project(MandelBrot2D)
add_executable(proto.MandelBrot2D main.cpp MandelBrot.cpp MandelBrot.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2 -pthread")