#include "main.h"
int main(int argc, char *argv[])
{
    memset(&app, 0, sizeof(App));
    initSDL(); //in init.cpp file
    atexit(cleanup);
    Mix_PlayMusic(background, -1); // playing background music on start
    while (1)
    {
        prepareScene(); //in draw.cpp file
        doInput();      // in input.cpp file
        presentScene(); //in draw.cpp file
    }
    return 0;
}
