#include "commonHeaders.h"
extern App app;
extern component

    levelOneWindowSky,
    levelOneWindowSun,
    levelOneWindowMountains,
    levelOneWindowTreeShade,
    levelOneWindowTrees,
    levelOneWindowClouds,
    levelOneWindowTrack,
    levelOneWindowCharacter,
    levelOneWindowTiger,
    levelOneWindowScore,
    levelOneWindowHighScore,
    levelOneWindowScoreText,
    levelOneWindowHighScoreText,
    levelOneCurzon, initialInstructions,

    characterFramePosition,
    tigerFramePosition,

    levelOneWindowCoins[5],
    levelOneWindowObstacle[3],

    back;

extern Variables variables;

extern void updateScore(void);
extern void drawCoinsFunction(void);
extern void levelOneDrawObstacleFunction(void);
extern void levelOneDrawLifeFunction(void);
extern void levelOneDrawLifeLossFunction();

extern void collision(void);
extern void drawCoinsEffectFunction(void);