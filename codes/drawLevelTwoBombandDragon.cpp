#include "drawLevelTwoBombandDragon.h"

void dragonflying()
{   
    //implementing the flying dragon and updating its motion 
    if ((levelTwoDragonPosition.rect.x + levelTwoDragonPosition.rect.w <= 0 && levelTwoBomb.rect.y > WINDOW_HEIGHT))
    {
        levelTwoDragonPosition.rect.x = WINDOW_WIDTH;
        levelTwoBomb.rect.y = 150;
        levelTwoBomb.rect.w = 0;
        levelTwoBomb.rect.h = 0;
        randomGenerator = levelTwoWindowCharacterPosition.rect.x;
    }
    else
    {
        levelTwoDragonPosition.rect.x -= 6;
    }
    if (abs(randomGenerator - levelTwoDragonPosition.rect.x) <= 10)
    {
        levelTwoBomb.rect.x = randomGenerator;
        levelTwoBomb.rect.y = 150;
        levelTwoBomb.rect.w = (int)40;
        levelTwoBomb.rect.h = (int)50;
    }
    if (levelTwoBomb.rect.x == randomGenerator)    // bomb falls when it possess the same x position as the character
    {
        levelTwoBomb.rect.y += 7;
    }
}
void drawBombandDragonFunction()
{
    dragonflying();
    SDL_RenderCopy(app.rend, levelTwoBomb.tex, NULL, &levelTwoBomb.rect);
    SDL_RenderCopy(app.rend, levelTwoDragon.tex, &levelTwoDragon.rect, &levelTwoDragonPosition.rect);
    SDL_RenderCopy(app.rend, levelTwoExplosion.tex, NULL, &levelTwoExplosion.rect);
}