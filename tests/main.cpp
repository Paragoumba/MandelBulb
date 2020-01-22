#include <gtest/gtest.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "../src/engine/Transformation.hpp"
#include "../src/engine/WindowOpenGL.hpp"
#include "../src/engine/exceptions/WindowException.hpp"

bool operator==(glm::mat4 mat1, glm::mat4 mat2){

    bool flag = true;

    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){

            if (mat1[i][j] != mat2[i][j]){

                flag = false;

            }
        }
    }

    return flag;

}

std::ostream& operator<<(std::ostream& o, glm::mat4 mat){

    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){

            o << mat[i][j] << (j != 3 ? ", " : "");

        }

        std::cout << std::endl;

    }

    return o;

}

TEST(MandelBulb, TransformationTest){

    std::cout << "- Testing Transformation::getViewMatrix -" << std::endl;

    Camera camera;

    glm::mat4 correctViewMatrix(1);
    glm::mat4 viewMatrix = Transformation::getViewMatrix(camera);

    ASSERT_TRUE(viewMatrix == correctViewMatrix);

    std::cout << "- Testing Transformation::getModelMatrix -" << std::endl;

    Object model;
    glm::mat4 correctModelMatrix(1);
    glm::mat4 modelMatrix = Transformation::getModelMatrix(&model);

    ASSERT_TRUE(modelMatrix == correctModelMatrix);

    std::cout << "- Testing Transformation::setProjectionMatrix -" << std::endl;

    glm::mat4 correctPerspectiveMatrix(1);
    Transformation::setProjectionMatrix(60, 1920.0f / 1080, -1, 100);

}

TEST(MandelBulb, WindowTest){

    std::cout << "- Testing WindowOpenGL constructor -" << std::endl;

    try {

        WindowOpenGL window(nullptr, 1920, 1080);

        FAIL() << "WindowOpenGL should return an exception when title is null.";

    } catch (WindowException& e){}

}