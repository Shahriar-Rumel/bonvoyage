#include "drawLevelOneCompleted.h"

//funtion to control the speeds of the levelOne completed window elements
void updateAnimationSpeedForLevelOneCompleted()
{   
    //getting the current time
    levelOneBackgroundPrevtime = levelOneBackgroundCurrenttime;
    levelOneBackgroundCurrenttime = SDL_GetTicks();
    levelOneBackgroundDeltatime = (levelOneBackgroundCurrenttime - levelOneBackgroundPrevtime) / 20.0f;

    levelOneBackgroundFrametime += levelOneBackgroundDeltatime;
    if (levelOneBackgroundFrametime >= (0.25f))
    {
        levelOneBackgroundFrametime = 0.0;

        levelOneSkyAnimationSpeed -= 0.412;
        if (levelOneSkyAnimationSpeed < -levelOneWindowSky.rect.w)
        {
            levelOneSkyAnimationSpeed = 0;
        }
        levelOneCloudsAnimationSpeed -= 0.812;
        if (levelOneCloudsAnimationSpeed < -levelOneWindowClouds.rect.w)
        {
            levelOneCloudsAnimationSpeed = 0;
        }
        levelOneMountainsAnimationSpeed -= 1.625;
        if (levelOneMountainsAnimationSpeed < -levelOneWindowMountains.rect.w)
        {
            levelOneMountainsAnimationSpeed = 0;
        }

        levelOneTreeShadeAnimationSpeed -= 2.125;
        if (levelOneTreeShadeAnimationSpeed < -levelOneWindowTreeShade.rect.w)
        {
            levelOneTreeShadeAnimationSpeed = 0;
        }

        levelOneTreesAnimationSpeed -= 4.25;
        if (levelOneTreesAnimationSpeed < -levelOneWindowTrees.rect.w)
        {
            levelOneTreesAnimationSpeed = 0;
        }

        levelOneTrackAnimationSpeed -= 5.5;
        if (levelOneTrackAnimationSpeed < -levelOneWindowTrack.rect.w)
        {
            levelOneTrackAnimationSpeed = 0;
        }
    }
}
//funtion to render the components of levelOne completed window
void drawLevelOneCompletedFunction()
{   
    //when game ends count increases
    count++;
    
    //writes the score in files
    if (variables.saveScore == 1)
    {
        updateAnimationSpeedForLevelOneCompleted();
    }
    //count is used to make sure score is written only once for one player
    if (variables.saveScore == 1 && count == 1)
    {
        updateScore();
    }
    levelOneWindowSky.rect.x = levelOneSkyAnimationSpeed;
    levelOneWindowMountains.rect.x = levelOneMountainsAnimationSpeed;
    levelOneWindowTreeShade.rect.x = levelOneTreeShadeAnimationSpeed;
    levelOneWindowTrees.rect.x = levelOneTreesAnimationSpeed;
    levelOneWindowClouds.rect.x = levelOneCloudsAnimationSpeed;
    levelOneWindowTrack.rect.x = levelOneTrackAnimationSpeed;
    SDL_RenderClear(app.rend);

    SDL_RenderCopy(app.rend, levelOneWindowSky.tex, NULL, &levelOneWindowSky.rect);
    levelOneWindowSky.rect.x = levelOneSkyAnimationSpeed + levelOneWindowSky.rect.w;
    SDL_RenderCopy(app.rend, levelOneWindowSky.tex, NULL, &levelOneWindowSky.rect);

    SDL_RenderCopy(app.rend, levelOneWindowSun.tex, NULL, &levelOneWindowSun.rect);

    SDL_RenderCopy(app.rend, levelOneWindowClouds.tex, NULL, &levelOneWindowClouds.rect);
    levelOneWindowClouds.rect.x = levelOneCloudsAnimationSpeed + levelOneWindowClouds.rect.w;
    SDL_RenderCopy(app.rend, levelOneWindowClouds.tex, NULL, &levelOneWindowClouds.rect);

    SDL_RenderCopy(app.rend, levelOneWindowMountains.tex, NULL, &levelOneWindowMountains.rect);
    levelOneWindowMountains.rect.x = levelOneMountainsAnimationSpeed + levelOneWindowMountains.rect.w;
    SDL_RenderCopy(app.rend, levelOneWindowMountains.tex, NULL, &levelOneWindowMountains.rect);

    SDL_RenderCopy(app.rend, levelOneWindowTreeShade.tex, NULL, &levelOneWindowTreeShade.rect);
    levelOneWindowTreeShade.rect.x = levelOneTreeShadeAnimationSpeed + levelOneWindowTreeShade.rect.w;
    SDL_RenderCopy(app.rend, levelOneWindowTreeShade.tex, NULL, &levelOneWindowTreeShade.rect);

    SDL_RenderCopy(app.rend, levelOneWindowTrees.tex, NULL, &levelOneWindowTrees.rect);
    levelOneWindowTrees.rect.x = levelOneTreesAnimationSpeed + levelOneWindowTrees.rect.w;
    SDL_RenderCopy(app.rend, levelOneWindowTrees.tex, NULL, &levelOneWindowTrees.rect);

    SDL_RenderCopy(app.rend, levelOneWindowTrack.tex, NULL, &levelOneWindowTrack.rect);
    levelOneWindowTrack.rect.x = levelOneTrackAnimationSpeed + levelOneWindowTrack.rect.w;
    SDL_RenderCopy(app.rend, levelOneWindowTrack.tex, NULL, &levelOneWindowTrack.rect);

    SDL_RenderCopy(app.rend, levelOneWindowScore.tex, NULL, &levelOneWindowScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScore.tex, NULL, &levelOneWindowHighScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowScoreText.tex, NULL, &levelOneWindowScoreText.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScoreText.tex, NULL, &levelOneWindowHighScoreText.rect);
    //rendering the levelOne completed message
    SDL_RenderCopy(app.rend, levelOneCompletedOverlay.tex, NULL, &levelOneCompletedOverlay.rect);
    SDL_RenderCopy(app.rend, levelOneCompletedMessage.tex, NULL, &levelOneCompletedMessage.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}