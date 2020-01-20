#include <iostream>
#include <stb/stb_image.h>

#include "Window.hpp"
#include "Transformation.hpp"

Window::Window(const char* title, int width, int height){

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

void Window::swapBuffers(){

    glfwSwapBuffers(handle);

}

bool Window::shouldClose() const {

    return glfwWindowShouldClose(handle);

}

int Window::getKey(int keyCode) const {

    return glfwGetKey(handle, keyCode);

}

Resolution Window::getSize() const {

    Resolution resolution{};

    glfwGetFramebufferSize(handle, &resolution.width, &resolution.height);

    return resolution;

}

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

void Window::close(){

    glfwSetWindowShouldClose(handle, true);

}

Window::~Window(){

    glfwTerminate();

}
