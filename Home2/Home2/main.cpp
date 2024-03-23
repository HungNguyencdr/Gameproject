#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <windows.h>
#include "start.h"
#include "functions.h"
#include "inventory.h"
using namespace std;


int main(int argc,char*argv[])
{
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
    LoadTexture(renderer,texture,"image\\Texture\\PT1.jpg");

    SDL_Delay(3000);

    LoadMessage(renderer,texture,"image\\Message\\MS1.png");

    SDL_Delay(6000);

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    LoadTexture(renderer,texture,"image\\Texture\\PT_comment.jpg");

    SDL_Delay(1000);
    LoadMessage(renderer,texture,"image\\comment1.png");

    waitUntilKetPressed();
    LoadQuestion(renderer,texture,"image\\Questions\\QS1.png");

    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    if(ctl==1){Receive_Object(gun);}
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    LoadTexture(renderer,texture,"image\\texture\\PT2.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS2.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    LoadTexture(renderer,texture,"image\\texture\\PT3.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS3.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    LoadTexture(renderer,texture,"image\\texture\\PT4.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS4.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    LoadTexture(renderer,texture,"image\\texture\\PT5.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS5.png");
    waitUntilKetPressed();
    LoadQuestion(renderer,texture,"image\\Questions\\QS2.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    LoadMessage(renderer,texture,"image\\message\\MSPause.png");
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    if(ctl==1)
    {
        LoadTexture(renderer,texture,"image\\texture\\PT5.jpg");
        waitUntilKetPressed();
        LoadMessage(renderer,texture,"image\\message\\MSn.png");
        waitUntilKetPressed();
        Receive_Object(crowbar);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }
    else {SDL_RenderClear(renderer);}

    LoadTexture(renderer,texture,"image\\texture\\PT6.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS6.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MSPause.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS7.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MSPause.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS8.png");
    waitUntilKetPressed();
    LoadTexture(renderer,texture,"image\\texture\\PT7.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS9.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS9_1.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS9_2.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS9_3.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    LoadTexture(renderer,texture,"image\\Texture\\PT8.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS10.png");
    waitUntilKetPressed();
    LoadQuestion(renderer,texture,"image\\Questions\\QS3.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    waitUntilKetPressed();


    if(ctl==0)
    {
            waitUntilKetPressed();
            LoadTexture(renderer,texture,"image\\Texture\\PT9.jpg");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS11.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS11_1.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS11_2.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MSPause.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS11_3.png");
            waitUntilKetPressed();
            LoadQuestion(renderer,texture,"image\\Questions\\QS4.png");
            waitUntilKetPressed();
            Yes_No(renderer,texture);
            Pick_Yes_No(ctl);
            if(ctl==1)
                {
                    LoadMessage(renderer,texture,"image\\message\\MSEnd1.png");
                    waitUntilKetPressed();
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyTexture(texture);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                }
            else
                {SDL_RenderClear(renderer);}

    }

    LoadTexture(renderer,texture,"image\\Texture\\PT10.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS12.png");
    waitUntilKetPressed();













//-------------------------------- End ---------------------------------------- //
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
