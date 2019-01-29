#include "Display.h"

#include "MyWindow.h"

Display::Display(SDL_Renderer* renderer):
    renderer(renderer),
    tubeTexture(loadPNGTexture(renderer, "images/tube.png")),
    bgTexture(loadPNGTexture(renderer, "images/background.png")),
    bgFirstTexture(loadPNGTexture(renderer, "images/bgfirst.png")),
    playTexture(loadPNGTexture(renderer, "images/play_button.png")),
    playAgainTexture(loadPNGTexture(renderer, "images/play_again_button.png")),

    myBird(renderer),
    myBackground(renderer, bgTexture, 0, 0, heightBackground, widthBackground),
    bgFirst(renderer, bgFirstTexture, 0, 0, MyWindow::Height, MyWindow::Width),
    playButton(renderer, playTexture, 400, 300, 50, 200),
    playAgainButton(renderer,playAgainTexture, 400, 300, 50, 200)
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        throw std::runtime_error(std::string("ERROR: Mix_OpenAudio()") + TTF_GetError());

    sfx_point = Mix_LoadWAV("sounds/sfx_point.wav");
    sfx_hit = Mix_LoadWAV("sounds/sfx_hit.wav");
    if (sfx_hit == NULL || sfx_point == NULL)
        throw std::runtime_error(std::string("ERROR: Can't load Audio") + TTF_GetError());
}

Display::~Display()
{
    //dtor
}
// Dieu kien chet cua chim
bool Display::tick(bool isMouseDown)
{
    bool life = true;
    if(counter++ % 1200 == 0)
    {
        float y = rand()%230 + 70;
        listTube.emplace_back(renderer, tubeTexture, y, false);
        listTube.emplace_back(renderer, tubeTexture, y, true);
    }
    myBird.moveBird(isMouseDown);
    myBackground.moveImage();
    for(int i = 0; i < listTube.size(); i++)
    {
        listTube.at(i).moveTube();
        if (listTube.at(i).x <= 100 && listTube.at(i).x >= -15)
        {
            if (myBird.y > listTube.at(i).y && myBird.y < listTube.at(i).y + 100)
            {
                life = true;
            }
            else
            {
                life = false;
            }
        }
        if(life == true && listTube.at(i).x == -15)
        {
            Mix_PlayChannel(-1, sfx_point, 0);
            score++;
            displayScore(score, "Score: ", 0, 0);
            displayScore(displayHightScore(score), "Hight Score: ", 0, 30);
        }
        if (life == false)
        {
            Mix_PlayChannel(-1, sfx_hit, 0);
        }
        if(listTube.at(i).x <= -65)
        {
            listTube.erase(listTube.begin(), listTube.begin()+1);
        }

    }
    return ((myBird.y < 550) && (myBird.y > 0) && life);
}
//Hoat dong trong game
int Display::exec()
{
    bool isMouseDown = false;
    int oldTick = SDL_GetTicks();
    bool done = false;
    while(!done)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
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
            if(!tick(isMouseDown))
            {
                SDL_Delay(500);
                myBird.x = 50;
                myBird.y = 300;
                score = 0;
                listTube.clear();
                isUp = false;
                while(isUp == false)
                {
                    SDL_QUIT;
                    SDL_DestroyTexture(playTexture);
                    drawScreen(bgFirst,playAgainButton);
                }

                return 1;
            }
        }
        oldTick = currentTick;
        myBackground.drawImage();
        myBird.drawBird();
        for(int i = 0; i < listTube.size(); i++)
            listTube.at(i).drawTube();
        displayScore(score, "Score: ", 0, 0);
        displayScore(displayHightScore(score), "Hight Score: ", 0, 30);
        SDL_RenderPresent(renderer);
    }
    return 0;
}
//Tinh diem va hien thi diem
void Display::displayScore(int score, string modeScore, int x, int y)
{
    if(TTF_Init() == -1)
        throw std::runtime_error(string("ERROR: TTF_Init()") + TTF_GetError());
    TTF_Font* font = TTF_OpenFont("SegoeUI.ttf", 10);
    if(!font)
        throw std::runtime_error(string("Error TTF_Font: ") + TTF_GetError());
    SDL_Color myColor = {255, 255, 255};
    std::string result = modeScore + to_string(score/2);
    SDL_Surface* surface = TTF_RenderText_Solid(font, result.c_str(), myColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = { x, y, 150, 40};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    SDL_RenderPresent(renderer);
    TTF_CloseFont(font);
}
//Quan Li man hinh
int Display::controlExec()
{
    drawScreen(bgFirst,playButton);
}
//Hien thi cac loai man hinh
void Display::drawScreen(Image &myBackground, Image &myButton)
{
    myBackground.drawImage();
    myButton.drawImage();
    SDL_RenderPresent(renderer);
    bool done = false;
    while(!done)
    {
        SDL_Event e;
        if(SDL_PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                {
                    SDL_PumpEvents();
                    SDL_GetMouseState(&xOfMouse, &yOfMouse);
                    if(xOfMouse>=400 && xOfMouse<=600 && yOfMouse>=300 && yOfMouse<=350)
                    {
                        exec();
                    }
                    break;
                }
                case SDL_QUIT:
                    done =true;
                    SDL_Quit();
                    break;
            }
        }
    }
}
//Đọc ghi file để tính điểm
int Display::displayHightScore(int score)
{
    int newScore = score/2;
    fstream f;
	f.open("score/HightScore.txt");
	string data;
	getline(f, data);
	stringstream toInt(data);
	int myScore;
	toInt >> myScore;
	f.close();
	f.open("score/HightScore.txt");
	if(myScore <= newScore)
	{
        myScore = newScore;
        f << myScore;
    }
    //ghi file diem
    f.close();
    return myScore*2;
}



