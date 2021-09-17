#include "variablesLevelOne.h"

// welcome window animation speed

float welcomeWindowSkyAnimationSpeed = 0;
float welcomeWindowMountainsAnimationSpeed = 0;
float welcomeWindowBirdsAnimationSpeed = 0;

float levelOneSkyAnimationSpeed = 0, levelOneMountainsAnimationSpeed = 0,
      levelOneTreeShadeAnimationSpeed = 0, levelOneTreesAnimationSpeed = 0,
      levelOneTrackAnimationSpeed = 0, levelOneCloudsAnimationSpeed = 0;

int levelOneCharacterFramewidth = 0, levelOneCharacterFrameheight = 0,
    levelOneCharacterTexturewidth = 0, levelOneCharacterTextureheight = 0;

float levelOneCharacterFrametime = 0;
int levelOneCharacterPrevtime = 0;
int levelOneCharacterCurrentime = 0;
float levelOneCharacterDeltatime = 0;

int levelOneTigerFramewidth = 0, levelOneTigerFrameheight = 0;
int levelOneTigerTexturewidth = 0, levelOneTigerTextureheight = 0;

float levelOneTigerFrametime = 0;
int levelOneTigerPrevtime = 0;
int levelOneTigerCurrentime = 0;
float levelOneTigerDeltatime = 0;

float levelOneMoveSpeed = 0;

int levelOneHighScore = 0;
char levelOneScoreString[10], levelOneHighScoreString[10],
    scoreBoardPlayerNameString[100][10], scoreBoardPlayerScoreString[100][10];

int space = 0;
int levelOneCurrentScore = 0;

float levelOneCharacterXposition = 600,
      levelOneCharacterYposition = 665;

int levelOneCharacterJumpCurrenttime = 0, levelOneCharacterJumpPrevtime = 0;
float levelOneCharacterJumpDeltatime = 0, levelOneCharacterJumpFrametime = 0;

int levelOneBackgroundCurrenttime = 0, levelOneBackgroundPrevtime = 0;
float levelOneBackgroundDeltatime = 0, levelOneBackgroundFrametime = 0;

char playerName[100] = " ";

char playerNameList[100][100], showPlayerNameList[10000][100];
int scoreList[100];
int levelOnePointEffectAnimationSpeed[5];
int levelOnePointAnimationSpeed[5];
int levelOneObstacleAnimationSpeed[3] = {1380, 1380, 1380};
int levelOneLifeAnimationSpeed[3] = {700, 700, 700};
int curzonPosition = 15000;
int count = 0;
int tigerJumped = 0;
float tigerYposition = 730;
int lifeSize = 6;

Mix_Music *background, *whoWeWantToBe;
Mix_Chunk *levelOneCoingain, *tigerRoar, *hitLevelOne, *gameOver, *click;