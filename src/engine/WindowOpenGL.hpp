#ifndef PTUT_WINDOWOPENGL_HPP
#define PTUT_WINDOWOPENGL_HPP

#include <iostream>

//#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <QtWidgets/QOpenGLWidget>

#include "Transformation.hpp"

struct Resolution {
    int width;
    int height;
};

class WindowOpenGL : public QOpenGLWidget {
private:
    GLFWwindow* handle;

public:
    explicit WindowOpenGL(QWidget* parent);
    WindowOpenGL(const char* title, int width, int height, QWidget* parent = nullptr);

    void swapBuffers();
    [[nodiscard]] bool shouldClose() const;
    [[nodiscard]] int getKey(int keyCode) const;
    [[nodiscard]] Resolution getSize() const;
    void setCursor(const char* path);
    void setTitle(const char* title);
    void close();

    ~WindowOpenGL();

};

#endif //PTUT_WINDOWOPENGL_HPP
