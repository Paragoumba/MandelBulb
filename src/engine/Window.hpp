#ifndef PTUT_WINDOW_HPP
#define PTUT_WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct Resolution {
    int width;
    int height;
};

struct Color {
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
};

class Window {
private:
    GLFWwindow* handle;
    Color color{0, 0, 0, 0};

public:
    Window(const char* title, int width, int height);

    void swapBuffers();
    [[nodiscard]] bool shouldClose() const;
    [[nodiscard]] int getKey(int keyCode) const;
    [[nodiscard]] Resolution getSize() const;
    [[nodiscard]] Color getColor() const;
    void setCursor(const char* path);
    void setTitle(const char* title);
    void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void close();

    ~Window();
};

#endif //PTUT_WINDOW_HPP
