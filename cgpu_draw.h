#ifndef CGPU_DRAW_H
#define CGPU_DRAW_H

#include <SDL.h>

class CGPU_DRAW
{
public:
    CGPU_DRAW();

    bool sdlInit();
    int createWindowAndRenderer(unsigned int, unsigned int, unsigned int, SDL_Window *&, SDL_Renderer *&);
    void clearScene(SDL_Renderer*);
    void setColorScene(SDL_Renderer*, unsigned char, unsigned char, unsigned char, unsigned char);

    void drawPoint(int, int, SDL_Renderer*, int);
    void drawSquare(int, int, int, int, SDL_Renderer*);
    void drawLine(int, int, int, int, SDL_Renderer*, int);
    void doRender(SDL_Renderer*);
};

#endif // CGPU_DRAW_H


