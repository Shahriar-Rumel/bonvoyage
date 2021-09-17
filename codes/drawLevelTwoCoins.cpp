#include "drawLevelTwoCoins.h"
 
void drawLevelTwoCoinsPopupFunction()
{
    SDL_RenderCopy(app.rend, levelTwoCoinPointPopUp.tex, 0, &levelTwoCoinPointPopUp.rect);
}

void updateCoinsPosition()
{
    for(int i=0; i<5; i++)
    {
        levelTwoWindowCoins[i].rect.w = (int)60;
        levelTwoWindowCoins[i].rect.h = (int)60;
    }
    
    //adjusting tracks position and keeping it into the frame  
    if (levelTwoTrack[0].rect.y < WINDOW_HEIGHT / 2 || levelTwoTrack[0].rect.y >= WINDOW_HEIGHT - 400)
    {
        levelTwoTrack[0].rect.y = WINDOW_HEIGHT / 2 + rand() % 100;
    }
    
    //updating coins position with respect to tracks 
    levelTwoWindowCoins[0].rect.y = levelTwoTrack[0].rect.y - 70 - rand() % 200;
    levelTwoWindowCoins[1].rect.y = levelTwoTrack[0].rect.y - 70 - rand() % 200;

    if (levelTwoWindowCoins[0].rect.y < levelTwoTrack[0].rect.y && levelTwoWindowCoins[0].rect.y > levelTwoTrack[0].rect.y - 120)
    {
        levelTwoWindowCoins[0].rect.y = WINDOW_WIDTH + 300;
    }
    levelTwoWindowCoins[2].rect.y = 200;
    levelTwoWindowCoins[3].rect.y = levelTwoWindowCoins[2].rect.y + 200;
    levelTwoWindowCoins[4].rect.y = levelTwoWindowCoins[3].rect.y + 300;
}
void updateCoinsPosition2()
{

    levelTwoWindowCoins[5].rect.w = (int)60;
    levelTwoWindowCoins[5].rect.h = (int)60;
    levelTwoWindowCoins[6].rect.w = (int)60;
    levelTwoWindowCoins[6].rect.h = (int)60;
    levelTwoWindowCoins[5].rect.y = levelTwoTrack[1].rect.y - 70 - rand() % 200;
    levelTwoWindowCoins[6].rect.y = levelTwoTrack[1].rect.y - 70 - rand() % 200;

    if (levelTwoWindowCoins[5].rect.y < levelTwoTrack[1].rect.y && levelTwoWindowCoins[5].rect.y > levelTwoTrack[1].rect.y - 120)
    {
        levelTwoWindowCoins[5].rect.y = WINDOW_WIDTH + 300;
    }
}
void drawLevelTwoCoinsFunction()
{
    for (int i = 0; i < 7; i++)
    {
        SDL_RenderCopy(app.rend, levelTwoWindowCoins[i].tex, &levelTwoRotatingCoin.rect, &levelTwoWindowCoins[i].rect);
    }
}