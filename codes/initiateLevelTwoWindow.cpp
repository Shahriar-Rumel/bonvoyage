#include "initiateLevelTwoWindow.h"

void levelTwoWindowLoad(void)
{
    // levelTwoSky load

    window.surface = IMG_Load("images/leveltwo/new/sky.png");

    if (!window.surface)
    {
        printf("levelTwoSky Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowSky.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelTwoWindowSky.tex)
    {
        printf("levelTwoSky Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoWindowSky.tex, NULL, NULL, &levelTwoWindowSky.rect.w, &levelTwoWindowSky.rect.h);
    levelTwoWindowSky.rect.w = (int)WINDOW_WIDTH;
    levelTwoWindowSky.rect.h = (int)WINDOW_HEIGHT;
    levelTwoWindowSky.rect.x = (int)0;
    levelTwoWindowSky.rect.y = (int)0;

    // levelTwoMoon load

    window.surface = IMG_Load("images/leveltwo/new/final moon.png");

    if (!window.surface)
    {
        printf("levelTwoMoon Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowMoon.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelTwoWindowMoon.tex)
    {
        printf("levelTwoMoon Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoWindowMoon.tex, NULL, NULL, &levelTwoWindowMoon.rect.w, &levelTwoWindowMoon.rect.h);
    levelTwoWindowMoon.rect.w = (int)110;
    levelTwoWindowMoon.rect.h = (int)110;
    levelTwoWindowMoon.rect.x = WINDOW_WIDTH / 2;
    levelTwoWindowMoon.rect.y = 150;

    //levelTwoMountains load

    window.surface = IMG_Load("images/leveltwo/new/mountains.png");

    if (!window.surface)
    {
        printf("levelTwoMountains Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowMountains.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelTwoWindowMountains.tex)
    {
        printf("levelTwoMountains Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoWindowMountains.tex, NULL, NULL, &levelTwoWindowMountains.rect.w, &levelTwoWindowMountains.rect.h);
    levelTwoWindowMountains.rect.w = (int)WINDOW_WIDTH;
    levelTwoWindowMountains.rect.h = (int)650;
    levelTwoWindowMountains.rect.x = (int)0;
    levelTwoWindowMountains.rect.y = (int)220;

    // levelTwoTreeshade load

    window.surface = IMG_Load("images/leveltwo/new/tree.png");

    if (!window.surface)
    {
        printf("levelTwoTreeshade Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowTreeShade.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelTwoWindowTreeShade.tex)
    {
        printf("levelTwoTreeshade Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoWindowTreeShade.tex, NULL, NULL, &levelTwoWindowTreeShade.rect.w, &levelTwoWindowTreeShade.rect.h);
    levelTwoWindowTreeShade.rect.w = (int)WINDOW_WIDTH;
    levelTwoWindowTreeShade.rect.h = (int)380;
    levelTwoWindowTreeShade.rect.x = (int)0;
    levelTwoWindowTreeShade.rect.y = (int)385;

    // levelTwoClouds load
    window.surface = IMG_Load("images/leveltwo/new/cloudsfinal.png");

    if (!window.surface)
    {
        printf("levelTwoClouds Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowClouds.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelTwoWindowClouds.tex)
    {
        printf("levelTwoClouds Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoWindowClouds.tex, NULL, NULL, &levelTwoWindowClouds.rect.w, &levelTwoWindowClouds.rect.h);
    levelTwoWindowClouds.rect.w = (int)WINDOW_WIDTH - 200;
    levelTwoWindowClouds.rect.h = (int)226;
    levelTwoWindowClouds.rect.x = (int)0;
    levelTwoWindowClouds.rect.y = 50;

    //levelTwoWindowTrack load
    window.surface = IMG_Load("images/leveltwo/new/newnightTrack.png");

    if (!window.surface)
    {
        printf("levelTwoWindowTrack Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowTrack.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelTwoWindowTrack.tex)
    {
        printf("levelTwoWindowTrack Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoWindowTrack.tex, NULL, NULL, &levelTwoWindowTrack.rect.w, &levelTwoWindowTrack.rect.h);
    levelTwoWindowTrack.rect.w = (int)WINDOW_WIDTH;
    levelTwoWindowTrack.rect.h = (int)200;
    levelTwoWindowTrack.rect.x = (int)0;
    levelTwoWindowTrack.rect.y = (int)760;

    // levelTwoWindowCharacter load
    levelTwoWindowCharacter.surface = IMG_Load("images/level2obstacles/winterfellCharacter.png");

    if (!levelTwoWindowCharacter.surface)
    {
        printf("levelTwoWindowCharacter Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowCharacter.tex = SDL_CreateTextureFromSurface(app.rend, levelTwoWindowCharacter.surface);

    if (!levelTwoWindowCharacter.tex)
    {
        printf("levelTwoWindowCharacter Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoWindowCharacter.tex, NULL, NULL, &levelTwoCharacterTextureHeight, &levelTwoCharacterTextureWidth);

    levelTwoCharacterFrameWidth = levelTwoCharacterTextureWidth / 2;
    levelTwoCharacterFrameHeight = levelTwoCharacterTextureHeight / 2;
    levelTwoWindowCharacter.rect.w = levelTwoCharacterFrameWidth;
    levelTwoWindowCharacter.rect.h = levelTwoCharacterFrameHeight;
    levelTwoWindowCharacter.rect.x = 0;
    levelTwoWindowCharacter.rect.y = 0;
    levelTwoWindowCharacterPosition.rect.w = levelTwoCharacterFrameWidth;
    levelTwoWindowCharacterPosition.rect.h = levelTwoCharacterFrameHeight;
    levelTwoWindowCharacterPosition.rect.x = 30;
    levelTwoWindowCharacterPosition.rect.y = 720;
    float CHARACTER2_X_POS = (float)100;
    float CHARACTER2_Y_POS = (float)700;

    // levelTwoIronThrone load

    window.surface = IMG_Load("images/newcomponents/ironethrone.png");

    if (!window.surface)
    {
        printf("levelTwoIronThrone Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    ironThrone.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!ironThrone.tex)
    {
        printf("levelTwoIronThrone Texture Error %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(ironThrone.tex, NULL, NULL, &ironThrone.rect.w, &ironThrone.rect.h);
    ironThrone.rect.w = (int)254;
    ironThrone.rect.h = (int)289;
    ironThrone.rect.x = (int)thronePosition;
    ironThrone.rect.y = (int)300;

    LevelTwoTracksLoad();
    LevelTwoCoinsload();
    BombandDragonLoad();
    LevelTwoLifeLoad();
    updateLevelTwoScore();
}

void levelTwoWindowCleanUp()
{
    SDL_DestroyTexture(levelTwoWindowSky.tex);
    SDL_DestroyTexture(levelTwoWindowMoon.tex);
    SDL_DestroyTexture(levelTwoWindowMountains.tex);
    SDL_DestroyTexture(levelTwoWindowTreeShade.tex);
    SDL_DestroyTexture(levelTwoWindowClouds.tex);
    SDL_DestroyTexture(levelTwoWindowTrack.tex);
    SDL_FreeSurface(levelTwoWindowCharacter.surface);
    SDL_DestroyTexture(levelTwoWindowCharacter.tex);
    LevelTwoTracksCleanUp();
    LevelTwoCoinsCleanUp();
    LevelTwoCoinsPopCleanUp();
    BombandDragonCleanUp();
    HeartCleanUp();
    IMG_Quit();
}
