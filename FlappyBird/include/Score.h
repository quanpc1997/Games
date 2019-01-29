#ifndef SCORE_H
#define SCORE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdexcept>

class Score
{
    public:
        Score();
        virtual ~Score();
        int score = 0;
    protected:

    private:
        SDL_Renderer *renderer;
};

#endif // SCORE_H
