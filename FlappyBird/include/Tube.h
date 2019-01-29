#pragma once

#include <SDL.h>
#include <vector>
#include <stdexcept>
#include "LoadTexture.h"

class Tube
{
    public:
        float x = 1000;
        Tube(SDL_Renderer* renderer, SDL_Texture *texture, int y, bool isUp);
        virtual ~Tube();
        void drawTube();
        void moveTube();


    protected:

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        bool isUp;

    public:
        float y;
};

