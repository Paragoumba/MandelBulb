#ifndef PTUT_APPLICATION_HPP
#define PTUT_APPLICATION_HPP

#include <QtWidgets/QApplication>

#include "Window.hpp"
#include "../engine/GameEngine.hpp"

class Application {
private:
    int argc;
    char **argv;

public:
    Application(int, char**);

    int exec();

    ~Application();

};

#endif //PTUT_APPLICATION_HPP