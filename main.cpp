#include <iostream>
#include <windows.h>
#include <SDL.h>

#include "cgpu_draw.h"

#ifdef __MINGW32__
#undef main
#endif

CGPU_DRAW GPU;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

unsigned int window_height = 640;
unsigned int window_width = 480;
unsigned int window_flags = 0;

int pointX = 300;
int pointY = 300;

void movePoint()
{
    if(GetAsyncKeyState(VK_UP)) pointY--;
    if(GetAsyncKeyState(VK_DOWN)) pointY++;

    if(GetAsyncKeyState(VK_RIGHT)) pointX++;
    if(GetAsyncKeyState(VK_LEFT)) pointX--;
    GPU.drawPoint(pointX, pointY, renderer, 1);
}

int main()
{
    if (GPU.sdlInit()) {
        if (GPU.createWindowAndRenderer(window_height, window_width, window_flags, window, renderer) == 0) {
            while (true) {
                GPU.setColorScene(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                GPU.clearScene(renderer);

                movePoint();

                GPU.drawSquare(125, 75, 50, 50, renderer);
                GPU.doRender(renderer);

                std::cout << "X = " << pointX << " \n" << "Y = " << pointY << "\n";
                system("cls");
            }

        }


        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }

    SDL_Quit();

    return 0;
}
