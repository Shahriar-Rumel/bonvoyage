#include "variablesLevelTwo.h"

int levelTwoCharacterFrameWidth,
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

    levelTwoDragonFramewidth = 0, 
    levelTwoDragonFrameheight = 0,
    levelTwoDragonTexturewidth = 0, 
    levelTwoDragonTextureheight = 0,

    randomGenerator,
    delayCountForPointPopUp = 0,
    delayCountForHearts = 0,
    delayCountForLifeRectChange = 0,
    delayCountForExplosion = 0,
    delayCountForCharacterCollisionEffect = 0,

    currentLife = 100,
    lifePercentage = 0,
    highScore,
    currentScore = 0,
    scoreUpdate = 0,
    levelTwoScoreList[100],
    isspaceclicked = 0,
    iflifeatstake = 0,
    leftbuttonclicked = 0,
    rightbuttonclicked = 1,
    isDownPressed=0,
    isUpPressed=0,
    countLevelTwo = 0,
    thronePosition = 10000;

float characterTwoFrametime = 0,
    characterTwoCurrentime = 0,
    characterTwoPrevtime = 0,
    characterTwoDeltatime = 0.0,
    moveSpeed = 300.0f,
    xPosLevelTwoCharacter = (float)100,
    yPosLevelTwoCharacter = (float)700,

    levelTwoRotatingCoinFrametime = 0,
    levelTwoRotatingCoinPrevtime = 0,
    levelTwoRotatingCoinCurrentime = 0,
    levelTwoRotatingCoinDeltatime = 0.0,

    levelTwoRotatingHeartFrametime = 0,
    levelTwoRotatingHeartPrevtime = 0,
    levelTwoRotatingHeartCurrentime = 0,
    levelTwoRotatingHeartDeltatime = 0.0,
      
    levelTwoDragonFrametime = 0,
    levelTwoDragonPrevtime = 0,
    levelTwoDragonCurrentime = 0,
    levelTwoDragonDeltatime = 0.0,

    levelTwoSkyAnimationSpeed = 0,
    levelTwoMountainsAnimationSpeed = 0,
    levelTwoTreeShadeAnimationSpeed = 0,
    levelTwoTreesAnimationSpeed = 0,
    levelTwoTrackAnimationSpeed = 0,
    levelTwoCloudsAnimationSpeed = 0,
    levelTwoBirdsAnimationSpeed = 0,
    xPosLevelTwoTrack = (float)WINDOW_WIDTH / 2 + 200,
    yPosLevelTwoTrack = (float)WINDOW_HEIGHT / 2 - 200,
    xPosLevelTwoTrack2 = (float)WINDOW_WIDTH / 2 + 200,
    yPosLevelTwoTrack2 = (float)WINDOW_HEIGHT / 2 - 200;

char lifeString[256] = " ",
    scoreString[256],
    highScoreString[256],
    levelTwoScoreBoardPlayerNameString[100][10],
    levelTwoScoreBoardPlayerScoreString[100][10],
    levelTwoPlayerNameList[100][100], 
    showLevelTwoPlayerNameList[10000][100],
    levelTwoHighScoreString[10],
    levelTwoPlayerName[100] = " ";

Mix_Music *got;
Mix_Chunk *coingain,
    *explosionsound,
    *jumpsound,
    *pointgainsound;
