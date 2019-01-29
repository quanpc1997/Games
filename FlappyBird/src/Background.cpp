#include "Background.h"

Background::Background(SDL_Renderer* renderer):
    renderer(renderer),
    background(loadTexture(renderer, "images/bg.bmp"))
{
    //ctor
}

Background::~Background()
{
    //dtor
}

void Background::drawBackground()
{
    SDL_Rect rectBG;
    rectBG.x = 0;
    rectBG.y = 0;
    rectBG.h = MyWindow::Height;
    rectBG.w = MyWindow::Width;
    int res = SDL_RenderCopy(renderer,background,nullptr, &rectBG);
    if (res !=0)
        throw std::runtime_error(std::string("Background.cpp: SDL_RenderCopy ") + SDL_GetError());
}
