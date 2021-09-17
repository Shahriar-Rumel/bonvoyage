#include "initiateLevelTwoBombandDragon.h"
void BombandDragonLoad()
{   
    // bomb load 
    window.surface = IMG_Load("images/level2obstacles/dragonerr.png");

    if (!window.surface)
    {
        printf("bomb Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoBomb.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoBomb.tex)
    {
        printf("bomb Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoBomb.tex, NULL, NULL, &levelTwoBomb.rect.w, &levelTwoBomb.rect.h);

    levelTwoBomb.rect.w = (int)100;
    levelTwoBomb.rect.h = (int)100;
    levelTwoBomb.rect.x = (int)-150;
    levelTwoBomb.rect.y = (int)WINDOW_HEIGHT + 10;

    //dragon load 
    window.surface = IMG_Load("images/level2obstacles/dragon_sprite.png");

    if (!window.surface)
    {
        printf("dragonSprite Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoDragon.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelTwoDragon.tex)
    {
        printf("dragon Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoDragon.tex, NULL, NULL, &levelTwoDragonTexturewidth, &levelTwoDragonTextureheight);
    
    // variables for animating the dragonSprite 
    levelTwoDragonFramewidth = levelTwoDragonTexturewidth / 6 + 1;
    levelTwoDragonFrameheight = levelTwoDragonTextureheight / 2;
    levelTwoDragon.rect.w = levelTwoDragonFramewidth;
    levelTwoDragon.rect.h = levelTwoDragonFrameheight;
    levelTwoDragon.rect.x = 0;
    levelTwoDragon.rect.y = 0;
    levelTwoDragonPosition.rect.w = levelTwoDragonFramewidth;
    levelTwoDragonPosition.rect.h = levelTwoDragonFrameheight;
    levelTwoDragonPosition.rect.x = WINDOW_WIDTH + 10;
    levelTwoDragonPosition.rect.y = 30;
    

    //explosion load 
    window.surface = IMG_Load("images/level2obstacles/explosion.png");

    if (!window.surface)
    {
        printf("explosion Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoExplosion.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoExplosion.tex)
    {
        printf("explosion Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoExplosion.tex, NULL, NULL, &levelTwoExplosion.rect.w, &levelTwoExplosion.rect.h);

    levelTwoExplosion.rect.w = (int)0;
    levelTwoExplosion.rect.h = (int)0;
    levelTwoExplosion.rect.x = (int)WINDOW_WIDTH - 150;
    levelTwoExplosion.rect.y = (int)levelTwoDragonPosition.rect.y;
}
void BombandDragonCleanUp()
{
    SDL_DestroyTexture(levelTwoDragon.tex);
    SDL_DestroyTexture(levelTwoBomb.tex);
    SDL_DestroyTexture(levelTwoExplosion.tex);
    IMG_Quit();
}
