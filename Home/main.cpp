#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <windows.h>
#include "start.h"
#include "CT_IN4.h"


using namespace std;

CT_IN4 Jame;
int main(int argc,char*argv[])
{
    FreeConsole();//AllocConsole();
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window*window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,0);
    SDL_Texture*texture=IMG_LoadTexture(renderer,"image\\start.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    // * //
    SDL_Event event;
    int bol=0;
    int frameI =0;
    while(bol==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                bol=1;
            }
            if(event.key.keysym.scancode==SDL_SCANCODE_Y)
            {
                bol=2;
            }

        }
        PressW(frameI,renderer,texture);
        SDL_RenderPresent(renderer);

    }
    if(bol==2)
    {
        while(countEYE<=24)
        {
            BlinkEye_PressW(countEYE,renderer,texture);
            SDL_RenderPresent(renderer);
        }
        countEYE=0;
        while(countEYE<=24)
        {
            BlinkEye_PressW(countEYE,renderer,texture);
            SDL_RenderPresent(renderer);
        }
        countEYE=0;
        SDL_Delay(700);
        while(countEYE<=24)
        {
            BlinkEye_PressW(countEYE,renderer,texture);
            SDL_RenderPresent(renderer);
        }
    }
    SDL_Delay(1000);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

// ------------------------------- xong doan dau ------------------------------ //
    texture =IMG_LoadTexture(renderer,"image\\PT318_5.jpg");
    SDL_Rect rectC{200,0,800,600};
    SDL_Rect rectD{0,0,800,600};
    SDL_RenderCopy(renderer,texture,&rectC,&rectD);

    texture=IMG_LoadTexture(renderer,"image\\PC1.png");
    SDL_Rect rectA{300,0,800,600};
    SDL_Rect rectB{0,100,800,600};
    SDL_RenderCopy(renderer,texture,&rectA,&rectB);


    texture=IMG_LoadTexture(renderer,"image\\Jame\\Jame_2.png");
    SDL_Rect rectddd{100,325,61,136};
    SDL_RenderCopy(renderer,texture,NULL,&rectddd);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);



    CT_IN4 Jame;
    Jame.walking_Frame_I=0;
    Jame.frame=8;
    Jame.Walk_Right="image\\Jame\\Jame_Move_Right.png";
    Jame.Walk_Left="image\\Jame\\Jame_Move_Left.png";
    SDL_Rect vitri{100,325,61,136};
    move_Jame_Event_1(Jame,texture,renderer,vitri);
//------------------------------xong_PC1_-------------------------------------- //
    texture = IMG_LoadTexture(renderer,"image\\PPPP.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);


//-------------------------------- End ---------------------------------------- //
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
