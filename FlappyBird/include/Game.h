#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "Bird.h"
#include "Background.h"
#include "MyWindow.h"

class Game
{
    public:
        Game(SDL_Renderer* renderer);
        virtual ~Game();
        int exec();
        bool tick(bool isMouseDown);

    protected:

    private:
        SDL_Renderer* renderer;
        Bird myBird;
};

#endif // GAME_H
