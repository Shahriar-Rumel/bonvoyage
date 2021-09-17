#include "initiateLife.h"

//funtion to load the lives of level one
void levelOneLifeLoad(void)
{
    for (int i = 0; i < 6; i++)
    {
        window.surface = IMG_Load("images/levelone/obstacles/redlife.png");

        if (!window.surface)
        {
            printf("life [i] Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelOneWindowLife[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);
        if (!levelOneWindowLife[i].tex)
        {
            printf("Life[i] Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(levelOneWindowLife[i].tex, NULL, NULL, &levelOneWindowLife[i].rect.w, &levelOneWindowLife[i].rect.h);
        levelOneWindowLife[i].rect.w = (int)56;
        levelOneWindowLife[i].rect.h = (int)40;
        levelOneWindowLife[i].rect.x = (int)600;
        levelOneWindowLife[i].rect.y = (int)500;
    }
}
//funtion to cleanup the textures of lives
void levelOneLifeCleanUp()
{
    for (int i = 0; i < 6; i++)
    {
        SDL_DestroyTexture(levelOneWindowLife[i].tex);
    }

    IMG_Quit();
}