#include "Tube.h"

Tube::Tube(SDL_Renderer* renderer, SDL_Texture *texture, int y, bool isUp):
    renderer(renderer),
    texture(texture),
    isUp(isUp),
    y(y)
{
    //ctor
}

Tube::~Tube()
{
}

void Tube::drawTube()
{
    if(!isUp)
    {
        SDL_Rect rectTube;
        rectTube.x = x;
        rectTube.y = 0;
        rectTube.h = y;
        rectTube.w = 65;
        int res = SDL_RenderCopyEx(renderer, texture, nullptr, &rectTube, 0, nullptr, SDL_FLIP_NONE);
        if (res != 0)
            throw std::runtime_error(std::string(" SDL_RenderCopyEx Tube ") + SDL_GetError());
    }
    else
    {
        SDL_Rect rectTube;
        rectTube.x = x;
        rectTube.y = y + 150;
        rectTube.h = 563 - y - 150;
        rectTube.w = 65;
        int res = SDL_RenderCopyEx(renderer, texture, nullptr, &rectTube, 0, nullptr, SDL_FLIP_VERTICAL);
        if (res != 0)
            throw std::runtime_error(std::string(" SDL_RenderCopyEx Tube ") + SDL_GetError());
    }
}

void Tube::moveTube()
{
    x-=0.25;
}

