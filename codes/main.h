#include "commonHeaders.h"

App app;
component
    //welcome window Components

    welcomeWindowSky,
    welcomeWindowBirds,
    welcomeWindowMountains,
    welcomeWindowTrees,
    welcomeWindowGameTitle,
    welcomeWindowNewgameButton,
    welcomeWindowControlsButton,
    welcomeWindowLegendsButton,
    welcomeWindowExitButton,

    //newgame Window Components

    newgameWindowlevelOneButton,
    newgameWindowlevelTwoButton,

    //level One(SundarBan) Components

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
    levelOneCompletedOverlay,
    levelOneCompletedMessage,
    levelOneCurzon, initialInstructions,
    levelOneWindowCoins[5],
    levelOneWindowObstacle[3],
    levelOneWindowLife[6],
    levelOneWindowCoinsEffect[5],
    levelOneLifeLoss[3],

    window,
    enterName,
    enterButton,
    playerNameBox,
    enterCommand,

    //Level Two Components

    levelTwoWindowSky,
    levelTwoWindowMoon,
    levelTwoWindowMountains,
    levelTwoWindowTreeShade,
    levelTwoWindowClouds,
    levelTwoWindowTrack,
    characterFramePosition,
    tigerFramePosition,
    levelTwoWindowScoreText,
    levelTwoWindowHighScoreText,
    levelTwoLifeScoreText,
    levelTwoWindowCoins[7],
    levelTwoWindowCharacter,
    levelTwoWindowCharacterPosition,
    levelTwoInvisibleBorder[2],
    levelTwoTrack[2],
    levelTwoRotatingCoin,
    levelTwoCoinPointPopUp,
    levelTwoBomb,
    levelTwoDragon,
    levelTwoDragonPosition,
    levelTwoExplosion,
    levelTwoHeart,
    ironThrone,
    levelTwoRotatingHeart,
    levelTwoLifeBonusPopUp,
    levelTwoLifeScoreDisplay,
    levelTwoHeartDisplay,
    levelTwoCompletedOverlay,
    levelTwoCompletedMessage,
    levelTwoEnterName,
    levelTwoEnterButton,
    levelTwoPlayerNameBox,
    levelTwoEnterCommand,

    //score Board Components for both levels

    scoreBoard,
    scoreBoardPlayerScore[5],
    scoreBoardPlayerName[5],
    levelTwoScoreBoard,
    levelTwoScoreBoardPlayerScore[5],
    levelTwoScoreBoardPlayerName[5],

    //Components for game Over (used for both levels)

    levelOneGameOverOverlay,
    levelOneGameOverMessage,

    //legends window Components

    newgameWindowlevelOneLegendsButton,
    newgameWindowlevelTwoLegendsButton,

    // control Window Components
    controlsList,

    //Back button
    back;

Variables variables;

extern void cleanup(void);
extern void initSDL(void);
extern void prepareScene(void);
extern void presentScene(void);
extern void doInput(void);
