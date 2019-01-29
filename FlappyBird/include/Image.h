#pragma once

#include <SDL.h>
#include <vector>
#include <stdexcept>
#include "LoadTexture.h"

class Image
{
    public:
        int heightBackground = 563;
        int widthBackground = 7356;

        Image(SDL_Renderer* renderer, SDL_Texture *texture, float x, float y, float height, float width);
        virtual ~Image();
        void drawImage();
        void moveImage();

    protected:

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        float x;
        float y;
        float height;
        float width;
};

