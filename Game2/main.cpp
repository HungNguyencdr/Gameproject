#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;
const char* Start[3]={
    "images\\start2.png",
    "images\\start3.png",
    "images\\start4.png"
};
const char*GamePlay[1]={
    "images\\BackGroundGame.png"
};
int main(int argc,char*argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window*window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1048, 524, SDL_WINDOW_SHOWN);
    SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,0);
    SDL_Texture *texture=IMG_LoadTexture(renderer,Start[0]);

    bool PC=0;
    bool GameIsRunning=0;
    SDL_Event event;
    while(GameIsRunning==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                GameIsRunning=1;
            }
            else if(event.type==SDL_MOUSEMOTION&&PC==0)
            {
                if(event.button.x>355&&event.button.x<703&&event.button.y>250&&event.button.y<300)
                {
                    texture=IMG_LoadTexture(renderer,Start[1]);
                }
                else if(event.button.x>355&&event.button.x<703&&event.button.y>322&&event.button.y<370)
                {
                    texture=IMG_LoadTexture(renderer,Start[2]);
                }
                else if(PC==0){texture=IMG_LoadTexture(renderer,Start[0]);}
            }
            else if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.x>355&&event.button.x<703&&event.button.y>250&&event.button.y<300)
                {
                    cerr<<"ok1";PC=1;
                    texture=IMG_LoadTexture(renderer,GamePlay[0]);
                    GameIsRunning=1;

                }
                else if(event.button.x>355&&event.button.x<703&&event.button.y>322&&event.button.y<370)
                {
                    cerr<<"ok2";PC=1;
                }
            }
        }

        SDL_RenderCopy(renderer,texture,NULL,NULL);
        SDL_RenderPresent(renderer);
    }
    GameIsRunning=0;
    while(GameIsRunning==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                GameIsRunning=1;
            }
            SDL_RenderCopy(renderer,texture,NULL,NULL);
            SDL_RenderPresent(renderer);
        }
    }



    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
