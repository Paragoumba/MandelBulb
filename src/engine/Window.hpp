#ifndef PTUT_WINDOW_HPP
#define PTUT_WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct Resolution {
    int width;
    int height;
};

class Window {
private:
    GLFWwindow* handle;

public:
    Window(const char* title, int width, int height);

    void swapBuffers();
    [[nodiscard]] bool shouldClose() const;
    [[nodiscard]] int getKey(int keyCode) const;
    [[nodiscard]] Resolution getSize() const;
    void setCursor(const char* path);
    void close();

    ~Window();
};

#endif //PTUT_WINDOW_HPP
