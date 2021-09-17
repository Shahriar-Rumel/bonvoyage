#include "drawlevelTwoTracks.h"


void JumpingEffectCharacter()
{    
    SDL_bool collisionBetweenCharacterandTrackOne =  SDL_HasIntersection(&levelTwoTrack[0].rect , &levelTwoWindowCharacterPosition.rect);
    SDL_bool collisionBetweenCharacterandTrackTwo =  SDL_HasIntersection(&levelTwoTrack[1].rect , &levelTwoWindowCharacterPosition.rect);
    SDL_bool collisionBetweenCharacterandInvisibleBorderOne =  SDL_HasIntersection(&levelTwoInvisibleBorder[0].rect , &levelTwoWindowCharacterPosition.rect);
    SDL_bool collisionBetweenCharacterandInvisibleBorderTwo =  SDL_HasIntersection(&levelTwoInvisibleBorder[1].rect , &levelTwoWindowCharacterPosition.rect);
    
    // keeping the character below the tracks
    if(collisionBetweenCharacterandInvisibleBorderOne)
    {
        yPosLevelTwoCharacter  +=5;
        isDownPressed = 0;
    }
    else if(collisionBetweenCharacterandInvisibleBorderTwo)
    {
        yPosLevelTwoCharacter   +=5;
        isDownPressed = 0;
    }
    // enabling the character walking on the tracks 
    else if(collisionBetweenCharacterandTrackOne && isUpPressed ==0)
    {
        isDownPressed = 0;
        yPosLevelTwoCharacter =  levelTwoTrack[0].rect.y - levelTwoWindowCharacter.rect.w -5 ;
    }
    else if(collisionBetweenCharacterandTrackTwo  && isUpPressed ==0)
    {
        isDownPressed = 0;
        yPosLevelTwoCharacter =  levelTwoTrack[1].rect.y - levelTwoWindowCharacter.rect.w - 5 ;
    }
    // if the character is not colliding with the tracks or invisible borders then it falls automatically 
    if((!collisionBetweenCharacterandTrackOne && !collisionBetweenCharacterandTrackTwo ) || abs(levelTwoTrack[1].rect.y  -  yPosLevelTwoCharacter - levelTwoWindowCharacter.rect.w)>=6 ||  abs(levelTwoTrack[0].rect.y  -  yPosLevelTwoCharacter - levelTwoWindowCharacter.rect.w)>=6 )
    {
        if (yPosLevelTwoCharacter != WINDOW_HEIGHT)
        {
            yPosLevelTwoCharacter += 10;
        }

        if (yPosLevelTwoCharacter >= WINDOW_HEIGHT - 250)
        {
            yPosLevelTwoCharacter = WINDOW_HEIGHT - 250;
        }
    }
    if(isUpPressed ==1)
    {
        isUpPressed =0;
    }

    if(isDownPressed==1 && yPosLevelTwoCharacter <= WINDOW_HEIGHT - 260  )
    {
        yPosLevelTwoCharacter  +=40;
        isDownPressed=0;
    }

}
void levelTwoTrackmotion()
{    
    levelOneCharacterPrevtime = levelOneCharacterCurrentime;  
    levelOneCharacterCurrentime = SDL_GetTicks();
    levelOneCharacterDeltatime = (levelOneCharacterCurrentime - levelOneCharacterPrevtime) / 280.0f;

    xPosLevelTwoTrack -= moveSpeed / 3 * levelOneCharacterDeltatime;
    xPosLevelTwoTrack2 -= moveSpeed / 3 * levelOneCharacterDeltatime;

        if (xPosLevelTwoTrack + levelTwoTrack[0].rect.w <=0)
        {

            xPosLevelTwoTrack = WINDOW_WIDTH;
            levelTwoTrack[0].rect.y = rand() % WINDOW_HEIGHT;
            updateCoinsPosition();
        }

        if (xPosLevelTwoTrack2 + levelTwoTrack[0].rect.w <=0)
        {

            xPosLevelTwoTrack2 = xPosLevelTwoTrack + 900 ;
            levelTwoTrack[1].rect.y = levelTwoTrack[0].rect.y -100;
            updateCoinsPosition2();
        }

        levelTwoInvisibleBorder[0].rect.y = levelTwoTrack[0].rect.y + levelTwoTrack[0].rect.h; 
        levelTwoInvisibleBorder[0].rect.x = xPosLevelTwoTrack;
        levelTwoInvisibleBorder[1].rect.y = levelTwoTrack[1].rect.y + levelTwoTrack[0].rect.h; 
        levelTwoInvisibleBorder[1].rect.x = xPosLevelTwoTrack2;

        levelTwoTrack[0].rect.x =xPosLevelTwoTrack;
        levelTwoTrack[1].rect.x =xPosLevelTwoTrack2;
        
        // coin positioning with respect to the tracks 
        levelTwoWindowCoins[0].rect.x = levelTwoTrack[0].rect.x + levelTwoWindowCoins[0].rect.y / 4;
        levelTwoWindowCoins[1].rect.x  =  levelTwoTrack[0].rect.x + levelTwoWindowCoins[1].rect.y / 4 + 300;
        levelTwoWindowCoins[2].rect.x = levelTwoTrack[0].rect.x - 200;
        levelTwoWindowCoins[3].rect.x = levelTwoTrack[0].rect.x  - 300;
        levelTwoWindowCoins[4].rect.x = levelTwoTrack[0].rect.x  + levelTwoTrack[0].rect.w + 200;
        
        levelTwoWindowCoins[5].rect.x = levelTwoTrack[1].rect.x + levelTwoWindowCoins[5].rect.y / 4;
        levelTwoWindowCoins[6].rect.x  =  levelTwoTrack[1].rect.x + levelTwoWindowCoins[6].rect.y / 4 + 300;
 
        JumpingEffectCharacter();
     
}
void drawLevelTwoTrackFunction()
{
    
    SDL_RenderCopy(app.rend, levelTwoTrack[0].tex, NULL, &levelTwoTrack[0].rect);
    levelTwoTrack[0].rect.x = xPosLevelTwoTrack + levelTwoTrack[0].rect.w ;
    SDL_RenderCopy(app.rend, levelTwoTrack[1].tex, NULL, &levelTwoTrack[1].rect);
    levelTwoTrack[1].rect.x = xPosLevelTwoTrack2 + levelTwoTrack[1].rect.w ;
}

