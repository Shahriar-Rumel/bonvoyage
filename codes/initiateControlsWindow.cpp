#include "initiateControlsWindow.h"

void ControlsWindowLoad(void)
{

    window.surface = IMG_Load("images/newcomponents/finalControlsWindow.png");

    if (!window.surface)
    {
        printf("controlsList Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    controlsList.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!controlsList.tex)
    {
        printf("controlsList  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    SDL_QueryTexture(controlsList.tex, NULL, NULL, &controlsList.rect.w, &controlsList.rect.h);
    controlsList.rect.w = (int)786;
    controlsList.rect.h = (int)435;
    controlsList.rect.x = (int)WINDOW_WIDTH / 2 - 393;
    controlsList.rect.y = (int)WINDOW_HEIGHT / 2 - 247;
}
void controlsWindowCleanUp()
{

    SDL_DestroyTexture(controlsList.tex);
    IMG_Quit();
}