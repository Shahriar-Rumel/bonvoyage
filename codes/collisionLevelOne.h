#include "commonHeaders.h"

extern App app;
extern component

    levelOneWindowCharacter,

    characterFramePosition,

    levelOneWindowCoins[5],
    levelOneWindowCoinsEffect[5],

    levelOneWindowObstacle[3],
    tigerFramePosition,
    levelOneWindowTiger,

    levelOneWindowLife[6],
    levelOneLifeLoss[3];

extern Variables variables;

extern void updateScore(void);
extern void drawCoinsFunction(void);
extern void drawCoinsEffectFunction(void);
extern void coineffectdelay();
extern void obstacleeffectdelay();

extern void coinsupdateanimation(void);
extern void collision(void);
extern void endlife(void);