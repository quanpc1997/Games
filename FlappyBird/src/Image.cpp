#include "Image.h"

Image::Image(SDL_Renderer* renderer, SDL_Texture *texture, float x, float y, float height, float width):
    renderer(renderer),
    texture(texture),
    x(x),
    y(y),
    height(height),
    width(width)
{
    //ctor
}

Image::~Image()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
}

void Image::drawImage()
{
    SDL_Rect rectBG;
    rectBG.x = x;
    rectBG.y = y;
    rectBG.h = height;
    rectBG.w = width;
    int res = SDL_RenderCopy(renderer, texture, nullptr, &rectBG);
    if (res !=0)
        throw std::runtime_error(std::string("Background.cpp: SDL_RenderCopy ") + SDL_GetError());
}

void Image::moveImage()
{
    x-=0.01;
    if(x == -widthBackground)
        x = 0;
}
