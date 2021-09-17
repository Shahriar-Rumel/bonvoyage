#include "initiateLevelTwoCoins.h"

void LevelTwoCoinsPopupLoad()
{
    window.surface = IMG_Load("images/level2obstacles/100.png");

    if (!window.surface)
    {
        printf("coinPointPopUp Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoCoinPointPopUp.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoCoinPointPopUp.tex)
    {
        printf("coinPointPopUp Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    
    SDL_QueryTexture(levelTwoCoinPointPopUp.tex, NULL, NULL, &levelTwoCoinPointPopUp.rect.w, &levelTwoCoinPointPopUp.rect.h);
    levelTwoCoinPointPopUp.rect.w = (int)0;
    levelTwoCoinPointPopUp.rect.h = (int)0;
    levelTwoCoinPointPopUp.rect.x = (int)WINDOW_WIDTH / 2;
    levelTwoCoinPointPopUp.rect.y = (int)WINDOW_HEIGHT / 2;
}

void LevelTwoCoinsload(void)
{
    for (int i = 0; i < 7; i++)
    {
        window.surface = IMG_Load("images/level2obstacles/finalcoins.png");

        if (!window.surface)
        {
            printf("levelTwoCoins Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelTwoWindowCoins[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);

        if (!levelTwoWindowCoins[i].tex)
        {
            printf("levelTwoCoins Texture Error: %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(levelTwoWindowCoins[i].tex, NULL, NULL, &levelTwoWindowCoins[i].rect.w, &levelTwoWindowCoins[i].rect.h);
        levelTwoWindowCoins[i].rect.w = (int)60;
        levelTwoWindowCoins[i].rect.h = (int)60;
        levelTwoWindowCoins[i].rect.x = (int)levelTwoTrack[0].rect.x + 150;
        levelTwoWindowCoins[i].rect.y = (int)levelTwoTrack[0].rect.y - 70;

        SDL_QueryTexture(levelTwoWindowCoins[i].tex, NULL, NULL, &levelTwoCoinTextureHeight, &levelTwoCoinTextureWidth);

        // variables for animating the rotatingCoins 
        levelTwoCoinFrameWidth = levelTwoCoinTextureWidth / 2;
        levelTwoCoinFrameHeight = levelTwoCoinTextureHeight / 2;

        levelTwoRotatingCoin.rect.w = (int)levelTwoCoinFrameWidth;
        levelTwoRotatingCoin.rect.h = (int)levelTwoCoinFrameHeight;
        levelTwoRotatingCoin.rect.x = (int)0;
        levelTwoRotatingCoin.rect.y = (int)0;
    }
    LevelTwoCoinsPopupLoad();
}

void LevelTwoCoinsCleanUp()
{
    for (int i = 0; i < 7; i++)
    {
        SDL_DestroyTexture(levelTwoWindowCoins[i].tex);
    }

    IMG_Quit();
}

void LevelTwoCoinsPopCleanUp()
{
    SDL_DestroyTexture(levelTwoCoinPointPopUp.tex);
    IMG_Quit();
}
