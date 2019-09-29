//
// Created by Paragoumba on 4/19/19.
//

#include <cstdlib>
#include <SDL2/SDL.h>
#include <iostream>

int main(){

    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow("MandelBrot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_SHOWN);
    auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    SDL_Rect pixel;

    pixel.w = pixel.h = 1;

    float x1 = -2.1;
    float x2 = 0.6;
    float y1 = -1.2;
    float y2 = 1.2;

    int zoom = 100;
    int iteration_max = 50;

    float image_x = (x2 - x1) * (float) zoom;
    float image_y = (y2 - y1) * (float) zoom;

    bool running = true;

    SDL_Event event;

    while (running) {

        while (SDL_PollEvent(&event)) {

            switch (event.type) {

                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_ESCAPE){

                        running = false;

                    }

                    break;

                default:
                    break;

            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for (int x = 0; (float) x < image_x; ++x) {
            for (int y = 0; (float) y < image_y; ++y) {

                float c_r = (float) x / (float) zoom + x1;
                float c_i = (float) y / (float) zoom + y1;

                float z_r = 0;
                float z_i = 0;

                int i = 0;

                do {

                    float tmp = z_r;

                    z_r = z_r * z_r - z_i * z_i + c_r;
                    z_i = 2 * z_i * tmp + c_i;
                    i++;

                } while (z_r * z_r + z_i * z_i < 4 && i < iteration_max);

                if (i == iteration_max) {

                    pixel.x = x;
                    pixel.y = y;

                    SDL_RenderFillRect(renderer, &pixel);

                }
            }
        }
        
        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}