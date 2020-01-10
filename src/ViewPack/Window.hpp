#ifndef PTUT_WINDOW_HPP
#define PTUT_WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* handle;

public:
    Window(const char* title, int width, int height);

    void swapBuffers();
    bool shouldClose();
    int getKey(int keyCode);
    void close();

    ~Window();
};

#endif //PTUT_WINDOW_HPP
