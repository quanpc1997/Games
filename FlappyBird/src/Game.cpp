#include "Game.h"

Game::Game(SDL_Renderer* renderer):
    renderer(renderer),
    myBird(renderer)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

bool Game::tick(bool isMouseDown)
{
    return (myBird.y < MyWindow::Height) || (myBird.y > 0);
}

int Game::exec()
{
    Background myBackground(renderer);
    bool isMouseDown = false;
    int oldTick = SDL_GetTicks();
    for (bool done = false; !done;)
    {
        SDL_Event e;
        if(SDL_PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                    isMouseDown = true;
                    break;

                case SDL_MOUSEBUTTONUP:
                    isMouseDown = false;
                    break;

                case SDL_QUIT:
                    done =true;
                    break;
            }
        }

        int currentTick = SDL_GetTicks();
        for(int i = oldTick; i < currentTick; ++i)
        {
            if (tick(isMouseDown))
                myBird.moveBird(isMouseDown);
        }
        oldTick = currentTick;

        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(renderer);
        myBackground.drawBackground();
        myBird.drawBird();
        SDL_RenderPresent(renderer);
    }
    return 0;
}
