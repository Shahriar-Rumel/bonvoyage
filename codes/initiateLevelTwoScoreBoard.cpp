#include "initiateLevelTwoScoreBoard.h"

void levelTwoScoreboard(void)
{
    // Legends Of Winterfell ScoreBoard Layouts

    window.surface = IMG_Load("./images/newcomponents/gotScoreboard.png");
    if (!window.surface)
    {
        printf("scoreBoard Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    levelTwoScoreBoard.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoScoreBoard.tex)
    {
        printf("levelTwoScoreBoard Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoScoreBoard.tex, NULL, NULL, &levelTwoScoreBoard.rect.w, &levelTwoScoreBoard.rect.h);
    levelTwoScoreBoard.rect.w = (int)952;
    levelTwoScoreBoard.rect.h = (int)529;
    levelTwoScoreBoard.rect.x = WINDOW_WIDTH / 2 - 476;
    levelTwoScoreBoard.rect.y = WINDOW_HEIGHT / 2 - 245;

    // Legends Of Winterfell ScoreBoard Player Name List

    for (int i = 0; i < 5; i++)
    {
        LoadScoreFile();
        if (showLevelTwoPlayerNameList[levelTwoScoreList[i]])
        {
            sprintf(levelTwoScoreBoardPlayerNameString[i], "%s", showLevelTwoPlayerNameList[levelTwoScoreList[i]]);
        }
        else
        {
            sprintf(levelTwoScoreBoardPlayerNameString[i], "%s", "000");
        }

        levelTwoScoreBoardPlayerName[i].surface = TTF_RenderText_Solid(variables.font, levelTwoScoreBoardPlayerNameString[i], variables.color);
        if (!levelTwoScoreBoardPlayerName[i].surface)
        {
            printf("playername Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelTwoScoreBoardPlayerName[i].tex = SDL_CreateTextureFromSurface(app.rend, levelTwoScoreBoardPlayerName[i].surface);
        if (!levelTwoScoreBoardPlayerName[i].tex)
        {
            printf("scoreText Texture Error: %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }
        SDL_QueryTexture(levelTwoScoreBoardPlayerName[i].tex, NULL, NULL, &levelTwoScoreBoardPlayerName[i].rect.w, &levelTwoScoreBoardPlayerName[i].rect.h);
        levelTwoScoreBoardPlayerName[i].rect.w = (int)levelTwoScoreBoardPlayerName[i].surface->w - 5;
        levelTwoScoreBoardPlayerName[i].rect.h = (int)levelTwoScoreBoardPlayerName[i].surface->h - 5;
        levelTwoScoreBoardPlayerName[i].rect.x = (int)590;
        levelTwoScoreBoardPlayerName[i].rect.y = (int)425 + i * 61;
        if (i == 3 || i == 4)

            levelTwoScoreBoardPlayerName[i].rect.y = (int)417 + i * 65;

        if (strlen(levelTwoScoreBoardPlayerNameString[i]) > 6)
        {
            levelTwoScoreBoardPlayerName[i].rect.x = (int)575;
        }

        // Legends Of Winterfell ScoreBoard Player Score List
        LoadScoreFile();
        if (levelTwoScoreList[i])
            sprintf(levelTwoScoreBoardPlayerScoreString[i], "%d", levelTwoScoreList[i]);
        else
            sprintf(levelTwoScoreBoardPlayerScoreString[i], "%d", 0);

        levelTwoScoreBoardPlayerScore[i].surface = TTF_RenderText_Solid(variables.font, levelTwoScoreBoardPlayerScoreString[i], variables.color);

        if (!levelTwoScoreBoardPlayerScore[i].surface)
        {
            printf("scorestring Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelTwoScoreBoardPlayerScore[i].tex = SDL_CreateTextureFromSurface(app.rend, levelTwoScoreBoardPlayerScore[i].surface);
        if (!levelTwoScoreBoardPlayerScore[i].tex)
        {
            printf("scoreText Texture Error: %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }
        SDL_QueryTexture(levelTwoScoreBoardPlayerScore[i].tex, NULL, NULL, &levelTwoScoreBoardPlayerScore[i].rect.w, &levelTwoScoreBoardPlayerScore[i].rect.h);
        levelTwoScoreBoardPlayerScore[i].rect.w = (int)levelTwoScoreBoardPlayerScore[i].surface->w - 10;
        levelTwoScoreBoardPlayerScore[i].rect.h = (int)levelTwoScoreBoardPlayerScore[i].surface->h - 10;
        levelTwoScoreBoardPlayerScore[i].rect.x = (int)880;
        levelTwoScoreBoardPlayerScore[i].rect.y = (int)430 + i * 61;
        if (i == 3 || i == 4)
            levelTwoScoreBoardPlayerScore[i].rect.y = (int)422 + i * 65;
    }
}
void levelTwoScoreboardCleanUp()
{
    SDL_DestroyTexture(levelTwoScoreBoard.tex);
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(levelTwoScoreBoardPlayerName[i].tex);
        SDL_DestroyTexture(levelTwoScoreBoardPlayerScore[i].tex);
        SDL_FreeSurface(levelTwoScoreBoardPlayerName[i].surface);
        SDL_FreeSurface(levelTwoScoreBoardPlayerScore[i].surface);
    }
}