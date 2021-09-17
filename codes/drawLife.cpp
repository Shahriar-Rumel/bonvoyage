#include "drawLife.h"

//funtion to set the life sizes and rendering them
void levelOneDrawLifeFunction()
{

    for (int i = 0; i < lifeSize; i++)
    {
        levelOneWindowLife[i].rect.x = i * 40 + 1000;
        levelOneWindowLife[i].rect.y = 30;

        levelOneWindowLife[i].rect.h = 30;
        levelOneWindowLife[i].rect.w = 30;
        SDL_RenderCopy(app.rend, levelOneWindowLife[i].tex, NULL, &levelOneWindowLife[i].rect);
    }
}
