#include "initiateLifeLoss.h"

//funtion to load life losing effect
void levelOneLifeLossLoad(void)
{

    for (int i = 0; i < 3; i++)
    {

        window.surface = IMG_Load("images/levelone/heartbreak.png");
        if (!window.surface)
        {
            printf("lifeloss[i] Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelOneLifeLoss[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);
        if (!levelOneWindowObstacle[i].tex)
        {
            printf("lifeloss[i]  Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(levelOneLifeLoss[i].tex, NULL, NULL, &levelOneLifeLoss[i].rect.w, &levelOneLifeLoss[i].rect.h);
        levelOneLifeLoss[i].rect.w = (int)0;
        levelOneLifeLoss[i].rect.h = (int)0;
        levelOneLifeLoss[i].rect.x = levelOneWindowObstacle[i].rect.x;
        levelOneLifeLoss[i].rect.y = (int)700;
    }
}

//funtion to destroy the texture of lifelosing
void levelOneLifeLossCleanUp()
{
    for (int i = 0; i < 3; i++)
    {
        SDL_DestroyTexture(levelOneLifeLoss[i].tex);
    }

    IMG_Quit();
}