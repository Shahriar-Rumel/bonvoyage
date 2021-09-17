#include "initiateLevelOneCompleted.h"

//funtion to load levelOne completed message
void levelOneCompletedLoad(void)
{
    // overlay load

    window.surface = IMG_Load("images/levelone/overlay-min.png");

    if (!window.surface)
    {
        printf("levelOneCompletedOverlay Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelOneCompletedOverlay.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelOneCompletedOverlay.tex)
    {
        printf("levelOneCompletedOverlay  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelOneCompletedOverlay.tex, NULL, NULL, &levelOneCompletedOverlay.rect.w, &levelOneCompletedOverlay.rect.h);
    levelOneCompletedOverlay.rect.w = (int)WINDOW_WIDTH;
    levelOneCompletedOverlay.rect.h = (int)WINDOW_HEIGHT;
    levelOneCompletedOverlay.rect.x = (int)0;
    levelOneCompletedOverlay.rect.y = (int)0;

    //Trophy load
    window.surface = IMG_Load("images/newcomponents/trophy.png");

    if (!window.surface)
    {
        printf("levelOneCompletedMessage Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelOneCompletedMessage.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelOneCompletedMessage.tex)
    {
        printf("levelOneCompletedMessage  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelOneCompletedMessage.tex, NULL, NULL, &levelOneCompletedMessage.rect.w, &levelOneCompletedMessage.rect.h);
    levelOneCompletedMessage.rect.w = (int)460;
    levelOneCompletedMessage.rect.h = (int)406;
    levelOneCompletedMessage.rect.x = WINDOW_WIDTH / 2 - 230;
    levelOneCompletedMessage.rect.y = WINDOW_HEIGHT / 2 - 203;
}
// funtion to destroy textures of levelOne completed
void levelOneCompletedCleanUp()
{

    SDL_DestroyTexture(levelOneCompletedOverlay.tex);
    SDL_DestroyTexture(levelOneCompletedMessage.tex);
    IMG_Quit();
}