#include "drawLevelOneWindow.h"

//funtion to add the animation effects
void updateAnimationSpeedForLevelOneWindow()
{
    //getting the current time 
    levelOneCharacterPrevtime = levelOneCharacterCurrentime;
    levelOneCharacterCurrentime = SDL_GetTicks();
    levelOneCharacterDeltatime = (levelOneCharacterCurrentime - levelOneCharacterPrevtime) / 220.0f;
    
    //setting the frame rate according to device fps
    levelOneTigerPrevtime = levelOneTigerCurrentime;
    levelOneTigerCurrentime = SDL_GetTicks();
    levelOneTigerDeltatime = (levelOneTigerCurrentime - levelOneTigerPrevtime) / 280.0f;

    levelOneCharacterJumpPrevtime = levelOneCharacterJumpCurrenttime;
    levelOneCharacterJumpCurrenttime = SDL_GetTicks();
    levelOneCharacterJumpDeltatime = (levelOneCharacterJumpCurrenttime - levelOneCharacterJumpPrevtime) / 20.0f;

    levelOneBackgroundPrevtime = levelOneBackgroundCurrenttime;
    levelOneBackgroundCurrenttime = SDL_GetTicks();
    levelOneBackgroundDeltatime = (levelOneBackgroundCurrenttime - levelOneBackgroundPrevtime) / 20.0f;
    
    //character sprite movement
    levelOneCharacterFrametime += levelOneCharacterDeltatime;
    if (levelOneCharacterFrametime >= (0.25f))
    {
        levelOneCharacterFrametime = 0.0;
        levelOneWindowCharacter.rect.x += levelOneCharacterFramewidth;

        if (levelOneWindowCharacter.rect.x >= levelOneCharacterTexturewidth)
        {
            levelOneWindowCharacter.rect.x = 0;
            levelOneCurrentScore += 22;
        }
    }
    
    //setting the tiger sprite movement or running effect
    levelOneTigerFrametime += levelOneTigerDeltatime;
    if (levelOneTigerFrametime >= (0.25f))
    {
        levelOneTigerFrametime = 0.0;
        levelOneWindowTiger.rect.x += levelOneTigerFramewidth;

        if (levelOneWindowTiger.rect.x >= levelOneTigerTexturewidth)
        {
            levelOneWindowTiger.rect.x = 0;
        }
    }

    //when the character reaches the end
    if (characterFramePosition.rect.x >= levelOneCurzon.rect.x + 100)
    {
        variables.levelOneCompleted = 1;
        variables.levelOne = 0;
        variables.saveScore = 1;
    }
    levelOneBackgroundFrametime += levelOneBackgroundDeltatime;
    if (levelOneBackgroundFrametime >= (0.25f))
    {
        levelOneBackgroundFrametime = 0.0;
        
        levelOneSkyAnimationSpeed -= 0.412;
        //setting the movement speed for sky
        if (levelOneSkyAnimationSpeed < -levelOneWindowSky.rect.w)
        {
            levelOneSkyAnimationSpeed = 0;
        }
         //setting the movement speed for mountains
        levelOneMountainsAnimationSpeed -= 1.625;
        if (levelOneMountainsAnimationSpeed < -levelOneWindowMountains.rect.w)
        {
            levelOneMountainsAnimationSpeed = 0;
        }
         //setting the movement speed for treeshade
        levelOneTreeShadeAnimationSpeed -= 2.125;
        if (levelOneTreeShadeAnimationSpeed < -levelOneWindowTreeShade.rect.w)
        {
            levelOneTreeShadeAnimationSpeed = 0;
        }
         //setting the movement speed for trees
        levelOneTreesAnimationSpeed -= 4.25;
        if (levelOneTreesAnimationSpeed < -levelOneWindowTrees.rect.w)
        {
            levelOneTreesAnimationSpeed = 0;
        }
          //setting the movement speed for track
        levelOneTrackAnimationSpeed -= 5.5;
        if (levelOneTrackAnimationSpeed < -levelOneWindowTrack.rect.w)
        {
            levelOneTrackAnimationSpeed = 0;
        }
    }
    //resetting the character position
    if (levelOneCharacterYposition <= 40)
    {
        levelOneCharacterYposition = 40;
    }
    if (levelOneCharacterXposition >= 600 && levelOneCharacterXposition < 665)
    {
        levelOneCharacterXposition = 600;
    }
    if (levelOneCharacterYposition >= 665)
    {
        levelOneCharacterYposition = 665;
    }
    if (levelOneCharacterXposition >= 700)
    {
        levelOneCharacterXposition = 600;
    }
    characterFramePosition.rect.x = WINDOW_WIDTH / 2 - 100;
    characterFramePosition.rect.y = levelOneCharacterYposition;

    //setting the jump effect
    levelOneCharacterJumpFrametime += levelOneCharacterJumpDeltatime;

    if (levelOneCharacterJumpFrametime >= (0.25f))
    {
        levelOneCharacterJumpFrametime = 0.0f;
        if (levelOneCharacterYposition < 665)
        {
            levelOneCharacterYposition += SCROLL_SPEED / 70;
        }

        if (tigerYposition < 730)
        {
            tigerYposition += (float)SCROLL_SPEED / 130;
        }
    }

    tigerFramePosition.rect.y = tigerYposition;
    //setting what happens after life becomes zero
    if (lifeSize == 0)
    {
        variables.levelOne = 0;
        variables.levelOnegameOver = 1;
        Mix_PlayChannel(-1, gameOver, 0);
    }
    curzonPosition -= 3;

    //setting tiger roar effect
    if (levelOneCurrentScore % 100 == 0)
    {
        Mix_VolumeChunk(tigerRoar, 10);
        Mix_PlayChannel(-1, tigerRoar, 0);
    }
}
//funtion to load all the animations
void drawLevelOneWindowFunction()
{

    if (variables.levelOne == 1 && space == 1)
    {
        updateAnimationSpeedForLevelOneWindow();
        updateScore();
    }
    //setting the clouds animation speed
    levelOneCloudsAnimationSpeed -= 0.812;
    if (levelOneCloudsAnimationSpeed < -levelOneWindowClouds.rect.w)
    {
        levelOneCloudsAnimationSpeed = 0;
    }
    
    levelOneWindowSky.rect.x = levelOneSkyAnimationSpeed;
    levelOneWindowMountains.rect.x = levelOneMountainsAnimationSpeed;
    levelOneWindowTreeShade.rect.x = levelOneTreeShadeAnimationSpeed;
    levelOneWindowTrees.rect.x = levelOneTreesAnimationSpeed;
    levelOneWindowClouds.rect.x = levelOneCloudsAnimationSpeed;
    levelOneWindowTrack.rect.x = levelOneTrackAnimationSpeed;
    levelOneCurzon.rect.x = curzonPosition;

    //rendering all the objects
    SDL_RenderClear(app.rend);
    
    //rendering the elements everytime new window comes
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
    if (variables.levelOne == 1 && space == 0)
        SDL_RenderCopy(app.rend, initialInstructions.tex, NULL, &initialInstructions.rect);

    if (variables.levelOne == 1 && space == 1)
    {
        SDL_RenderCopy(app.rend, levelOneWindowCharacter.tex, &levelOneWindowCharacter.rect, &characterFramePosition.rect);
        SDL_RenderCopy(app.rend, levelOneWindowTiger.tex, &levelOneWindowTiger.rect, &tigerFramePosition.rect);
    }

    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
    
    //calling the functions for showing rewards and obstacles
    if (variables.levelOne == 1 && space == 1)
    {
        drawCoinsFunction();
        levelOneDrawObstacleFunction();
        
        //calling the funtion to detect collision
        collision();
        drawCoinsEffectFunction();
        levelOneDrawLifeFunction();
        levelOneDrawLifeLossFunction();
    }
    SDL_RenderCopy(app.rend, levelOneCurzon.tex, NULL, &levelOneCurzon.rect);
}