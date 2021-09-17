#include "resetAll.h"

void resetAll() // Resetting all the variables
{
    variables.gameWindowBegin = 1;
    variables.levelOne = 0;
    variables.levelTwo = 0;
    variables.chooseLevel = 0;
    variables.levelOneCompleted = 0;
    variables.levelOnePlayerName = 0;
    variables.newScore = 0;
    variables.ScoreBoard = 0;
    space = 0;
    variables.legendsWindow = 0;
    levelOneWindowTrack.rect.x = 0;
    levelOneCurrentScore = 0;
    variables.levelOnegameOver = 0;
    variables.levelTwoCompleted = 0;
    variables.controlsWindow = 0;
    variables.levelTwoGameOver = 0;

    variables.levelTwoScoreBoard = 0;

    variables.levelTwoPlayerName = 0;
    variables.newLevelTwoScore = 0;

    lifeSize = 6;

    strcpy(playerName, " ");
    strcpy(levelTwoPlayerName, " ");
    updatePlayerName();
    updateLevelTwoPlayerName();
    updateScore();

    levelOneSkyAnimationSpeed = 0;
    levelOneMountainsAnimationSpeed = 0;
    levelOneTreeShadeAnimationSpeed = 0;
    levelOneTreesAnimationSpeed = 0;
    levelOneCloudsAnimationSpeed = 0;
    levelOneTrackAnimationSpeed = 0;

    levelOneCharacterXposition = 600;
    levelOneCharacterYposition = 665;
    tigerYposition = 730;

    levelTwoSkyAnimationSpeed = 0;
    levelTwoMountainsAnimationSpeed = 0;
    levelTwoCloudsAnimationSpeed = 0;
    levelTwoTreeShadeAnimationSpeed = 0;
    levelTwoTrackAnimationSpeed = 0;
    xPosLevelTwoCharacter = 0;

    for (int i = 0; i < 5; i++)
    {
        levelOnePointEffectAnimationSpeed[i] = 0;
        levelOnePointAnimationSpeed[i] = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        levelOneObstacleAnimationSpeed[i] = 1380;
        levelOneLifeAnimationSpeed[i] = 700;
        levelOneLifeLoss[i].rect.w = (int)0;
        levelOneLifeLoss[i].rect.h = (int)0;
    }
    curzonPosition = 15000;
    count = 0;
    currentScore = 0;
    lifePercentage = 0;
    isspaceclicked = 0;
    rightbuttonclicked = 1;
    leftbuttonclicked = 0;
    levelTwoWindowLoad();

    countLevelTwo = 0;
    thronePosition = 10000;
    SDL_SetTextureColorMod(levelOneWindowCharacter.tex, 255, 255, 255);
}