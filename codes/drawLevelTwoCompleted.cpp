#include "drawLevelTwoCompleted.h"

void updateAnimationSpeedForLevelTwoCompleted()
{   
    // adjusting animation speed for levelTwoDragon 
    levelTwoDragonPrevtime = levelTwoDragonCurrentime;
    levelTwoDragonCurrentime = SDL_GetTicks();
    levelTwoDragonDeltatime = (levelTwoDragonCurrentime - levelTwoDragonPrevtime) / 280.0f;
    
    // updating the frame for animating levelTwoDragonSprite 
    levelTwoDragonFrametime += levelTwoDragonDeltatime;
    if (levelTwoDragonFrametime >= (0.25f))
    {
        levelTwoDragonFrametime = 0.0;
        levelTwoDragon.rect.x += levelTwoDragonFramewidth;

        if (levelTwoDragon.rect.x >= levelTwoDragonTexturewidth)
        {
            levelTwoDragon.rect.x = 0;
        }
    }
    
    //implementing collision after effect for levelTwoCharacter
    if (delayCountForCharacterCollisionEffect == 250)
    {
        if (currentLife > 10)
        {
            levelTwoWindowCharacter.surface = IMG_Load("images/level2obstacles/sonicsprite.png");
            levelTwoWindowCharacter.tex = SDL_CreateTextureFromSurface(app.rend, levelTwoWindowCharacter.surface);
        }
        else
        {
            levelTwoWindowCharacter.surface = IMG_Load("images/level2obstacles/sonicsprite3.png");
            levelTwoWindowCharacter.tex = SDL_CreateTextureFromSurface(app.rend, levelTwoWindowCharacter.surface);
        }
        delayCountForCharacterCollisionEffect = 0;
    }
    if (delayCountForCharacterCollisionEffect > 0)
    {
        delayCountForCharacterCollisionEffect++;
    }
    
    //adjusting animation speed for levelTwoCharacter 
    characterTwoPrevtime = characterTwoCurrentime;
    characterTwoCurrentime = SDL_GetTicks();
    characterTwoDeltatime = (characterTwoCurrentime - characterTwoPrevtime) / 280.0f;

    characterTwoFrametime += characterTwoDeltatime;

    if (characterTwoFrametime >= (0.25f))
    {
        characterTwoFrametime = 0;
        levelTwoWindowCharacter.rect.x += levelTwoCharacterFrameWidth;
        if (levelTwoWindowCharacter.rect.x == levelTwoCharacterTextureWidth && levelTwoWindowCharacter.rect.y == levelTwoCharacterFrameHeight)
        {
            levelTwoWindowCharacter.rect.y = 0;
            levelTwoWindowCharacter.rect.x = 0;
        }
        else if (levelTwoWindowCharacter.rect.x == levelTwoCharacterTextureWidth)
        {
            levelTwoWindowCharacter.rect.x = 0;
            levelTwoWindowCharacter.rect.y = levelTwoCharacterFrameHeight;
        }
    }
    
    // adjusting animation speed for levelTwoRotatingCoins
    levelTwoRotatingCoinPrevtime = levelTwoRotatingCoinCurrentime;
    levelTwoRotatingCoinCurrentime = SDL_GetTicks();
    levelTwoRotatingCoinDeltatime = (levelTwoRotatingCoinCurrentime - levelTwoRotatingCoinPrevtime) / 280.0f;

    // updating the frame for animating levelTwoRotatingCoinSprite 
    levelTwoRotatingCoinFrametime += levelTwoRotatingCoinDeltatime;

    if (levelTwoRotatingCoinFrametime >= (0.25f))
    {
        levelTwoRotatingCoinFrametime = 0;
        levelTwoRotatingCoin.rect.x += levelTwoCoinFrameWidth;
        if (levelTwoRotatingCoin.rect.x == levelTwoCoinTextureWidth && levelTwoRotatingCoin.rect.y == levelTwoCoinFrameHeight)
        {
            levelTwoRotatingCoin.rect.y = 0;
            levelTwoRotatingCoin.rect.x = 0;
        }
        else if (levelTwoRotatingCoin.rect.x == levelTwoCoinTextureWidth)
        {
            levelTwoRotatingCoin.rect.x = 0;
            levelTwoRotatingCoin.rect.y = levelTwoCoinFrameHeight;
        }
    }
    
    // adjusting animation speed for levelTwoRotatingHearts
    levelTwoRotatingHeartPrevtime = levelTwoRotatingHeartCurrentime;
    levelTwoRotatingHeartCurrentime = SDL_GetTicks();
    levelTwoRotatingHeartDeltatime = (levelTwoRotatingHeartCurrentime - levelTwoRotatingHeartPrevtime) / 280.0f;

    // updating the frame for animating levelTwoRotatingHeartSprite
    levelTwoRotatingHeartFrametime += levelTwoRotatingHeartDeltatime;

    if (levelTwoRotatingHeartFrametime >= (0.25f))
    {
        levelTwoRotatingHeartFrametime = 0;
        levelTwoRotatingHeart.rect.x += levelTwoHeartFrameWidth;
        if (levelTwoRotatingHeart.rect.x == levelTwoHeartTextureWidth && levelTwoRotatingHeart.rect.y == levelTwoHeartFrameHeight)
        {
            levelTwoRotatingHeart.rect.y = 0;
            levelTwoRotatingHeart.rect.x = 0;
        }
        else if (levelTwoRotatingHeart.rect.x == levelTwoHeartTextureWidth)
        {
            levelTwoRotatingHeart.rect.x = 0;
            levelTwoRotatingHeart.rect.y = levelTwoHeartFrameHeight;
        }
    }

    // keeping levelTwoCharacter into the frame 
    if (yPosLevelTwoCharacter <= 40)
    {
        yPosLevelTwoCharacter = 40;
    }
    if (xPosLevelTwoCharacter <= 40)
    {
        xPosLevelTwoCharacter = 40;
    }
    if (yPosLevelTwoCharacter >= 800)
    {
        yPosLevelTwoCharacter = 800;
    }
    if (xPosLevelTwoCharacter >= WINDOW_WIDTH)
    {
        xPosLevelTwoCharacter = 0;
    }

    levelTwoWindowCharacterPosition.rect.x = xPosLevelTwoCharacter;
    levelTwoWindowCharacterPosition.rect.y = yPosLevelTwoCharacter;
    

    // adjusting the animation speeds for levelTwo sky, mountains, treeShades, clouds, windowTrack 
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
void drawLevelTwoCompletedFunction()
{
    countLevelTwo++;

    if (variables.levelTwoCompleted == 1)
    {
        updateAnimationSpeedForLevelTwoCompleted();
    }
    if (variables.levelTwoCompleted == 1 && countLevelTwo == 1)
    {
        updateLevelTwoScore();
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

    SDL_RenderCopy(app.rend, levelTwoCompletedOverlay.tex, NULL, &levelTwoCompletedOverlay.rect);
    SDL_RenderCopy(app.rend, levelTwoCompletedMessage.tex, NULL, &levelTwoCompletedMessage.rect);

    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}