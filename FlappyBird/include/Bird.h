#pragma once

#include <SDL.h>
#include <stdexcept>
#include "LoadTexture.h"

class Bird
{
    public:
        const float X_LOCATION = 50;
        const float Y_LOCATION = 230;
        float x = X_LOCATION;
        float y = Y_LOCATION;

    public:
        Bird(SDL_Renderer* renderer);
        virtual ~Bird();
        void drawBird();
        void moveBird(bool isMouseDown);

    protected:

    private:
        SDL_Renderer* renderer;
        SDL_Texture* bird1;
        SDL_Texture* bird2;
        float v=0.0f;

};

