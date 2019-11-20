//
// Created by paragoumba on 08/10/2019.
//

#ifndef MANDELBULB_MANDELBROT_HPP
#define MANDELBULB_MANDELBROT_HPP

#include <mutex>
#include <SDL2/SDL_render.h>

class MandelBrot {
public:
    static const int WIDTH = 300;
    static const int HEIGHT = 300;

    MandelBrot();

    void setupThread();
    void setupControls();

    void calculate();
    void display();
    void clear();
    void controls();
    void calculateImage_x();
    void calculateImage_y();
	void coloring(int, SDL_Color&);

    ~MandelBrot();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Color grid[WIDTH][HEIGHT]{};
    bool running = true;
    int zoom = 100;
    int iteration_max = 64;
    float x1 = -2.1f;
    float x2 = 0.6f;
    float y1 = -1.2f;
    float y2 = 1.2f;
    float bias_x = 0.0f;
    float bias_y = 0.0f;
    float image_x{};
    float image_y{};
    SDL_Rect pixel{};
    std::mutex gridMutex;
};

#endif //MANDELBULB_MANDELBROT_HPP
