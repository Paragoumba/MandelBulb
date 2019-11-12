//
// Created by paragoumba on 08/10/2019.
//

#ifndef MANDELBULB_MANDELBROT_HPP
#define MANDELBULB_MANDELBROT_HPP

#include <mutex>
#include <SDL2/SDL_render.h>

class MandelBrot {
public:
    static const int WIDTH = 1000;
    static const int HEIGHT = 1000;

    MandelBrot();

    void setupThread();
    void setupControls();

    void calculate();
    void display();
    void clear();
    void controls();
    void calculateImage_x();
    void calculateImage_y();

    ~MandelBrot();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Color grid[WIDTH][HEIGHT]{};
    bool running = true;
    int zoom = 100;
    int iteration_max = 100;
    float x1 = -2.1f;
    float x2 = 0.6f;
    float y1 = -1.2f;
    float y2 = 1.2f;
    float image_x{};
    float image_y{};
    SDL_Rect pixel{};
    std::mutex gridMutex;
};

#endif //MANDELBULB_MANDELBROT_HPP
