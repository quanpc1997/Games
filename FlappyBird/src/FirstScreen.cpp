#include "FirstScreen.h"

FirstScreen::FirstScreen(SDL_Renderer* renderer):
    renderer(renderer),
    texture(texture),
    myBackground(renderer, "images/bg-first.bmp"),
    plButton(renderer, "images/play_button.bmp"),
    clButton(renderer, "images/close_button.bmp")
{

}

FirstScreen::~FirstScreen()
{

}

void FirstScreen::drawScreen()
{

}
