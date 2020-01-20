add_executable(proto.Translation main.cpp TranslationManager.cpp TranslationManager.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lyaml-cpp")