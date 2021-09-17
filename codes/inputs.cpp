#include "inputs.h"

void doInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {

        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        //level one Key Events

        if (variables.levelOnePlayerName == 1 || variables.levelOne == 1)
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(playerName) > 1)
                {
                    //delteing player names character

                    playerName[strlen(playerName) - 1] = '\0';
                    updatePlayerName();
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && variables.levelOne == 1)
                {
                    space = 1;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
                {
                    //if player jumps up  color and position are toggled

                    levelOneCharacterYposition -= levelOneMoveSpeed * levelOneCharacterDeltatime + 400;
                    SDL_SetTextureColorMod(levelOneWindowCharacter.tex, 255, 255, 255);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
                {
                    //if player jumps down  color and position are toggled

                    levelOneCharacterYposition += levelOneMoveSpeed * levelOneCharacterDeltatime + 400;
                    SDL_SetTextureColorMod(levelOneWindowCharacter.tex, 255, 255, 255);
                }
            }
            else if (event.type == SDL_TEXTINPUT && variables.levelOnePlayerName == 1)
            {
                //Not allowing player to copy paste for username

                if (strlen(playerName) < 10 && !(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == ' ' || event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V')))
                {
                    strcat(playerName, event.text.text);
                    updatePlayerName();
                }
            }
        }

        if (event.type == SDL_KEYDOWN && variables.levelTwoPlayerName == 1)
        {
            if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(levelTwoPlayerName) > 1)
            {
                //delteing player names character

                levelTwoPlayerName[strlen(levelTwoPlayerName) - 1] = '\0';
                updateLevelTwoPlayerName();
            }
        }
        if (event.type == SDL_TEXTINPUT && variables.levelTwoPlayerName == 1)
        {
            //Not allowing player to copy paste for username

            if (strlen(levelTwoPlayerName) < 10 && !(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == ' ' || event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V')))
            {
                strcat(levelTwoPlayerName, event.text.text);
                updateLevelTwoPlayerName();
            }
        }
        if (variables.levelTwo == 1) // level Two Key Events
        {

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
                {
                    isspaceclicked = 1;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    leftbuttonclicked = 0;
                    rightbuttonclicked = 1;
                    if (xPosLevelTwoCharacter < WINDOW_WIDTH - 300)
                    {
                        xPosLevelTwoCharacter += moveSpeed * characterTwoDeltatime;
                    }
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    leftbuttonclicked = 1;
                    rightbuttonclicked = 0;
                    xPosLevelTwoCharacter -= moveSpeed * characterTwoDeltatime;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
                {
                    // handling the collision between invisible borders & the character and implementing the jumping effect of the character

                    SDL_bool collisionBetweenCharacterandInvisibleBorderOne = SDL_HasIntersection(&levelTwoInvisibleBorder[0].rect, &levelTwoWindowCharacterPosition.rect);
                    SDL_bool collisionBetweenCharacterandInvisibleBorderTwo = SDL_HasIntersection(&levelTwoInvisibleBorder[1].rect, &levelTwoWindowCharacterPosition.rect);

                    if (collisionBetweenCharacterandInvisibleBorderOne)
                    {
                        yPosLevelTwoCharacter += 5;
                    }
                    else if (collisionBetweenCharacterandInvisibleBorderTwo)
                    {
                        yPosLevelTwoCharacter += 5;
                    }
                    else if (yPosLevelTwoCharacter > 250)
                    {
                        isUpPressed = 1;
                        yPosLevelTwoCharacter -= 70;
                    }
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
                {
                    isDownPressed = 1;
                }
            }
        }
    }

    // mouse events for all levels

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        if (variables.gameWindowBegin == 1 && (mousex >= welcomeWindowNewgameButton.rect.x && mousex <= (welcomeWindowNewgameButton.rect.x + welcomeWindowNewgameButton.rect.w) && mousey >= welcomeWindowNewgameButton.rect.y && mousey <= (welcomeWindowNewgameButton.rect.y + welcomeWindowNewgameButton.rect.h)))
        {
            variables.chooseLevel = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.legendsWindow = 0;
            variables.newLevelTwoScore = 0;
            variables.controlsWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }
        if (variables.gameWindowBegin == 1 && (mousex >= welcomeWindowControlsButton.rect.x && mousex <= (welcomeWindowControlsButton.rect.x + welcomeWindowControlsButton.rect.w) && mousey >= welcomeWindowControlsButton.rect.y && mousey <= (welcomeWindowControlsButton.rect.y + welcomeWindowControlsButton.rect.h)))
        {
            variables.controlsWindow = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.legendsWindow = 0;
            variables.newLevelTwoScore = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }
        if (variables.chooseLevel == 1 && (mousex >= newgameWindowlevelOneButton.rect.x && mousex <= (newgameWindowlevelOneButton.rect.x + newgameWindowlevelOneButton.rect.w) && mousey >= newgameWindowlevelOneButton.rect.y && mousey <= (newgameWindowlevelOneButton.rect.y + newgameWindowlevelOneButton.rect.h)))
        {
            variables.levelOnePlayerName = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.legendsWindow = 0;
            variables.newLevelTwoScore = 0;
            variables.controlsWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }

        if (variables.chooseLevel == 1 && (mousex >= newgameWindowlevelTwoButton.rect.x && mousex <= (newgameWindowlevelTwoButton.rect.x + newgameWindowlevelTwoButton.rect.w) && mousey >= newgameWindowlevelTwoButton.rect.y && mousey <= (newgameWindowlevelTwoButton.rect.y + newgameWindowlevelTwoButton.rect.h)))
        {
            variables.levelTwoPlayerName = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.legendsWindow = 0;
            variables.newLevelTwoScore = 0;
            variables.controlsWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }

        if (strlen(playerName) > 1 && variables.levelOnePlayerName == 1 && (mousex >= enterButton.rect.x && mousex <= (enterButton.rect.x + enterButton.rect.w) && mousey >= enterButton.rect.y && mousey <= (enterButton.rect.y + enterButton.rect.h)))
        {
            variables.levelOne = 1;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 1;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.legendsWindow = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 0;
            variables.controlsWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_VolumeMusic(30); //adjusting volume
            Mix_PlayMusic(whoWeWantToBe, 0);
            Mix_PlayChannel(-1, click, 0);
        }

        if (strlen(levelTwoPlayerName) > 1 && variables.levelTwoPlayerName == 1 && (mousex >= levelTwoEnterButton.rect.x && mousex <= (levelTwoEnterButton.rect.x + levelTwoEnterButton.rect.w) && mousey >= levelTwoEnterButton.rect.y && mousey <= (levelTwoEnterButton.rect.y + levelTwoEnterButton.rect.h)))
        {
            variables.levelTwo = 1;
            variables.levelOne = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.legendsWindow = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 1;
            variables.controlsWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayMusic(got, 0);
            Mix_PlayChannel(-1, click, 0);
        }

        if (variables.gameWindowBegin == 1 && (mousex >= welcomeWindowLegendsButton.rect.x && mousex <= (welcomeWindowLegendsButton.rect.x + welcomeWindowLegendsButton.rect.w) && mousey >= welcomeWindowLegendsButton.rect.y && mousey <= (welcomeWindowLegendsButton.rect.y + welcomeWindowLegendsButton.rect.h)))
        {
            variables.legendsWindow = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 0;
            variables.controlsWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }
        if (variables.legendsWindow == 1 && (mousex >= newgameWindowlevelOneLegendsButton.rect.x && mousex <= (newgameWindowlevelOneLegendsButton.rect.x + newgameWindowlevelOneLegendsButton.rect.w) && mousey >= newgameWindowlevelOneLegendsButton.rect.y && mousey <= (newgameWindowlevelOneLegendsButton.rect.y + newgameWindowlevelOneLegendsButton.rect.h)))
        {
            variables.ScoreBoard = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.legendsWindow = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 0;
            variables.controlsWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }

        if (variables.legendsWindow == 1 && (mousex >= newgameWindowlevelTwoLegendsButton.rect.x && mousex <= (newgameWindowlevelTwoLegendsButton.rect.x + newgameWindowlevelTwoLegendsButton.rect.w) && mousey >= newgameWindowlevelTwoLegendsButton.rect.y && mousey <= (newgameWindowlevelTwoLegendsButton.rect.y + newgameWindowlevelTwoLegendsButton.rect.h)))
        {
            variables.levelTwoScoreBoard = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.legendsWindow = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 0;
            variables.controlsWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }

        if (variables.gameWindowBegin == 1 && (mousex >= welcomeWindowExitButton.rect.x && mousex <= (welcomeWindowExitButton.rect.x + welcomeWindowExitButton.rect.w) && mousey >= welcomeWindowExitButton.rect.y && mousey <= (welcomeWindowExitButton.rect.y + welcomeWindowExitButton.rect.h)))
        {
            exit(0);
        }
        if (mousex >= back.rect.x && mousex <= (back.rect.x + back.rect.w) && mousey >= back.rect.y && mousey <= (back.rect.y + back.rect.h))
        {

            if (variables.levelOneCompleted == 1 || variables.levelTwoCompleted == 1 || variables.levelOne == 1 || variables.levelTwo == 1 || variables.levelTwoGameOver == 1 || variables.levelOnegameOver == 1)
            {
                Mix_PlayMusic(background, -1);
            }
            //if player wants to go back reseting the windows

            resetAll();
        }
    }

    // Hover Effects for Buttons

    if (variables.gameWindowBegin == 1 && (mousex >= welcomeWindowNewgameButton.rect.x && mousex <= (welcomeWindowNewgameButton.rect.x + welcomeWindowNewgameButton.rect.w) && mousey >= welcomeWindowNewgameButton.rect.y && mousey <= (welcomeWindowNewgameButton.rect.y + welcomeWindowNewgameButton.rect.h)))
    {
        SDL_SetTextureColorMod(welcomeWindowNewgameButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(welcomeWindowNewgameButton.tex, 255, 255, 255);

    if (variables.gameWindowBegin == 1 && (mousex >= welcomeWindowControlsButton.rect.x && mousex <= (welcomeWindowControlsButton.rect.x + welcomeWindowControlsButton.rect.w) && mousey >= welcomeWindowControlsButton.rect.y && mousey <= (welcomeWindowControlsButton.rect.y + welcomeWindowControlsButton.rect.h)))
    {
        SDL_SetTextureColorMod(welcomeWindowControlsButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(welcomeWindowControlsButton.tex, 255, 255, 255);

    if (variables.chooseLevel == 1 && (mousex >= newgameWindowlevelOneButton.rect.x && mousex <= (newgameWindowlevelOneButton.rect.x + newgameWindowlevelOneButton.rect.w) && mousey >= newgameWindowlevelOneButton.rect.y && mousey <= (newgameWindowlevelOneButton.rect.y + newgameWindowlevelOneButton.rect.h)))
    {
        SDL_SetTextureColorMod(newgameWindowlevelOneButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(newgameWindowlevelOneButton.tex, 255, 255, 255);

    if (variables.chooseLevel == 1 && (mousex >= newgameWindowlevelTwoButton.rect.x && mousex <= (newgameWindowlevelTwoButton.rect.x + newgameWindowlevelTwoButton.rect.w) && mousey >= newgameWindowlevelTwoButton.rect.y && mousey <= (newgameWindowlevelTwoButton.rect.y + newgameWindowlevelTwoButton.rect.h)))
    {
        SDL_SetTextureColorMod(newgameWindowlevelTwoButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(newgameWindowlevelTwoButton.tex, 255, 255, 255);

    if (strlen(playerName) > 1 && variables.levelOnePlayerName == 1 && (mousex >= enterButton.rect.x && mousex <= (enterButton.rect.x + enterButton.rect.w) && mousey >= enterButton.rect.y && mousey <= (enterButton.rect.y + enterButton.rect.h)))
    {
        SDL_SetTextureColorMod(enterButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(enterButton.tex, 255, 255, 255);

    if (strlen(levelTwoPlayerName) > 1 && variables.levelTwoPlayerName == 1 && (mousex >= levelTwoEnterButton.rect.x && mousex <= (levelTwoEnterButton.rect.x + levelTwoEnterButton.rect.w) && mousey >= levelTwoEnterButton.rect.y && mousey <= (levelTwoEnterButton.rect.y + levelTwoEnterButton.rect.h)))
    {
        SDL_SetTextureColorMod(levelTwoEnterButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(levelTwoEnterButton.tex, 255, 255, 255);

    if (variables.gameWindowBegin == 1 && (mousex >= welcomeWindowLegendsButton.rect.x && mousex <= (welcomeWindowLegendsButton.rect.x + welcomeWindowLegendsButton.rect.w) && mousey >= welcomeWindowLegendsButton.rect.y && mousey <= (welcomeWindowLegendsButton.rect.y + welcomeWindowLegendsButton.rect.h)))
    {
        SDL_SetTextureColorMod(welcomeWindowLegendsButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(welcomeWindowLegendsButton.tex, 255, 255, 255);
    if (variables.legendsWindow == 1 && (mousex >= newgameWindowlevelOneLegendsButton.rect.x && mousex <= (newgameWindowlevelOneLegendsButton.rect.x + newgameWindowlevelOneLegendsButton.rect.w) && mousey >= newgameWindowlevelOneLegendsButton.rect.y && mousey <= (newgameWindowlevelOneLegendsButton.rect.y + newgameWindowlevelOneLegendsButton.rect.h)))
    {
        SDL_SetTextureColorMod(newgameWindowlevelOneLegendsButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(newgameWindowlevelOneLegendsButton.tex, 255, 255, 255);
    if (variables.legendsWindow == 1 && (mousex >= newgameWindowlevelTwoLegendsButton.rect.x && mousex <= (newgameWindowlevelTwoLegendsButton.rect.x + newgameWindowlevelTwoLegendsButton.rect.w) && mousey >= newgameWindowlevelTwoLegendsButton.rect.y && mousey <= (newgameWindowlevelTwoLegendsButton.rect.y + newgameWindowlevelTwoLegendsButton.rect.h)))
    {
        SDL_SetTextureColorMod(newgameWindowlevelTwoLegendsButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(newgameWindowlevelTwoLegendsButton.tex, 255, 255, 255);

    if (variables.gameWindowBegin == 1 && (mousex >= welcomeWindowExitButton.rect.x && mousex <= (welcomeWindowExitButton.rect.x + welcomeWindowExitButton.rect.w) && mousey >= welcomeWindowExitButton.rect.y && mousey <= (welcomeWindowExitButton.rect.y + welcomeWindowExitButton.rect.h)))
    {
        SDL_SetTextureColorMod(welcomeWindowExitButton.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(welcomeWindowExitButton.tex, 255, 255, 255);
    if (mousex >= back.rect.x && mousex <= (back.rect.x + back.rect.w) && mousey >= back.rect.y && mousey <= (back.rect.y + back.rect.h))
    {
        SDL_SetTextureColorMod(back.tex, 255, 78, 255);
    }
    else
        SDL_SetTextureColorMod(back.tex, 255, 255, 255);
}
