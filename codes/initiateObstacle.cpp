#include "initiateObstacle.h"

//function to load obstacles of levelone
void levelOneObstacleLoad(void)
{
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            window.surface = IMG_Load("images/levelone/obstacles/rocktwin.png");
            if (!window.surface)
            {
                printf("Obstacle[i] Error: %s\n", IMG_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            levelOneWindowObstacle[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
            SDL_FreeSurface(window.surface);
            if (!levelOneWindowObstacle[i].tex)
            {
                printf("Obstacle[i] Texture %s\n", SDL_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            SDL_QueryTexture(levelOneWindowObstacle[i].tex, NULL, NULL, &levelOneWindowObstacle[i].rect.w, &levelOneWindowObstacle[i].rect.h);
            levelOneWindowObstacle[i].rect.w = (int)160;
            levelOneWindowObstacle[i].rect.h = (int)140;
            levelOneWindowObstacle[i].rect.x = (int)WINDOW_WIDTH + 100;
            levelOneWindowObstacle[i].rect.y = (int)700;
        }

        if (i == 1)
        {
            window.surface = IMG_Load("images/levelone/obstacles/bigrock.png");
            if (!window.surface)
            {
                printf("Obstacle[i] Error: %s\n", IMG_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            levelOneWindowObstacle[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
            SDL_FreeSurface(window.surface);
            if (!levelOneWindowObstacle[i].tex)
            {
                printf("Obstacle[i]_  Texture %s\n", SDL_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            SDL_QueryTexture(levelOneWindowObstacle[i].tex, NULL, NULL, &levelOneWindowObstacle[i].rect.w, &levelOneWindowObstacle[i].rect.h);
            levelOneWindowObstacle[i].rect.w = (int)224;
            levelOneWindowObstacle[i].rect.h = (int)136;
            levelOneWindowObstacle[i].rect.x = (int)WINDOW_WIDTH + 100;
            levelOneWindowObstacle[i].rect.y = (int)700;
        }

        if (i == 2)
        {
            window.surface = IMG_Load("images/levelone/obstacles/pumpkin.png");
            if (!window.surface)
            {
                printf("Obstacle[i] Error: %s\n", IMG_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            levelOneWindowObstacle[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
            SDL_FreeSurface(window.surface);
            if (!levelOneWindowObstacle[i].tex)
            {
                printf("Obstacle[i]  Texture %s\n", SDL_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            SDL_QueryTexture(levelOneWindowObstacle[i].tex, NULL, NULL, &levelOneWindowObstacle[i].rect.w, &levelOneWindowObstacle[i].rect.h);
            levelOneWindowObstacle[i].rect.w = (int)102;
            levelOneWindowObstacle[i].rect.h = (int)93;
            levelOneWindowObstacle[i].rect.x = (int)WINDOW_WIDTH * 3;
            levelOneWindowObstacle[i].rect.y = (int)700;
        }
    }
}

//funtion to destroy the textures of obstacles
void levelOneObstacleCleanUp()
{
    for (int i = 0; i < 3; i++)
    {
        SDL_DestroyTexture(levelOneWindowObstacle[i].tex);
    }
}