#include <gtest/gtest.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "../src/engine/Transformation.hpp"
#include "../src/engine/Window.hpp"
#include "../src/engine/exceptions/WindowException.hpp"
#include "../src/engine/Utils.hpp"

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

TEST(Utils, setExePath){

    const char* p = "/test1/test2";

    Utils::setExePath(p);

    ASSERT_TRUE(strcmp(p, Utils::getExePath().c_str()) == 0);

}

TEST(Utils, getPath){

    Utils::setExePath("/root/bin/exe");

    ASSERT_TRUE(strcmp("/root/bin/res/tex.png", Utils::getPath("res/tex.png").c_str()) == 0);

}

// TODO Fix that test. Window's constructor can't access OpenGL
/*TEST(Window, setCursor){

    Window* window;

    try {

        window = new Window("test", 1, 1);

    } catch (WindowException& e){

        try {

            window->setCursor("");

            FAIL() << "Calling setCursor on Window with an invalid path should throw a WindowException.";

        } catch (...){}

    }
}*/
