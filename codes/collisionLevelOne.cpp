#include "collisionLevelOne.h"

//funtion to detect collisions for levelOne
void collision()
{   
    
    for (int i = 0; i < 5; i++)
    {
        //detecting collision between character and coins
        if (SDL_HasIntersection(&characterFramePosition.rect, &levelOneWindowCoins[i].rect))
        {   
            //giving sound effects for collision
            Mix_VolumeChunk(levelOneCoingain, 40);
            Mix_PlayChannel(-1, levelOneCoingain, 0);
            //making the coins disappear after collision
            levelOneWindowCoins[i].rect.h = 0;
            levelOneWindowCoins[i].rect.w = 0;
            //making the coin getting effect appear after collision
            levelOneWindowCoinsEffect[i].rect.h = int(100);
            levelOneWindowCoinsEffect[i].rect.w = int(100);
            //adding the extra score after getting coin
            levelOneCurrentScore += 100;
            coineffectdelay();
        }
    }
    for (int i = 0; i < 3; i++)
    {
        //detecting collisions between character and obstacles
        if (SDL_HasIntersection(&characterFramePosition.rect, &levelOneWindowObstacle[i].rect))
        {   
            //sound effects after hitting an obstacle
            Mix_PlayChannel(-1, hitLevelOne, 0);
            //setting the character's texture to red
            SDL_SetTextureColorMod(levelOneWindowCharacter.tex, 255, 0, 0);
            //making the obstacles disappear after collision
            levelOneWindowObstacle[i].rect.h = 0;
            levelOneWindowObstacle[i].rect.w = 0;
            levelOneLifeAnimationSpeed[i] = 700;
            //making the life losing balloon appear after collision
            levelOneLifeLoss[i].rect.h = int(60);
            levelOneLifeLoss[i].rect.w = int(60);

            //after collision with obstacles character loses life
            if (lifeSize >= 1)
            {
                lifeSize--;
                break;
            }
        }
        
        //detecting collision between the tiger and obstacles
        if (SDL_HasIntersection(&tigerFramePosition.rect, &levelOneWindowObstacle[i].rect))
        {   
            //if tiger hits an obstacle it jumps
            tigerYposition -= 8;
        }
    }
}