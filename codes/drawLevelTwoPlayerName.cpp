#include "drawLevelTwoPlayerName.h"

void updateAnimationSpeedForLevelTwoPlayerName()
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
void drawLevelTwoPlayerNameFunction()
{
    updateAnimationSpeedForLevelTwoPlayerName();
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
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
    SDL_RenderCopy(app.rend, levelTwoEnterName.tex, NULL, &levelTwoEnterName.rect);
    SDL_RenderCopy(app.rend, levelTwoPlayerNameBox.tex, NULL, &levelTwoPlayerNameBox.rect);
    SDL_RenderCopy(app.rend, levelTwoEnterButton.tex, NULL, &levelTwoEnterButton.rect);
    SDL_RenderCopy(app.rend, levelTwoEnterCommand.tex, NULL, &levelTwoEnterCommand.rect);
}