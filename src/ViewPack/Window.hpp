#ifndef PTUT_WINDOW_HPP
#define PTUT_WINDOW_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../engine/Transformation.hpp"

class Window {
private:
    GLFWwindow* handle;

public:
    Window(const char* title, int width, int height);

    void swapBuffers();
    bool shouldClose();
    [[nodiscard]] int getKey(int keyCode) const;
    void close();

    ~Window();
};

#endif //PTUT_WINDOW_HPP
