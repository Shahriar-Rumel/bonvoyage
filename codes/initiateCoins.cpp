#include "initiateCoins.h"

//funtion to load the coins of levelOne
void levelOneCoinsLoad(void)
{
    for (int i = 0; i < 5; i++)
    {
        window.surface = IMG_Load("images/levelone/coins-min.png");

        if (!window.surface)
        {
            printf("coins[i]Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelOneWindowCoins[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);
        if (!levelOneWindowCoins[i].tex)
        {
            printf("coins[i]  Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(levelOneWindowCoins[i].tex, NULL, NULL, &levelOneWindowCoins[i].rect.w, &levelOneWindowCoins[i].rect.h);
        levelOneWindowCoins[i].rect.w = (int)40;
        levelOneWindowCoins[i].rect.h = (int)40;
        levelOneWindowCoins[i].rect.x = (int)WINDOW_WIDTH + 100;
        levelOneWindowCoins[i].rect.y = (int)500;
    }
}
//funtion to cleanup the textures of the coins of LevelOne
void levelOneCoinsCleanUp()
{
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(levelOneWindowCoins[i].tex);
    }

    IMG_Quit();
}