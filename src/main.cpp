#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "engine/GameEngine.hpp"
#include "ModelPack/Data.hpp"
#include "ModelPack/DataManager.hpp"
#include "ViewPack/Application.hpp"

int main(int argc, char **argv){

    Application app(argc, argv);

    return app.exec();

}