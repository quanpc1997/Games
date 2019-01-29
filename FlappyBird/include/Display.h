#pragma once

#include <SDL_ttf.h>
#include <SDL.h>
#include "Bird.h"
#include "Background.h"
#include "Tube.h"
#include <vector>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "LoadTexture.h"
#include "Image.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Display
{
    public:
        int texW = 0;
        int texH = 0;
        int score = 0;
        //int hightScore;
        int xOfMouse;
        int yOfMouse;
        bool isUp = true;
        int heightBackground = 563;
        int widthBackground = 7356;

        Mix_Chunk* sfx_point;
        Mix_Chunk* sfx_hit;

        Display(SDL_Renderer* renderer);
        virtual ~Display();

        int exec();
        bool tick(bool isMouseDown);
        void displayScore(int score, string modeScore, int x, int y);
        int displayHightScore(int score);
        int controlExec();
        void drawScreen(Image &myImage1, Image &myImage2);

    protected:

    private:
        SDL_Renderer* renderer;
        SDL_Texture* tubeTexture;
        SDL_Texture* bgTexture;
        SDL_Texture* bgFirstTexture;
        SDL_Texture* playTexture;
        SDL_Texture* playAgainTexture;

        Bird myBird;
        std::vector<Tube> listTube;
        Image myBackground;
        int counter = 0;
        Image bgFirst;
        Image playButton;
        Image playAgainButton;

};


