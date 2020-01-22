#include "Application.hpp"

Application::Application(int _argc, char **_argv) : argc(_argc), argv(_argv) {}

//TODO: merge WindowOpenGL in the QApplication (QOpenGLWidget) to get one window (now: OpenGL Render + QT UI)
int Application::exec() {

    QApplication a(argc, argv);

    Window w;
    w.show();

    try {

        GameEngine gameEngine;

        gameEngine.loop();

    } catch (const std::exception& e){

        std::cerr << e.what() << std::endl;
        std::cerr << "Exiting due to a fatal unrecoverable error." << std::endl;

    } catch (...){

        std::cerr << "Exiting due to unknown fatal unrecoverable error." << std::endl;

    }

    return a.exec();

}

Application::~Application() {}