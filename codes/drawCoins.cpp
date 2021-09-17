#include "drawCoins.h"

//funtion to determine the speeds of the coins
void coinsupdateanimation()
{
    //giving each coins different speeds
    levelOnePointAnimationSpeed[0] -= 8;
    if (levelOnePointAnimationSpeed[0] < -WINDOW_WIDTH + 100)
    {
        levelOnePointAnimationSpeed[0] = WINDOW_WIDTH + 100;

        levelOneWindowCoins[0].rect.h = 40;
        levelOneWindowCoins[0].rect.w = 40;
        //randomly setting the coin positions
        levelOneWindowCoins[0].rect.y = 630 - rand() % 500;
    }

    levelOnePointAnimationSpeed[1] -= 7;
    if (levelOnePointAnimationSpeed[1] < -WINDOW_WIDTH + 100)
    {
        levelOnePointAnimationSpeed[1] = WINDOW_WIDTH + 100;

        levelOneWindowCoins[1].rect.h = 40;
        levelOneWindowCoins[1].rect.w = 40;
        //randomly setting the coin positions
        levelOneWindowCoins[1].rect.y = 630 - rand() % 500;
    }

    levelOnePointAnimationSpeed[2] -= 6;
    if (levelOnePointAnimationSpeed[2] < -WINDOW_WIDTH + 100)
    {
        levelOnePointAnimationSpeed[2] = WINDOW_WIDTH + 100;

        levelOneWindowCoins[2].rect.h = 40;
        levelOneWindowCoins[2].rect.w = 40;
        //randomly setting the coin positions
        levelOneWindowCoins[2].rect.y = 630 - rand() % 500;
    }

    levelOnePointAnimationSpeed[3] -= 5;
    if (levelOnePointAnimationSpeed[3] < -WINDOW_WIDTH + 100)
    {
        levelOnePointAnimationSpeed[3] = WINDOW_WIDTH + 100;

        levelOneWindowCoins[3].rect.h = 40;
        levelOneWindowCoins[3].rect.w = 40;
        //randomly setting the coin positions
        levelOneWindowCoins[3].rect.y = 630 - rand() % 500;
    }

    levelOnePointAnimationSpeed[4] -= 4;
    if (levelOnePointAnimationSpeed[4] < -WINDOW_WIDTH + 100)
    {
        levelOnePointAnimationSpeed[4] = WINDOW_WIDTH + 100;

        levelOneWindowCoins[4].rect.h = 40;
        levelOneWindowCoins[4].rect.w = 40;
        //randomly setting the coin positions
        levelOneWindowCoins[4].rect.y = 630 - rand() % 500;
    }
}
//funtion to render the coins of levelOne
void drawCoinsFunction()
{
    coinsupdateanimation();
    for (int i = 0; i < 5; i++)
    {
        SDL_RenderCopy(app.rend, levelOneWindowCoins[i].tex, NULL, &levelOneWindowCoins[i].rect);
        levelOneWindowCoins[i].rect.x = levelOnePointAnimationSpeed[i];
        SDL_RenderCopy(app.rend, levelOneWindowCoins[i].tex, NULL, &levelOneWindowCoins[i].rect);
    }
}