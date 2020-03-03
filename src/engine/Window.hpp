#ifndef PTUT_WINDOW_HPP
#define PTUT_WINDOW_HPP
/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 *  Program to manafe the window of the program
 *
 */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
/**
 * \struct Resolution
 * Define one resolution
 */
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

/**
 * \class Window
 * Class to manage window of the program
 */
class Window {
private:
    GLFWwindow* handle;
    Color color{0, 0, 0, 0};

public:
    /**
     *  Constructor the class Window
     *
     * @param title, name of the window
     * @param width, the width of the window
     * @param height, the height of the window
     */
    Window(const char* title, int width, int height);
    /**
     * Swap the buffers
     */
    void swapBuffers();
    /**
     * ??
     * @return
     */
    [[nodiscard]] bool shouldClose() const;
    /**
     * give the key by the keyCode
     * @param keyCode
     * @return
     */
    [[nodiscard]] int getKey(int keyCode) const;
    /**
     *  give the resolution of this window
     *
     * @return the resolution
     */
    [[nodiscard]] Resolution getSize() const;

    [[nodiscard]] Color getColor() const;
    /**
     *  define the cursor of this windows
     *
     * @param path name of cursor's file
     */
    GLFWwindow* getHandle() const;
    void setCursor(const char* path);
    /**
    * define the title of this window
    *
    * @param title, the string
     */
    void setTitle(const char* title);

    void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
    * close this window
    */
    void close();

    int takeScreenshot(const char*);

    /**
     *  Destructor of the class window
    */
    ~Window();
};

#endif //PTUT_WINDOW_HPP
