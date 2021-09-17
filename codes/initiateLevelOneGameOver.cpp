#include "initiateLevelOneGameOver.h"

//funtion to load GameOver message
void levelOneGameOverLoad(void)
{

    window.surface = IMG_Load("images/levelone/gameover.png");

    if (!window.surface)
    {
        printf("levelOneGameOverMessage Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelOneGameOverMessage.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelOneGameOverMessage.tex)
    {
        printf("levelOneGameOverMessage  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelOneGameOverMessage.tex, NULL, NULL, &levelOneGameOverMessage.rect.w, &levelOneGameOverMessage.rect.h);

    levelOneGameOverMessage.rect.w = (int)375;
    levelOneGameOverMessage.rect.h = (int)403;
    levelOneGameOverMessage.rect.x = (int)WINDOW_WIDTH / 2 - 187;
    levelOneGameOverMessage.rect.y = (int)WINDOW_HEIGHT / 2 - 201;
}
//function to destroy texture of gameover message
void levelOneGameOverCleanUp()
{

    SDL_DestroyTexture(levelOneGameOverMessage.tex);
    IMG_Quit();
}