#include <iostream>

#include "Window.hpp"
#include "../EnginePack/Transformation.hpp"

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
    glClearColor(0.5f, 0.3f, 0.1f, 1.0f);

    glfwSetFramebufferSizeCallback(handle, [](GLFWwindow* _handle, int width, int height){

        Transformation::setProjectionMatrix(
                60,
                (float) width / (float) height,
                0.1f,
                100.0f
        );
    });

    Transformation::setProjectionMatrix(
            60,
            (float) width / (float) height,
            0.1f,
            100.0f
            );

}

void Window::swapBuffers(){

    glfwSwapBuffers(handle);

}

bool Window::shouldClose(){

    return glfwWindowShouldClose(handle);

}

int Window::getKey(int keyCode){

    return glfwGetKey(handle, keyCode);

}

void Window::close(){

    glfwSetWindowShouldClose(handle, true);

}

Window::~Window(){

    glfwTerminate();

}
