#include "drawNewgameWindow.h"

void updateAnimationSpeedForNewgameWindow()
{
    welcomeWindowSkyAnimationSpeed -= 2;
    if (welcomeWindowSkyAnimationSpeed < -welcomeWindowSky.rect.w)
    {
        welcomeWindowSkyAnimationSpeed = 0;
    }

    welcomeWindowBirdsAnimationSpeed += 3;
    if (welcomeWindowBirdsAnimationSpeed > welcomeWindowBirds.rect.w)
    {
        welcomeWindowBirdsAnimationSpeed -= 2 * welcomeWindowBirds.rect.w;
    }
    welcomeWindowMountainsAnimationSpeed -= 1;
    if (welcomeWindowMountainsAnimationSpeed < -welcomeWindowMountains.rect.w)
    {
        welcomeWindowMountainsAnimationSpeed = 0;
    }
}
void drawNewgameWindowFunction()
{
    updateAnimationSpeedForNewgameWindow();
    welcomeWindowSky.rect.x = welcomeWindowSkyAnimationSpeed;
    welcomeWindowBirds.rect.x = welcomeWindowBirdsAnimationSpeed;
    welcomeWindowMountains.rect.x = welcomeWindowMountainsAnimationSpeed;
    SDL_RenderClear(app.rend);

    SDL_RenderCopy(app.rend, welcomeWindowSky.tex, NULL, &welcomeWindowSky.rect);
    welcomeWindowSky.rect.x = welcomeWindowSkyAnimationSpeed + welcomeWindowSky.rect.w;
    SDL_RenderCopy(app.rend, welcomeWindowSky.tex, NULL, &welcomeWindowSky.rect);

    SDL_RenderCopy(app.rend, welcomeWindowBirds.tex, NULL, &welcomeWindowBirds.rect);
    welcomeWindowBirds.rect.x = welcomeWindowBirdsAnimationSpeed + welcomeWindowBirds.rect.w;
    SDL_RenderCopy(app.rend, welcomeWindowBirds.tex, NULL, &welcomeWindowBirds.rect);

    SDL_RenderCopy(app.rend, welcomeWindowMountains.tex, NULL, &welcomeWindowMountains.rect);
    welcomeWindowMountains.rect.x = welcomeWindowMountainsAnimationSpeed + welcomeWindowMountains.rect.w;
    SDL_RenderCopy(app.rend, welcomeWindowMountains.tex, NULL, &welcomeWindowMountains.rect);

    SDL_RenderCopy(app.rend, welcomeWindowTrees.tex, NULL, &welcomeWindowTrees.rect);

    SDL_RenderCopy(app.rend, welcomeWindowGameTitle.tex, NULL, &welcomeWindowGameTitle.rect);
    SDL_RenderCopy(app.rend, newgameWindowlevelOneButton.tex, NULL, &newgameWindowlevelOneButton.rect);
    SDL_RenderCopy(app.rend, newgameWindowlevelTwoButton.tex, NULL, &newgameWindowlevelTwoButton.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}