#include "initiateWelcomeWindow.h"

void welcomeWindowLoad(void)
{
    // Welcome Window Backgroud Sky

    window.surface = IMG_Load("./images/frontbackground/sky.png");
    if (!window.surface)
    {
        printf("Welcome window sky Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    welcomeWindowSky.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowSky.tex)
    {
        printf("Welcome window sky Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(welcomeWindowSky.tex, NULL, NULL, &welcomeWindowSky.rect.w, &welcomeWindowSky.rect.h);
    welcomeWindowSky.rect.w = (int)WINDOW_WIDTH;
    welcomeWindowSky.rect.h = (int)WINDOW_HEIGHT;
    welcomeWindowSky.rect.x = 0;
    welcomeWindowSky.rect.y = 0;

    // Welcome Window Backgroud Birds

    window.surface = IMG_Load("./images/frontbackground/birds.png");
    if (!window.surface)
    {
        printf("welcomeWindowBirds Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    welcomeWindowBirds.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowBirds.tex)
    {
        printf("welcomeWindowBirds Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(welcomeWindowBirds.tex, NULL, NULL, &welcomeWindowBirds.rect.w, &welcomeWindowBirds.rect.h);
    welcomeWindowBirds.rect.w = (int)WINDOW_WIDTH;
    welcomeWindowBirds.rect.h = (int)100;
    welcomeWindowBirds.rect.x = 0;
    welcomeWindowBirds.rect.y = 100;

    // Welcome Window Backgroud Mountains

    window.surface = IMG_Load("./images/frontbackground/mountains.png");
    if (!window.surface)
    {
        printf("welcomeWindowMountains Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    welcomeWindowMountains.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowMountains.tex)
    {
        printf("welcomeWindowMountains Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(welcomeWindowMountains.tex, NULL, NULL, &welcomeWindowMountains.rect.w, &welcomeWindowMountains.rect.h);
    welcomeWindowMountains.rect.w = (int)WINDOW_WIDTH;
    welcomeWindowMountains.rect.h = (int)800;
    welcomeWindowMountains.rect.x = 0;
    welcomeWindowMountains.rect.y = 200;

    // Welcome Window Backgroud Trees

    window.surface = IMG_Load("./images/frontbackground/frontTrees.png");
    if (!window.surface)
    {
        printf("welcomeWindowTrees Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    welcomeWindowTrees.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowTrees.tex)
    {
        printf("welcomeWindowTrees Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(welcomeWindowTrees.tex, NULL, NULL, &welcomeWindowTrees.rect.w, &welcomeWindowTrees.rect.h);
    welcomeWindowTrees.rect.w = (int)WINDOW_WIDTH + 50;
    welcomeWindowTrees.rect.h = (int)WINDOW_HEIGHT;
    welcomeWindowTrees.rect.x = 0;
    welcomeWindowTrees.rect.y = 0;

    // Welcome Window Game Logo

    window.surface = IMG_Load("images/bonvoyagelogo.png");

    if (!window.surface)
    {
        printf("welcomeWindowGameTitle Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    welcomeWindowGameTitle.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowGameTitle.tex)
    {
        printf("welcomeWindowGameTitle  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    SDL_QueryTexture(welcomeWindowGameTitle.tex, NULL, NULL, &welcomeWindowGameTitle.rect.w, &welcomeWindowGameTitle.rect.h);
    /* adjusting the poster for wide screen */
    welcomeWindowGameTitle.rect.w = (int)241;
    welcomeWindowGameTitle.rect.h = (int)181;
    welcomeWindowGameTitle.rect.x = (int)WINDOW_WIDTH / 2 - 120;
    welcomeWindowGameTitle.rect.y = (int)WINDOW_HEIGHT / 2 - 460;

    // Welcome Window Play  Button

    window.surface = IMG_Load("images/buttons/newPlayButton.png");

    if (!window.surface)
    {
        printf("welcomeWindowNewgameButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    welcomeWindowNewgameButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowNewgameButton.tex)
    {
        printf("welcomeWindowNewgameButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(welcomeWindowNewgameButton.tex, NULL, NULL, &welcomeWindowNewgameButton.rect.w, &welcomeWindowNewgameButton.rect.h);
    welcomeWindowNewgameButton.rect.w = (int)309;
    welcomeWindowNewgameButton.rect.h = (int)77;
    welcomeWindowNewgameButton.rect.x = (int)WINDOW_WIDTH / 2 + 180;
    welcomeWindowNewgameButton.rect.y = (int)WINDOW_HEIGHT / 2 - 220;

    // Welcome Window Legends  Button

    window.surface = IMG_Load("images/buttons/newLegendsButton.png");

    if (!window.surface)
    {
        printf("welcomeWindowLegendsButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    welcomeWindowLegendsButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowLegendsButton.tex)
    {
        printf("welcomeWindowLegendsButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(welcomeWindowLegendsButton.tex, NULL, NULL, &welcomeWindowLegendsButton.rect.w, &welcomeWindowLegendsButton.rect.h);
    welcomeWindowLegendsButton.rect.w = (int)309;
    welcomeWindowLegendsButton.rect.h = (int)77;
    welcomeWindowLegendsButton.rect.x = (int)welcomeWindowNewgameButton.rect.x;
    welcomeWindowLegendsButton.rect.y = (int)welcomeWindowNewgameButton.rect.y + 100;

    // Welcome Window Controls  Button

    window.surface = IMG_Load("images/buttons/newControlsButton.png");

    if (!window.surface)
    {
        printf("welcomeWindowControlsButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    welcomeWindowControlsButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowControlsButton.tex)
    {
        printf("welcomeWindowControlsButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(welcomeWindowControlsButton.tex, NULL, NULL, &welcomeWindowControlsButton.rect.w, &welcomeWindowControlsButton.rect.h);
    welcomeWindowControlsButton.rect.w = (int)309;
    welcomeWindowControlsButton.rect.h = (int)70;
    welcomeWindowControlsButton.rect.x = (int)welcomeWindowNewgameButton.rect.x;
    welcomeWindowControlsButton.rect.y = (int)welcomeWindowNewgameButton.rect.y + 200;

    //WelCome Window Exit Button

    window.surface = IMG_Load("images/buttons/newExitButton.png");

    if (!window.surface)
    {
        printf("welcomeWindowExitButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    welcomeWindowExitButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!welcomeWindowExitButton.tex)
    {
        printf("welcomeWindowExitButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(welcomeWindowExitButton.tex, NULL, NULL, &welcomeWindowExitButton.rect.w, &welcomeWindowExitButton.rect.h);
    welcomeWindowExitButton.rect.w = (int)309;
    welcomeWindowExitButton.rect.h = (int)70;
    welcomeWindowExitButton.rect.x = (int)welcomeWindowNewgameButton.rect.x;
    welcomeWindowExitButton.rect.y = (int)welcomeWindowNewgameButton.rect.y + 300;
}

void welcomeWindowCleanUp() // cleaning up components textures and surfaces
{

    SDL_DestroyTexture(welcomeWindowSky.tex);
    SDL_DestroyTexture(welcomeWindowBirds.tex);
    SDL_DestroyTexture(welcomeWindowMountains.tex);
    SDL_DestroyTexture(welcomeWindowTrees.tex);
    SDL_DestroyTexture(welcomeWindowGameTitle.tex);
    SDL_DestroyTexture(welcomeWindowNewgameButton.tex);
    SDL_DestroyTexture(welcomeWindowLegendsButton.tex);
    SDL_DestroyTexture(welcomeWindowControlsButton.tex);
    SDL_DestroyTexture(welcomeWindowExitButton.tex);
    IMG_Quit();
}