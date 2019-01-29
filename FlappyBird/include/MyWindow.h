#pragma once

#include <SDL.h>
#include <string>
#include <stdexcept>
#include <SDL_image.h>
#include <stdio.h>
#include "Bird.h"
#include "Display.h"

class MyWindow
{
    public:
        static const int Width = 1000;
        static const int Height = 563;

        MyWindow();
        MyWindow(SDL_Renderer* renderer);
        virtual ~MyWindow();
        int exec();

    protected:

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};

