//
// Created by paragoumba on 08/10/2019.
//

#include <SDL2/SDL_events.h>
#include <thread>
#include <cmath>
#include <string>
#include <SDL2/SDL.h>

#include "MandelBrot.hpp"

MandelBrot::MandelBrot(){

    window = SDL_CreateWindow("MandelBrot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MandelBrot::WIDTH, MandelBrot::HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetWindowResizable(window, SDL_TRUE);

    pixel.w = pixel.h = 1;

    clear();

    calculateImage_x();
    calculateImage_y();

}

void MandelBrot::setupThread(){

    std::thread nouveauThread(&MandelBrot::calculate, this);
    nouveauThread.detach();

}

void MandelBrot::setupControls() {

    std::thread controlThread(&MandelBrot::controls, this);

    controlThread.detach();

}

void MandelBrot::calculate(){

    while (running){

        for (int x = 0; (float) x < image_x && x < WIDTH; ++x) {
            for (int y = 0; (float) y < image_y && y < HEIGHT; ++y) {

                float c_r = (float) x / (float) zoom + x1 + bias_x;
                float c_i = (float) y / (float) zoom + y1 + bias_y;

                float z_r = 0;
                float z_i = 0;

                int i = 0;

                do {

                    float tmp = z_r;

                    z_r = z_r * z_r - z_i * z_i + c_r;
                    z_i = 2 * z_i * tmp + c_i;
                    i++;

                } while (z_r * z_r + z_i * z_i < 4 && i < iteration_max);

                gridMutex.lock();
					
				/*
				grid[x][y].r = (int)((i>=10)?255:(255/2)*(1-cos(M_PI*i/10)));
				grid[x][y].g = (int)((i<=10)?0:(255/2)*(1+cos(M_PI*i/10)));
				grid[x][y].b = (int)((i<=5)?0:((i>=15)?255:(255/2)*(1-sin(M_PI*i/10))));
				*/
				/*
				grid[x][y].r = (int)(255 / 1 + exp(-(i - MandelBrot::iteration_max / 4) / sqrt(MandelBrot::iteration_max)));
				grid[x][y].g = (int)(255 / 1 + exp(-(i - MandelBrot::iteration_max / 2) / sqrt(MandelBrot::iteration_max)));
				grid[x][y].b = (int)(255 / 1 + exp(-(i - 3*MandelBrot::iteration_max / 4) / sqrt(MandelBrot::iteration_max)));
				*/
					

				coloring(i, grid[x][y]);
					

				gridMutex.unlock();

            }
        }
    }
}

void MandelBrot::display(){

    int i = 0;
    long start = SDL_GetTicks();

    while (running){

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //clear();
        SDL_RenderClear(renderer);

        gridMutex.lock();

        for (int x = 0; x < WIDTH; ++x) {
            for (int y = 0; y < HEIGHT; ++y) {

                pixel.x = x;
                pixel.y = y;
                SDL_SetRenderDrawColor(renderer, grid[x][y].r, grid[x][y].g, grid[x][y].b, grid[x][y].a);
                SDL_RenderFillRect(renderer, &pixel);

            }
        }

        gridMutex.unlock();

        SDL_RenderPresent(renderer);

        ++i;

        long time = SDL_GetTicks();

        if (time - start > 1000){

            start = time;
            SDL_SetWindowTitle(window, ("MandelBrot - " + std::to_string(i) + "FPS").c_str());
            i = 0;

        }
    }
}

void MandelBrot::clear(){

    for (auto& i : grid) {
        for (auto& j : i) {

            j.r = 0;
            j.g = 0;
            j.b = 0;
            j.a = 255;

        }
    }
}

void MandelBrot::controls(){

    SDL_Event event;

    while (running){

        while (SDL_PollEvent(&event)){

            switch (event.type){

                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {

                        running = false;

                    } else if (event.key.keysym.sym == SDLK_UP){

                        zoom += 10;
                        calculateImage_x();
                        calculateImage_y();

                    } else if (event.key.keysym.sym == SDLK_DOWN){

                        zoom -= 10;
                        calculateImage_x();
                        calculateImage_y();

                    } else if (event.key.keysym.sym == SDLK_a){

		            	bias_x += 0.1;
		            	calculateImage_x();
                        calculateImage_y();

		            } else if (event.key.keysym.sym == SDLK_q){

		            	bias_x -= 0.1;
		            	calculateImage_x();
                        calculateImage_y();

		            } else if (event.key.keysym.sym == SDLK_z){

			            bias_y += 0.1;
			            calculateImage_x();
                        calculateImage_y();

		            } else if (event.key.keysym.sym == SDLK_s){

			            bias_y -= 0.1;
			            calculateImage_x();
                        calculateImage_y();

		            }

                    break;

                default:
                    break;

            }
        }
    }
}

void MandelBrot::calculateImage_x(){

    image_x = (x2 - x1) * (float) zoom;

}

void MandelBrot::calculateImage_y(){

    image_y = (y2 - y1) * (float) zoom;

}

MandelBrot::~MandelBrot(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void MandelBrot::coloring(int m, SDL_Color& out) {
	int value;
	if (m >= MandelBrot::iteration_max) {
		m = MandelBrot::iteration_max;
		value = 0;
	}
	else
		value = 1;

	double hue = (int)(360 * m / MandelBrot::iteration_max), r = 0, g = 0, b = 0;

	int i;
	double f, p, q, t;

	if (hue == 360)
		hue = 0;
	else
		hue = hue / 60;

	i = (int)(hue);
	f = hue - i;

	p = 0;
	q = value * (1.0 - f);
	t = value * f;

	switch (i) {
	case 0:
		r = value;
		g = t;
		b = p;
		break;
	case 1:
		r = q;
		g = value;
		b = p;
		break;
	case 2:
		r = p;
		g = value;
		b = t;
		break;
	case 3:
		r = p;
		g = q;
		b = t;
		break;
	case 4:
		r = t;
		g = p;
		b = value;
		break;
	default:
		r = value;
		g = p;
		b = q;
		break;
	}

	out.a = 255;
	out.b = b * 255;
	out.g = g * 255;
	out.r = r * 255;
}