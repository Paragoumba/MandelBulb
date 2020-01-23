#include <gtest/gtest.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "../src/engine/Transformation.hpp"
#include "../src/engine/Window.hpp"
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

TEST(Transformation, getViewMatrix){

    Camera camera;

    glm::mat4 correctViewMatrix(1);
    glm::mat4 viewMatrix = Transformation::getViewMatrix(camera);

    ASSERT_TRUE(viewMatrix == correctViewMatrix);

}

TEST(Transformation, getModelMatrix){

    Object model;
    glm::mat4 correctModelMatrix(1);
    glm::mat4 modelMatrix = Transformation::getModelMatrix(&model);

    ASSERT_TRUE(modelMatrix == correctModelMatrix);

}

TEST(Transformation, setProjectionMatrix){

    glm::mat4 correctPerspectiveMatrix(0);

    correctPerspectiveMatrix[0][0] = -0.0878174752;
    correctPerspectiveMatrix[1][1] = -0.156119958;
    correctPerspectiveMatrix[2][2] = -1.02020204;
    correctPerspectiveMatrix[2][3] = -1;
    correctPerspectiveMatrix[3][2] = -2.02020192;

    Transformation::setProjectionMatrix(60, 1920.0f / 1080, 1, 100);

    glm::mat4 projectionMatrix = Transformation::getProjectionMatrix();

    ASSERT_TRUE(projectionMatrix == correctPerspectiveMatrix);

}