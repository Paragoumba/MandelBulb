/**
 * \file Window.cpp
 * \brief Program to manage window.
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program to manage the window of the program
 *
 */

#include <iostream>
#include <stb/stb_image.h>
#include "Window.hpp"
#include "Transformation.hpp"

/**
 * \fn Window(const char* title, int width, int height)
 * \brief Constructor the class Window
 *
 * @param title, name of the window
 * @param width, the width of the window
 * @param height, the height of the window
 */

Window::Window(const char* title, int width, int height){

    if (title == nullptr){

        title = "";

    }

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    handle = glfwCreateWindow(width, height, title, nullptr, nullptr);

    glfwMakeContextCurrent(handle);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){

        glfwTerminate();

        std::cerr << "Failed to initialize GLAD." << std::endl;
        exit(1);

    }

    glViewport(0, 0, width, height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetFramebufferSizeCallback(handle, [](GLFWwindow* _handle, int newWidth, int newHeight){

        Transformation::setProjectionMatrix(
                glm::radians(60.0f),
                (float) newWidth / (float) newHeight,
                0.1f,
                100.0f
        );
    });

    Transformation::setProjectionMatrix(
            glm::radians(60.0f),
            (float) width / (float) height,
            0.1f,
            100.0f
            );

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    setCursor("../res/imgs/cursor.png");

}


/**
 * \fn void swapBuffers(void)
 * \brief complete
 *
 *
 */
void Window::swapBuffers(){

    glfwSwapBuffers(handle);

}

/**
 * \fn bool shouldClose(void)
 * \brief complete
 *
 *
 * @return glfwWindowShouldClose
 */
bool Window::shouldClose() const {

    return glfwWindowShouldClose(handle);

}

/**
 * \fn int getKey(int keyCode) const
 * \brief give the key by the keyCode
 *
 * @param keyCode
 * @return the key
 */
int Window::getKey(int keyCode) const {

    return glfwGetKey(handle, keyCode);

}

/**
 * \fn Resolution getSize(void) const
 * \brief give the resolution of this window
 *
 * @return the resolution
 */
Resolution Window::getSize() const {

    Resolution resolution{};

    glfwGetFramebufferSize(handle, &resolution.width, &resolution.height);

    return resolution;

}

Color Window::getColor() const {

    return color;

}

/**
 * \fn void setCursor(const char* path)
 * \brief define the cursor of this windows
 *
 * @param path name of cursor's file
 */
void Window::setCursor(const char* path){

    stbi_set_flip_vertically_on_load(false);

    GLFWimage cursorImage;

    cursorImage.pixels = stbi_load(path, &cursorImage.width, &cursorImage.height, nullptr, 0);

    GLFWcursor* cursor = glfwCreateCursor(&cursorImage, 0, 0);

    stbi_image_free(cursorImage.pixels);

    if (cursor != nullptr){

        glfwSetCursor(handle, cursor);

    } else {

        std::cerr << "Could not create cursor from image located at " << path << '.' << std::endl;

    }
}

/**
 * \fn void setTitle(const char* title)
 * \brief define the title of this window
 *
 *
 * @param title, the string
 */
void Window::setTitle(const char* title){

    glfwSetWindowTitle(handle, title);

}

void Window::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a){

    glClearColor(r, g, b, a);

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;

}

/**
 * \fn void close(void)
 * \brief close this window
 *
 */
void Window::close(){

    glfwSetWindowShouldClose(handle, true);

}

/**
 * \fn ~Window(void)
 * \brief Destructor of the class window
 */
Window::~Window(){

    glfwTerminate();

}
