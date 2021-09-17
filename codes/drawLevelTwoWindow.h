#include "commonHeaders.h"
extern App app;
extern component
    levelTwoWindowSky,
    levelTwoWindowMoon,
    levelTwoWindowMountains,
    levelTwoWindowTreeShade,
    levelTwoWindowClouds,
    levelTwoWindowTrack,
    levelTwoWindowCharacter, 
    levelTwoWindowCharacterPosition, 
    levelTwoRotatingCoin, 
    levelTwoRotatingHeart,
    characterFramePosition,
    levelTwoWindowScoreText,
    levelTwoLifeScoreText, 
    levelTwoWindowHighScoreText,
    levelOneWindowScore,
    levelOneWindowHighScore,
    levelTwoDragon,
    ironThrone,
    initialInstructions,
    back;

extern Variables variables;
extern void drawLevelTwoTrackFunction(void);
extern void levelTwoTrackmotion(void);
extern void drawLevelTwoCoinsFunction(void);
extern void drawLevelTwoCoinsPopupFunction(void);
extern void drawBombandDragonFunction(void);
extern void collisionsLevelTwo(void);
extern void updateLevelTwoScore(void);
extern void updateLevelTwoLifeBonusPopupFunction(void);
extern void drawLevelTwoLifeText(void);
extern void drawLevelTwoLifeFunction(void);
extern void LevelTwoLifeTextCleanUp(void);
extern void updateHeartPosition(void);
extern void lifeatstakeaftereffect(void);
extern void drawLevelTwoHeartFunction(void);
extern void drawLevelTwoHeartPopupFunction(void);
