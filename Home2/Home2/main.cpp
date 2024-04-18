#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <windows.h>
#include "start.h"
#include "functions.h"
#include "inventory.h"
#include "minigame.h"
#include <SDL_mixer.h>
using namespace std;
int main(int argc,char*argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* backgroundMusic = Mix_LoadMUS("sounds\\song1.mp3");
    Mix_Chunk* soundEffect = Mix_LoadWAV("sounds\\song2.mp3");
    Mix_Chunk *soundEffect_Walking=Mix_LoadWAV("sounds\\Walking_sound.mp3");
    SDL_Window*window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,0);
    SDL_Texture*texture=IMG_LoadTexture(renderer,"image\\start.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    Mix_PlayMusic(backgroundMusic, -1);
    SDL_Delay(10000);
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
        Mix_PauseMusic();
        backgroundMusic = Mix_LoadMUS("sounds\\music_background.mp3");
        Mix_PlayChannel(-1, soundEffect, 0);
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
bool GameIsRunning=0;
while(GameIsRunning==0)
    {
    Mix_ResumeMusic();
    Mix_PlayMusic(backgroundMusic, -1);
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
    arrow(renderer,texture);
    LoadQuestion(renderer,texture,"image\\Questions\\QS1.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    if(ctl==1){Receive_Object(gun);}
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    waitUntilKetPressed();
    LoadTexture(renderer,texture,"image\\texture\\PT2.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS2.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    waitUntilKetPressed();
    LoadTexture(renderer,texture,"image\\texture\\PT3.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS3.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    waitUntilKetPressed();
    LoadTexture(renderer,texture,"image\\texture\\PT4.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS4.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    LoadTexture(renderer,texture,"image\\texture\\PT5.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS5.png");
    waitUntilKetPressed();
    LoadQuestion(renderer,texture,"image\\Questions\\QS2.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    SDL_RenderClear(renderer);
    LoadTexture(renderer,texture,"image\\texture\\PT5.jpg");


    if(ctl==1)
    {
        LoadTexture(renderer,texture,"image\\texture\\PT5.jpg");
        waitUntilKetPressed();

        unlocking(renderer,texture);

        SDL_RenderClear(renderer);
        LoadMessage(renderer,texture,"image\\message\\MSn.png");
        SDL_Delay(2000);
        Receive_Object(crowbar);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        waitUntilKetPressed();
    }
    else {SDL_RenderClear(renderer);}
    LoadTexture(renderer,texture,"image\\texture\\PT6.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS6.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS7.png");
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
    waitUntilKetPressed();

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
                    SDL_RenderClear(renderer);
                    Mix_HaltChannel(-1);
                    Mix_PlayChannel(-1, soundEffect, 0);
                    End2_1(renderer,texture);
                    End2_2(renderer,texture);
                    SDL_Delay(3000);


                    Mix_FreeMusic(backgroundMusic);
                    Mix_FreeChunk(soundEffect);
                    Mix_CloseAudio();
                    Mix_Quit();

                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyTexture(texture);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;

                    //end
                }
            else
                {SDL_RenderClear(renderer);}

    }

    LoadTexture(renderer,texture,"image\\Texture\\PT10.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS12.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    waitUntilKetPressed();
    LoadTexture(renderer,texture,"image\\texture\\PT12.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS13.png");
    waitUntilKetPressed();

    LoadTexture(renderer,texture,"image\\texture\\PT13.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS14.png");//*
    waitUntilKetPressed();
    LoadQuestion(renderer,texture,"image\\Questions\\QS5.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    waitUntilKetPressed();
    if(ctl==1)
        {
           Mix_PauseMusic();
           LoadTexture(renderer,texture,"image\\texture\\PT15.jpg");
           waitUntilKetPressed();
           LoadMessage(renderer,texture,"image\\message\\MS15.png");
           waitUntilKetPressed();
           LoadMessage(renderer,texture,"image\\message\\MS15_1.png");
           waitUntilKetPressed();
           LoadMessage(renderer,texture,"image\\message\\MS15_2.png");
           waitUntilKetPressed();
           LoadMessage(renderer,texture,"image\\message\\MS15_3.png");
           waitUntilKetPressed();

           Mix_PlayChannel(-1, soundEffect, 0);
           Bad_End(renderer,texture);
           SDL_Delay(4000);

        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
           // chet do vao nham phong :)))
        }
    else
        {
            LoadTexture(renderer,texture,"image\\texture\\PT14.jpg");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS16.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS16_1.png");
            waitUntilKetPressed();
            LoadQuestion(renderer,texture,"image\\Questions\\QS6.png");
            waitUntilKetPressed();
            Yes_No(renderer,texture);
            Pick_Yes_No(ctl);
            if(ctl==1)
            {
                SDL_RenderClear(renderer);
                LoadTexture(renderer,texture,"image\\texture\\PT17.jpg");
                waitUntilKetPressed();
                LoadMessage(renderer,texture,"image\\message\\MS16_3.png");
                waitUntilKetPressed();
                LoadQuestion(renderer,texture,"image\\Questions\\QS6.png");
                waitUntilKetPressed();
                Yes_No(renderer,texture);
                Pick_Yes_No(ctl);
                if(ctl==1)
                {
                    SDL_RenderClear(renderer);
                    LoadTexture(renderer,texture,"image\\texture\\PT17.jpg");
                    waitUntilKetPressed();
                    LoadMessage(renderer,texture,"image\\message\\MS16_4.png");
                    waitUntilKetPressed();
                    LoadQuestion(renderer,texture,"image\\Questions\\QS6.png");
                    waitUntilKetPressed();
                    Yes_No(renderer,texture);
                    Pick_Yes_No(ctl);
                    if(ctl==1)
                    {
                        SDL_RenderClear(renderer);
                        LoadTexture(renderer,texture,"image\\texture\\PT17.jpg");
                        waitUntilKetPressed();
                        LoadMessage(renderer,texture,"image\\message\\MS16_5.png");
                        waitUntilKetPressed();
                        LoadQuestion(renderer,texture,"image\\Questions\\QS6.png");
                        waitUntilKetPressed();
                        Yes_No(renderer,texture);
                        Pick_Yes_No(ctl);
                        if(ctl==1)
                        {
                            SDL_RenderClear(renderer);
                            LoadTexture(renderer,texture,"image\\texture\\PT17.jpg");
                            waitUntilKetPressed();
                            LoadMessage(renderer,texture,"image\\message\\MS16_2.png");
                            waitUntilKetPressed();
                            Receive_Object(bullet);
                        }
                    }
                }
            }
        }
    SDL_RenderClear(renderer);
    LoadTexture(renderer,texture,"image\\texture\\PT18.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS17.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS17_1.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS17_2.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS17_3.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS17_4.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS17_5.png");
    Mix_PauseMusic();

    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS17_6.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS17_7.png");
    waitUntilKetPressed();
    // minigame
    piece_of_paper a{"image\\minigame\\Paper1.png",0,0,0,0,0,0};
    piece_of_paper b{"image\\minigame\\Paper2.png",650,300,0,0,0,0};
    run_minigame(a,b,renderer,texture);
    waitUntilKetPressed();

    SDL_RenderClear(renderer);
    Mix_PlayChannel(-1,soundEffect_Walking,0);
    LoadTexture(renderer,texture,"image\\texture\\PT18.jpg");// tieng buoc chan
    LoadMessage(renderer,texture,"image\\message\\MS18.png");
    while (Mix_Playing(-1)) {
    // Đợi cho đến khi âm thanh hiệu ứng kết thúc
}
    waitUntilKetPressed();

    LoadQuestion(renderer,texture,"image\\Questions\\QS7.png");
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    if(ctl==1)
        {
            Mix_PauseMusic();
            Mix_PlayChannel(-1, soundEffect, 0);
              Bad_End(renderer,texture);
              texture=IMG_LoadTexture(renderer,"image\\End1\\Skull50_1.png");
              SDL_RenderCopy(renderer,texture,NULL,NULL);
              SDL_RenderPresent(renderer);
              SDL_Delay(4000);
              Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
        }// end vi tien lai gan cua, bi sat nhan dam chet
    else
        {
            if(Object_exist(gun,inventory)==1)
            {
                LoadQuestion(renderer,texture,"image\\Questions\\Qs8.png");
                Pick_Yes_No(ctl);
                if(ctl==0)
                {
                    Mix_PauseMusic();
                    Mix_PlayChannel(-1, soundEffect, 0);
                    Bad_End(renderer,texture);
                    SDL_Delay(4000);
                    Mix_FreeMusic(backgroundMusic);
                    Mix_FreeChunk(soundEffect);
                    Mix_CloseAudio();
                    Mix_Quit();
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyTexture(texture);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                    //end vi khong cam sung len tu ve
                }
            }
            else
            {
                    Mix_PauseMusic();
                    Mix_PlayChannel(-1, soundEffect, 0);
                    SDL_RenderClear(renderer);
                    SDL_RenderPresent(renderer);
                    Bad_End(renderer,texture);
                    SDL_Delay(4000);
                    Mix_FreeMusic(backgroundMusic);
                    Mix_FreeChunk(soundEffect);
                    Mix_CloseAudio();
                    Mix_Quit();
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyTexture(texture);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                    //end vi khong dem theo sung
            }
        }
    SDL_RenderClear(renderer);
    LoadTexture(renderer,texture,"image\\Texture\\PT20.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MSPause.png");
    LoadMessage(renderer,texture,"image\\message\\MS19.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MSPause.png");
    LoadMessage(renderer,texture,"image\\message\\MS20.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS20_1.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MSPause.png");
    LoadTexture(renderer,texture,"image\\texture\\PT19.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS21.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MSPause.png");
    LoadTexture(renderer,texture,"image\\texture\\PT13.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\Texture\\MS21.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\texture\\MSPause.png");
    LoadTexture(renderer,texture,"image\\texture\\PT14.jpg");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\Message\\MS22.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MSPause.png");
    if(Object_exist(crowbar,inventory)==1)
        {
            LoadTexture(renderer,texture,"image\\texture\\PT22.jpg");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS22_1.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS22_2.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MSPause.png");
        }
    LoadTexture(renderer,texture,"image\\texture\\PT13.jpg");
    waitUntilKetPressed();
    if(Object_exist(crowbar,inventory)==0)
        {
            Mix_PauseMusic();

            LoadMessage(renderer,texture,"image\\message\\MS22_3.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MSPause.png");
            LoadMessage(renderer,texture,"image\\message\\MS22_4.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MSPause.png");
            LoadTexture(renderer,texture,"image\\texture\\PT15.jpg");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS15.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS15_1.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS15_2.png");
            waitUntilKetPressed();
            LoadMessage(renderer,texture,"image\\message\\MS15_3.png");
            waitUntilKetPressed();
            Mix_PlayChannel(-1, soundEffect, 0);
            Bad_End(renderer,texture);
            SDL_Delay(4000);

             Mix_FreeMusic(backgroundMusic);
            Mix_FreeChunk(soundEffect);
            Mix_CloseAudio();
            Mix_Quit();

            SDL_DestroyRenderer(renderer);
            SDL_DestroyTexture(texture);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 0;
           // chet do vao nham phong :)))
        }
    LoadTexture(renderer,texture,"image\\Texture\\PT6.jpg");
    waitUntilKetPressed();
    LoadTexture(renderer,texture,"image\\Texture\\PT4.jpg");
    waitUntilKetPressed();
            //mini game?
    LoadMessage(renderer,texture,"image\\message\\MS23.png");
    waitUntilKetPressed();
    SDL_RenderClear(renderer);
    LoadMessage(renderer,texture,"image\\message\\MS23_1.png");
    waitUntilKetPressed();
    backgroundMusic = Mix_LoadMUS("sounds\\music2.mp3");
    Mix_PlayMusic(backgroundMusic, -1);
    LoadMessage(renderer,texture,"image\\message\\MS24.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS25.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS26.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS27.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS28.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS29.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS30.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS31.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS32.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS33.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS34.png");
    waitUntilKetPressed();
    LoadTexture(renderer,texture,"image\\texture\\PT23.jpg");
    LoadMessage(renderer,texture,"image\\message\\MS35.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS36.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS37.png");
    waitUntilKetPressed();
    LoadMessage(renderer,texture,"image\\message\\MS38.png");
    waitUntilKetPressed();
    if(Object_exist(gun,inventory)==0)
        {
            Mix_PauseMusic();
            Mix_PlayChannel(-1, soundEffect, 0);
            //end do khong dem theo sung
            Bad_End(renderer,texture);
            SDL_Delay(4000);
            Mix_FreeMusic(backgroundMusic);
            Mix_FreeChunk(soundEffect);
            Mix_CloseAudio();
            Mix_Quit();

            SDL_DestroyRenderer(renderer);
            SDL_DestroyTexture(texture);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 0;
        }
    LoadMessage(renderer,texture,"image\\message\\MS39.png");
    waitUntilKetPressed();
    LoadQuestion(renderer,texture,"image\\Questions\\QS9.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    SDL_RenderClear(renderer);
    if(ctl==0)
    {


        LoadMessage(renderer,texture,"image\\message\\MS39_IF_NO.png");
        waitUntilKetPressed();
        LoadMessage(renderer,texture,"image\\message\\MS39_IF_NO2.png");
        waitUntilKetPressed();
        LoadMessage(renderer,texture,"image\\message\\MS39_IF_NO3.png");
        waitUntilKetPressed();Mix_PauseMusic();
        Mix_PlayChannel(-1, soundEffect, 0);
        Bad_End(renderer,texture);

        SDL_Delay(4000);

         Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
        //end do khong kiem tra bang dan
    }
    else if(Object_exist(bullet,inventory)==0)
    {
        LoadMessage(renderer,texture,"image\\message\\MSP_IF_YES_BULLET_0.png");
        waitUntilKetPressed();

        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
        // end do khong co vien dan, open ending
    }
    else
    {
        LoadMessage(renderer,texture,"image\\message\\MSP_IF_YES_BULLET_0.png");
        waitUntilKetPressed();
        LoadMessage(renderer,texture,"image\\message\\MSP_IF_YES_BULLET_1.png");
        waitUntilKetPressed();
        LoadMessage(renderer,texture,"image\\message\\MS39_IF_NO21.png");
        waitUntilKetPressed();
        LoadMessage(renderer,texture,"image\\message\\HappyEnding.png");
        waitUntilKetPressed();
        Mix_PauseMusic();
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        Happy_Ending(renderer,texture);
        waitUntilKetPressed();
        //minigame?
        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
}
//-------------------------------- End ---------------------------------------- //
        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;


}
