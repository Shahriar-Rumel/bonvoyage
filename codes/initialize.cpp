#include "initialize.h"

void initSDL(void)
{

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) < 0)
    {
        printf("video and timer: %s\n", SDL_GetError());
    }
    if (TTF_Init() < 0)
    {
        printf("Text: Can't laod %s\n", SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
        printf("image: %s\n", SDL_GetError());

    app.window = SDL_CreateWindow("Bon Voyage", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!app.window)
    {
        printf("window: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    app.rend = SDL_CreateRenderer(app.window, -1, render_flags);

    if (!app.rend)
    {
        printf("renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    //loading fonts and setting colors

    variables.font = TTF_OpenFont("Freshman.ttf", 30); // opening fonts
    variables.color = {234, 206, 9};
    variables.levelTwofont = TTF_OpenFont("Freshman.ttf", 30);
    variables.levelTwocolor = {234, 206, 9};

    //loading All musics

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    background = Mix_LoadMUS("audio/inception.mp3");
    got = Mix_LoadMUS("audio/got.mp3");
    whoWeWantToBe = Mix_LoadMUS("audio/potc.mp3");
    coingain = Mix_LoadWAV("audio/coingain.wav");
    explosionsound = Mix_LoadWAV("audio/explosionsound.wav");
    jumpsound = Mix_LoadWAV("audio/jump.wav");
    pointgainsound = Mix_LoadWAV("audio/pointgain.wav");
    hitLevelOne = Mix_LoadWAV("audio/hitLevelOne.wav");
    levelOneCoingain = Mix_LoadWAV("audio/levelOneCoinGain.wav");
    tigerRoar = Mix_LoadWAV("audio/tigerroar.wav");
    gameOver = Mix_LoadWAV("audio/gameOver.wav");
    click = Mix_LoadWAV("audio/click.wav");

    //Back button initialization

    window.surface = IMG_Load("images/backbutton.png");

    if (!window.surface)
    {
        printf("Back Button Error Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    back.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!back.tex)
    {
        printf("Back Button Error  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(back.tex, NULL, NULL, &back.rect.w, &back.rect.h);
    back.rect.w = (int)115;
    back.rect.h = (int)47;
    back.rect.x = (int)30;
    back.rect.y = (int)890;

    //function calls to load other game windows

    SDL_StartTextInput();

    welcomeWindowLoad();

    newgameWindowLoad();

    updatePlayerName();
    updateLevelTwoPlayerName();

    levelOneWindowLoad();

    levelTwoWindowLoad();

    levelOneCompletedLoad();
    levelTwoCompletedLoad();

    levelOneGameOverLoad();

    scoreboard();
    levelTwoScoreboard();

    LegendsWindowLoad();

    ControlsWindowLoad();
}
void cleanup(void) //cleaning up all the components at exit
{

    welcomeWindowCleanUp();

    newGameWindowCleanUp();

    levelOneWindowCleanUp();
    levelOneScoreCleanUp();
    levelTwoScoreCleanUp();
    levelOnePlayerNameCleanUp();
    levelOneScoreboardCleanUp();
    levelOneObstacleCleanUp();
    levelOneLifeLossCleanUp();
    levelOneLifeCleanUp();
    levelOneCoinsEffectCleanUp();
    levelOneCoinsCleanUp();
    levelOneGameOverCleanUp();
    levelTwoCompletedCleanUp();

    LegendsWindowCleanUp();
    levelTwoWindowCleanUp();
    levelTwoScoreboardCleanUp();
    controlsWindowCleanUp();

    SDL_DestroyRenderer(app.rend);
    SDL_DestroyWindow(app.window);
    SDL_DestroyTexture(back.tex);
    SDL_StopTextInput();
    TTF_CloseFont(variables.font);
    TTF_Quit();
    Mix_FreeMusic(background);
    Mix_FreeChunk(coingain);
    Mix_FreeChunk(explosionsound);
    Mix_FreeChunk(jumpsound);
    Mix_FreeChunk(pointgainsound);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
}
