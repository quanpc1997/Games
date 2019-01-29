#include "Bird.h"

Bird::Bird(SDL_Renderer* renderer):
    renderer(renderer),
    bird1(loadPNGTexture(renderer, "images/bird1.png")),
    bird2(loadPNGTexture(renderer, "images/bird2.png"))
{
    //ctor
}

Bird::~Bird()
{
    SDL_DestroyTexture(bird1);
    SDL_DestroyTexture(bird2);
}

void Bird::drawBird()
{
    SDL_Rect birdRect;
    birdRect.x = x;
    birdRect.y = y;
    birdRect.h = 50;
    birdRect.w = 50;
    int res = SDL_RenderCopyEx(renderer, SDL_GetTicks() % 300 > 150 ? bird1 : bird2, nullptr, &birdRect, v*50, nullptr, SDL_FLIP_NONE);
    if (res !=0)
        throw std::runtime_error(std::string(" SDL_RenderCopyEx Bird ") + SDL_GetError());
}

void Bird::moveBird(bool isMouseDown)
{
    v -= isMouseDown ? 0.003 : 0;
    v += 0.001;
    y += v;
}
