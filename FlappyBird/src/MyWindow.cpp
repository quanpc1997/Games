#include "MyWindow.h"

MyWindow::MyWindow()
{
    int res = SDL_Init(SDL_INIT_EVERYTHING);
    if (res != 0)
        throw std::runtime_error(std::string("SDL_Init(SDL_INIT_EVERYTHING)")+SDL_GetError()) ;
    SDL_CreateWindowAndRenderer(Width, Height, SDL_WINDOW_SHOWN, &window, &renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

MyWindow::~MyWindow()
{
    //dtor
}

int MyWindow::exec()
{
    Display myDisplay(renderer);
    return myDisplay.controlExec();
}


