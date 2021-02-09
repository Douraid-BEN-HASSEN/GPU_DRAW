#include "cgpu_draw.h"

CGPU_DRAW::CGPU_DRAW()
{

}

bool CGPU_DRAW::sdlInit()
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) return true;
    else return false;
}

int CGPU_DRAW::createWindowAndRenderer(unsigned int height, unsigned int width, unsigned int window_flags, SDL_Window *&window, SDL_Renderer *&renderer)
{
    return SDL_CreateWindowAndRenderer(height, width, window_flags, &window, &renderer);
}

void CGPU_DRAW::clearScene(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
}

void CGPU_DRAW::setColorScene(SDL_Renderer* renderer, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
    SDL_SetRenderDrawColor(renderer, R, G, B, A);
}

void CGPU_DRAW::drawPoint(int xPos, int yPos, SDL_Renderer* renderer, int taille)
{
    // On choisit la couleur [1]
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    // On positione le point [2]
    SDL_RenderDrawPoint(renderer, xPos, yPos);
    for(int cpt = 0; cpt < taille; cpt++)
    {
        SDL_RenderDrawPoint(renderer, xPos + cpt, yPos);
        SDL_RenderDrawPoint(renderer, xPos, yPos + cpt);
        SDL_RenderDrawPoint(renderer, xPos + taille, yPos + cpt);
        SDL_RenderDrawPoint(renderer, xPos + cpt, yPos + taille);
    }
}

void CGPU_DRAW::drawSquare(int xPos, int yPos, int height, int width, SDL_Renderer* renderer)
{
    for(int cpt = 0; cpt < width; cpt++)
    {
        drawPoint(xPos + cpt, yPos, renderer, 5);
        drawPoint(xPos + cpt, height + yPos, renderer, 5);
    }

    for(int cpt = 0; cpt < height; cpt++)
    {
        drawPoint(xPos, yPos + cpt, renderer, 5);
        drawPoint(width + xPos, yPos + cpt, renderer, 5);
    }
}

void CGPU_DRAW::drawLine(int xPosB, int yPosB, int xPosE, int yPosE, SDL_Renderer* renderer, int taille)
{
        int dx=xPosE-xPosB;
        int dy=yPosE-yPosB;
        int d=2*dy-dx;
        int incrE=2*dy;
        int incrNE=2*(dy-dx);
        int x=xPosB;
        int y=yPosB;

        drawPoint(x, y, renderer, taille);

        while(x<xPosE)
        {
            if(d<=0)
            {
                d+=incrE;
                x++;
            }
            else
            {
                d+=incrNE;
                x++;
                y++;
            }
            drawPoint(x, y, renderer, taille);
        }
}

void CGPU_DRAW::doRender(SDL_Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}
