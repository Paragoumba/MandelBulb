/**
 * \author R.VIOLLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
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
#include "exceptions/WindowException.hpp"
#include "Utils.hpp"

/**
 *  Constructor the class Window
 *
 * @param title, name of the window
 * @param width, the width of the window
 * @param height, the height of the window
 */

Window::Window(const char* title, int width, int height){

    if (title == nullptr){

        std::cerr << "Argument title is null in Window constructor." << std::endl;
        std::cerr << "Using default value (\"\") instead." << std::endl;
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

        throw WindowException("Failed to initialize GLAD.");

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

        glViewport(0, 0, newWidth, newHeight);

    });

    Transformation::setProjectionMatrix(
            glm::radians(60.0f),
            (float) width / (float) height,
            0.1f,
            100.0f
            );

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    setCursor(Utils::getPath("../res/imgs/cursor.png").c_str());

}


/**
 *  swap the buffers
 */
void Window::swapBuffers(){

    glfwSwapBuffers(handle);

}

/**
 *  complete
 *
 * @return glfwWindowShouldClose
 */
bool Window::shouldClose() const {

    return glfwWindowShouldClose(handle);

}

/**
 *  give the key by the keyCode
 *
 * @param keyCode
 * @return the key
 */
int Window::getKey(int keyCode) const {

    return glfwGetKey(handle, keyCode);

}

/**
 *  give the resolution of this window
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

GLFWwindow* Window::getHandle() const {

    return this->handle;

}

/**
 *  define the cursor of this windows
 *
 * @param path name of cursor's file
 */
void Window::setCursor(const char* path){

    stbi_set_flip_vertically_on_load(false);

    GLFWimage cursorImage;

    cursorImage.pixels = stbi_load(path, &cursorImage.width, &cursorImage.height, nullptr, 0);

    if (cursorImage.pixels == nullptr){

        throw WindowException(
                (std::string("Could not create cursor from image located at ") + path + '.').c_str());

    }

    GLFWcursor* cursor = glfwCreateCursor(&cursorImage, 0, 0);

    glfwSetCursor(handle, cursor);
    stbi_image_free(cursorImage.pixels);

}

/**
 * define the title of this window
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
 *  close this window
 *
 */
void Window::close(){

    glfwSetWindowShouldClose(handle, true);

}

/**
 *  Destructor of the class window
 *
 */
Window::~Window(){

    glfwTerminate();

}