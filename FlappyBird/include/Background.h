#pragma once


#include <SDL.h>
#include "LoadTexture.h"
#include "MyWindow.h"

class Background
{
    public:
        Background(SDL_Renderer* renderer);
        virtual ~Background();
        void drawBackground();

    protected:

    private:
        SDL_Renderer* renderer;
        SDL_Texture* background;
};
