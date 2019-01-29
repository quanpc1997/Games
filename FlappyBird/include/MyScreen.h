#ifndef MYGAME_H
#define MYGAME_H

#include <SDL.h>
#include <string>
#include <stdexcept>
#include <SDL_image.h>
#include "Bird.h"
#include <stdio.h>

class MyWindow
{
    public:
        static const int Width = 900;
        static const int Height = 500;

        MyWindow();
        virtual ~MyWindow();
        int exec();
    protected:

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif // MYGAME_H
