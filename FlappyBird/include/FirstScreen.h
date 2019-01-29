#pragma once

#include <SDL.h>
#include "LoadTexture.h"
#include "Image.h"

class FirstScreen
{
    public:
        FirstScreen(SDL_Renderer* renderer);
        virtual ~FirstScreen();
        void drawScreen();

    protected:

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        Image myBackground;
        Image plButton;
        Image clButton;
};
