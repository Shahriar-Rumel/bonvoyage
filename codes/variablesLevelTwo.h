#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "preprocessors.h"

extern int levelTwoCharacterFrameWidth,
    levelTwoCharacterFrameHeight,
    levelTwoCharacterTextureWidth,
    levelTwoCharacterTextureHeight,

    levelTwoCoinTextureHeight,
    levelTwoCoinTextureWidth,
    levelTwoCoinFrameHeight,
    levelTwoCoinFrameWidth,

    levelTwoHeartTextureWidth,
    levelTwoHeartTextureHeight,
    levelTwoHeartFrameHeight,
    levelTwoHeartFrameWidth,

    levelTwoDragonFramewidth, 
    levelTwoDragonFrameheight,
    levelTwoDragonTexturewidth, 
    levelTwoDragonTextureheight,

    randomGenerator,
    delayCountForPointPopUp,
    delayCountForHearts,
    delayCountForLifeRectChange,
    delayCountForExplosion,
    delayCountForCharacterCollisionEffect,

    currentLife,
    lifePercentage,
    highScore,
    currentScore,
    scoreUpdate,
    levelTwoScoreList[100],
    isspaceclicked,
    iflifeatstake,
    leftbuttonclicked,
    rightbuttonclicked,
    isDownPressed,
    isUpPressed,
    countLevelTwo,
    thronePosition;

extern float characterTwoFrametime,
    characterTwoPrevtime,
    characterTwoCurrentime,
    characterTwoDeltatime ,
    moveSpeed,
    xPosLevelTwoCharacter,
    yPosLevelTwoCharacter,

    levelTwoRotatingCoinFrametime,
    levelTwoRotatingCoinPrevtime,
    levelTwoRotatingCoinCurrentime,
    levelTwoRotatingCoinDeltatime,

    levelTwoRotatingHeartFrametime,
    levelTwoRotatingHeartPrevtime,
    levelTwoRotatingHeartCurrentime,
    levelTwoRotatingHeartDeltatime,
      
    levelTwoDragonFrametime,
    levelTwoDragonPrevtime,
    levelTwoDragonCurrentime,
    levelTwoDragonDeltatime,

    levelTwoSkyAnimationSpeed,
    levelTwoMountainsAnimationSpeed,
    levelTwoTreeShadeAnimationSpeed,
    levelTwoTreesAnimationSpeed,
    levelTwoTrackAnimationSpeed,
    levelTwoCloudsAnimationSpeed,
    levelTwoBirdsAnimationSpeed,
    xPosLevelTwoTrack,
    yPosLevelTwoTrack,
    xPosLevelTwoTrack2,
    yPosLevelTwoTrack2;

extern char lifeString[256],
    scoreString[256],
    highScoreString[256],
    levelTwoScoreBoardPlayerNameString[100][10],
    levelTwoScoreBoardPlayerScoreString[100][10],
    levelTwoPlayerNameList[100][100], 
    showLevelTwoPlayerNameList[10000][100],
    levelTwoHighScoreString[10],
    levelTwoPlayerName[100];

extern Mix_Music *got;
extern Mix_Chunk *coingain,
    *explosionsound,
    *jumpsound,
    *pointgainsound;