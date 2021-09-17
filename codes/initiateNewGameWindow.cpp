#include "initiateNewGameWindow.h"

void newgameWindowLoad(void)
{
    //Sundarban Button

    window.surface = IMG_Load("images/buttons/newSundarbanButton.png");

    if (!window.surface)
    {
        printf("newgameWindowlevelOneButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    newgameWindowlevelOneButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!newgameWindowlevelOneButton.tex)
    {
        printf("newgameWindowlevelOneButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(newgameWindowlevelOneButton.tex, NULL, NULL, &newgameWindowlevelOneButton.rect.w, &newgameWindowlevelOneButton.rect.h);
    newgameWindowlevelOneButton.rect.w = (int)322;
    newgameWindowlevelOneButton.rect.h = (int)63;
    newgameWindowlevelOneButton.rect.x = (int)WINDOW_WIDTH / 2 - 161;
    newgameWindowlevelOneButton.rect.y = (int)WINDOW_HEIGHT / 2 - 200;

    //WinterFell Button

    window.surface = IMG_Load("images/newcomponents/winterfell.png");

    if (!window.surface)
    {
        printf("newgameWindowlevelTwoButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    newgameWindowlevelTwoButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!newgameWindowlevelTwoButton.tex)
    {
        printf("newgameWindowlevelTwoButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(newgameWindowlevelTwoButton.tex, NULL, NULL, &newgameWindowlevelTwoButton.rect.w, &newgameWindowlevelTwoButton.rect.h);
    newgameWindowlevelTwoButton.rect.w = (int)322;
    newgameWindowlevelTwoButton.rect.h = (int)63;
    newgameWindowlevelTwoButton.rect.x = (int)WINDOW_WIDTH / 2 - 161;
    newgameWindowlevelTwoButton.rect.y = (int)WINDOW_HEIGHT / 2 - 100;
}

void newGameWindowCleanUp()
{

    SDL_DestroyTexture(newgameWindowlevelOneButton.tex);
    SDL_DestroyTexture(newgameWindowlevelTwoButton.tex);
    IMG_Quit();
}