#include "drawLevelTwoGameOver.h"

void updateAnimationSpeedForLevelTwoGameOver()
{

    levelTwoSkyAnimationSpeed -= 0.5;
    if (levelTwoSkyAnimationSpeed < -levelTwoWindowSky.rect.w)
    {
        levelTwoSkyAnimationSpeed = 0;
    }

    levelTwoMountainsAnimationSpeed -= 2;
    if (levelTwoMountainsAnimationSpeed < -levelTwoWindowMountains.rect.w)
    {
        levelTwoMountainsAnimationSpeed = 0;
    }

    levelTwoTreeShadeAnimationSpeed -= 4;
    if (levelTwoTreeShadeAnimationSpeed < -levelTwoWindowTreeShade.rect.w)
    {
        levelTwoTreeShadeAnimationSpeed = 0;
    }
    levelTwoCloudsAnimationSpeed -= 1;
    if (levelTwoCloudsAnimationSpeed < -levelTwoWindowClouds.rect.w)
    {
        levelTwoCloudsAnimationSpeed = 0;
    }

    levelTwoTrackAnimationSpeed -= 6;
    if (levelTwoTrackAnimationSpeed < -levelTwoWindowTrack.rect.w)
    {
        levelTwoTrackAnimationSpeed = 0;
    }
}
void drawLevelTwoGameOverFunction()
{

    if (variables.levelTwoGameOver == 1)
    {
        updateAnimationSpeedForLevelTwoGameOver();
    }

    levelTwoWindowSky.rect.x = levelTwoSkyAnimationSpeed;
    levelTwoWindowMountains.rect.x = levelTwoMountainsAnimationSpeed;
    levelTwoWindowTreeShade.rect.x = levelTwoTreeShadeAnimationSpeed;
    levelTwoWindowClouds.rect.x = levelTwoCloudsAnimationSpeed;
    levelTwoWindowTrack.rect.x = levelTwoTrackAnimationSpeed;
    SDL_RenderClear(app.rend);

    SDL_RenderCopy(app.rend, levelTwoWindowSky.tex, NULL, &levelTwoWindowSky.rect);
    levelTwoWindowSky.rect.x = levelTwoSkyAnimationSpeed + levelTwoWindowSky.rect.w;
    SDL_RenderCopy(app.rend, levelTwoWindowSky.tex, NULL, &levelTwoWindowSky.rect);

    SDL_RenderCopy(app.rend, levelTwoWindowMountains.tex, NULL, &levelTwoWindowMountains.rect);
    levelTwoWindowMountains.rect.x = levelTwoMountainsAnimationSpeed + levelTwoWindowMountains.rect.w;
    SDL_RenderCopy(app.rend, levelTwoWindowMountains.tex, NULL, &levelTwoWindowMountains.rect);

    SDL_RenderCopy(app.rend, levelTwoWindowTreeShade.tex, NULL, &levelTwoWindowTreeShade.rect);
    levelTwoWindowTreeShade.rect.x = levelTwoTreeShadeAnimationSpeed + levelTwoWindowTreeShade.rect.w;
    SDL_RenderCopy(app.rend, levelTwoWindowTreeShade.tex, NULL, &levelTwoWindowTreeShade.rect);

    SDL_RenderCopy(app.rend, levelTwoWindowTrack.tex, NULL, &levelTwoWindowTrack.rect);
    levelTwoWindowTrack.rect.x = levelTwoTrackAnimationSpeed + levelTwoWindowTrack.rect.w;
    SDL_RenderCopy(app.rend, levelTwoWindowTrack.tex, NULL, &levelTwoWindowTrack.rect);

    SDL_RenderCopy(app.rend, levelTwoWindowMoon.tex, NULL, &levelTwoWindowMoon.rect);

    SDL_RenderCopy(app.rend, levelTwoWindowClouds.tex, NULL, &levelTwoWindowClouds.rect);
    levelTwoWindowClouds.rect.x = levelTwoCloudsAnimationSpeed + levelTwoWindowClouds.rect.w;
    SDL_RenderCopy(app.rend, levelTwoWindowClouds.tex, NULL, &levelTwoWindowClouds.rect);

    SDL_RenderCopy(app.rend, levelOneWindowScore.tex, NULL, &levelOneWindowScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScore.tex, NULL, &levelOneWindowHighScore.rect);
    SDL_RenderCopy(app.rend, levelTwoWindowScoreText.tex, NULL, &levelTwoWindowScoreText.rect);
    SDL_RenderCopy(app.rend, levelTwoWindowHighScoreText.tex, NULL, &levelTwoWindowHighScoreText.rect);

    SDL_RenderCopy(app.rend, levelOneCompletedOverlay.tex, NULL, &levelOneCompletedOverlay.rect);
    SDL_RenderCopy(app.rend, levelOneGameOverMessage.tex, NULL, &levelOneGameOverMessage.rect);

    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}