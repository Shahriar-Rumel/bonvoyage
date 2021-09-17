#include "initiateLevelTwoCompleted.h"

void levelTwoCompletedLoad(void) // if player completes the game , overlay with a message apears
{
    // Overlay Load

    window.surface = IMG_Load("images/levelone/overlay-min.png");

    if (!window.surface)
    {
        printf("levelTwoCompletedOverlay Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoCompletedOverlay.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoCompletedOverlay.tex)
    {
        printf("levelTwoCompletedOverlay Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoCompletedOverlay.tex, NULL, NULL, &levelTwoCompletedOverlay.rect.w, &levelTwoCompletedOverlay.rect.h);
    levelTwoCompletedOverlay.rect.w = (int)WINDOW_WIDTH;
    levelTwoCompletedOverlay.rect.h = (int)WINDOW_HEIGHT;
    levelTwoCompletedOverlay.rect.x = (int)0;
    levelTwoCompletedOverlay.rect.y = (int)0;

    //Trophy Load
    window.surface = IMG_Load("images/newcomponents/trophy.png");

    if (!window.surface)
    {
        printf("levelTwoCompletedMessage Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoCompletedMessage.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelTwoCompletedMessage.tex)
    {
        printf("levelTwoCompletedMessage Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoCompletedMessage.tex, NULL, NULL, &levelTwoCompletedMessage.rect.w, &levelTwoCompletedMessage.rect.h);
    levelTwoCompletedMessage.rect.w = (int)460;
    levelTwoCompletedMessage.rect.h = (int)406;
    levelTwoCompletedMessage.rect.x = WINDOW_WIDTH / 2 - 230;
    levelTwoCompletedMessage.rect.y = WINDOW_HEIGHT / 2 - 203;
}

void levelTwoCompletedCleanUp()
{
    SDL_DestroyTexture(levelTwoCompletedOverlay.tex);
    SDL_DestroyTexture(levelTwoCompletedMessage.tex);
    IMG_Quit();
}