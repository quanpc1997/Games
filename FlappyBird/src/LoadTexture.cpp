#include "LoadTexture.h"
#include <stdexcept>
#include <string>
#include <SDL_image.h>

SDL_Texture * loadPNGTexture(SDL_Renderer *renderer, const char *fileName)
{
    SDL_Texture* texture = IMG_LoadTexture( renderer, fileName);
    if (!texture)
    {
        throw std::runtime_error(std::string("IMG_LoadTexture(") + fileName + "): " + SDL_GetError());
    }
    return texture;
}

