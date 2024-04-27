#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <windows.h>
#include "start.h"
#include "functions.h"
#include "inventory.h"
#include "minigame.h"
#include <SDL_mixer.h>
#include <fstream>
#include <cstring>
#include "messages.h"

using namespace std;

int main(int argc,char*argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* backgroundMusic = Mix_LoadMUS("sounds\\song1.mp3");
    Mix_Chunk* soundEffect = Mix_LoadWAV("sounds\\song2.mp3");
    Mix_Chunk *soundEffect_Walking=Mix_LoadWAV("sounds\\Walking_sound.mp3");
    READ_STORY();
    SDL_Window*window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,0);
    SDL_Texture*texture=IMG_LoadTexture(renderer,"image\\start.png");

    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    Mix_PlayMusic(backgroundMusic, -1);
    SDL_Delay(5000);
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
    LoadTexture(renderer,texture,"image\\texture\\PT2.jpg"); //////////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);

    LoadTexture(renderer,texture,"image\\texture\\PT3.jpg");///////////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);

    LoadTexture(renderer,texture,"image\\texture\\PT4.jpg");///////////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);

    LoadTexture(renderer,texture,"image\\texture\\PT5.jpg");//////////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);

    LoadQuestion(renderer,texture,"image\\Questions\\QS2.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    SDL_RenderClear(renderer);
    LoadTexture(renderer,texture,"image\\texture\\PT5.jpg");///////////////////////////////////////


    if(ctl==1)
    {
        all_messages_box[4].ring=1;
        LoadTexture(renderer,texture,"image\\texture\\PT5.jpg");//////////////////////////////////
        waitUntilKetPressed();

        unlocking(renderer,texture);

        SDL_RenderClear(renderer);
        LoadMessages(renderer);
        SDL_Delay(2000);
        Receive_Object(crowbar);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        waitUntilKetPressed();
    }
    else
        {
            LoadMessages(renderer);
            SDL_RenderClear(renderer);
        }
    LoadTexture(renderer,texture,"image\\texture\\PT6.jpg");//////////////////////////////
    waitUntilKetPressed();
    for(int i=0;i<3;i++)
    {
        LoadMessages(renderer);
    }
    LoadTexture(renderer,texture,"image\\texture\\PT7.jpg");///////////////////////////////////
    waitUntilKetPressed();
    for(int i=0;i<4;i++)
    {
        LoadMessages(renderer);
    }

    LoadTexture(renderer,texture,"image\\Texture\\PT8.jpg");//////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);
    LoadQuestion(renderer,texture,"image\\Questions\\QS3.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    waitUntilKetPressed();


    if(ctl==0)
    {
            all_messages_box[13].ring=1;
            all_messages_box[14].ring=1;
            all_messages_box[15].ring=1;
            all_messages_box[16].ring=1;
            LoadTexture(renderer,texture,"image\\Texture\\PT9.jpg");////////////////////////////////
            waitUntilKetPressed();
            LoadMessages(renderer);
            LoadMessages(renderer);
            LoadMessages(renderer);
            LoadMessages(renderer);

            LoadQuestion(renderer,texture,"image\\Questions\\QS4.png");
            waitUntilKetPressed();
            Yes_No(renderer,texture);
            Pick_Yes_No(ctl);
            if(ctl==1)
                {
                    all_messages_box[17].ring=1;
                    LoadMessages(renderer);
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
                    TTF_Quit();
                    CotTruyen.close();

                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyTexture(texture);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;

                    //end
                }
            else
                {
                    LoadMessages(renderer);
                    SDL_RenderClear(renderer);
                }

    }
    else
    {
        for(int i=0;i<=4;i++)
        {
            LoadMessages(renderer);
        }
    }
    LoadTexture(renderer,texture,"image\\Texture\\PT10.jpg");/////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);
    LoadTexture(renderer,texture,"image\\texture\\PT12.jpg");//////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);
    LoadTexture(renderer,texture,"image\\texture\\PT13.jpg");////////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);
    LoadQuestion(renderer,texture,"image\\Questions\\QS5.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    waitUntilKetPressed();
    if(ctl==1)
        {
            all_messages_box[21].ring=1;
            all_messages_box[22].ring=1;
            all_messages_box[23].ring=1;
            all_messages_box[24].ring=1;
           Mix_PauseMusic();
           LoadTexture(renderer,texture,"image\\texture\\PT15.jpg");/////////////////////////////
           waitUntilKetPressed();
           LoadMessages(renderer);
           LoadMessages(renderer);
           LoadMessages(renderer);
           LoadMessages(renderer);

           Mix_PlayChannel(-1, soundEffect, 0);
           Bad_End(renderer,texture);
           SDL_Delay(4000);

        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();
        TTF_Quit();
        CotTruyen.close();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
           // chet do vao nham phong :)))
        }
    else
        {
            for(int i=0;i<4;i++)
            {
                LoadMessages(renderer);
            }
            LoadTexture(renderer,texture,"image\\texture\\PT14.jpg");//////////////////////////////////////
            waitUntilKetPressed();
            LoadMessages(renderer);
            LoadMessages(renderer);
            LoadQuestion(renderer,texture,"image\\Questions\\QS6.png");
            waitUntilKetPressed();
            Yes_No(renderer,texture);
            Pick_Yes_No(ctl);
            if(ctl==1)
            {
                all_messages_box[27].ring=1;
                SDL_RenderClear(renderer);
                LoadTexture(renderer,texture,"image\\texture\\PT17.jpg");
                waitUntilKetPressed();
                LoadMessages(renderer);
                LoadQuestion(renderer,texture,"image\\Questions\\QS6.png");
                waitUntilKetPressed();
                Yes_No(renderer,texture);
                Pick_Yes_No(ctl);
                if(ctl==1)
                {
                    all_messages_box[28].ring=1;
                    SDL_RenderClear(renderer);
                    LoadTexture(renderer,texture,"image\\texture\\PT17.jpg");
                    waitUntilKetPressed();
                    LoadMessages(renderer);
                    LoadQuestion(renderer,texture,"image\\Questions\\QS6.png");
                    waitUntilKetPressed();
                    Yes_No(renderer,texture);
                    Pick_Yes_No(ctl);
                    if(ctl==1)
                    {
                        all_messages_box[29].ring=1;
                        SDL_RenderClear(renderer);
                        LoadTexture(renderer,texture,"image\\texture\\PT17.jpg");
                        waitUntilKetPressed();
                        LoadMessages(renderer);
                        LoadQuestion(renderer,texture,"image\\Questions\\QS6.png");
                        waitUntilKetPressed();
                        Yes_No(renderer,texture);
                        Pick_Yes_No(ctl);
                        if(ctl==1)
                        {
                            all_messages_box[30].ring=1;
                            SDL_RenderClear(renderer);
                            LoadTexture(renderer,texture,"image\\texture\\PT17.jpg");
                            waitUntilKetPressed();
                            LoadMessages(renderer);
                            Receive_Object(bullet);
                        }
                        else
                        {
                            for(int i=0;i<1;i++)
                            {
                                LoadMessages(renderer);
                            }
                        }
                    }
                    else
                    {
                        for(int i=0;i<2;i++)
                        {
                            LoadMessages(renderer);
                        }
                    }
                }
                else
                    {
                        for(int i=0;i<3;i++)
                        {
                            LoadMessages(renderer);
                        }
                    }
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    LoadMessages(renderer);
                }
            }
        }
    Find_New_Paper(renderer,texture);
    SDL_RenderClear(renderer);
    LoadTexture(renderer,texture,"image\\texture\\PT18.jpg");//////////////////////////////////
    waitUntilKetPressed();
    for(int i=0;i<6;i++)
    {
        LoadMessages(renderer);
    }
    Mix_PauseMusic();

    LoadMessages(renderer);
    LoadMessages(renderer);
    // minigame
    piece_of_paper a{"image\\minigame\\Paper1.png",0,0,0,0,0,0};
    piece_of_paper b{"image\\minigame\\Paper2.png",650,300,0,0,0,0};
    run_minigame(a,b,renderer,texture);
    waitUntilKetPressed();

    SDL_RenderClear(renderer);
    Mix_PlayChannel(-1,soundEffect_Walking,0);
    LoadTexture(renderer,texture,"image\\texture\\PT18.jpg");//////////////////////////////////////
    LoadMessages(renderer);
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
              TTF_Quit();
              CotTruyen.close();

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
                    TTF_Quit();
                    CotTruyen.close();

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
                    TTF_Quit();
                    CotTruyen.close();

                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyTexture(texture);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                    //end vi khong dem theo sung
            }
        }
    SDL_RenderClear(renderer);
    LoadTexture(renderer,texture,"image\\Texture\\PT20.jpg");/////////////////////////////////////////
    waitUntilKetPressed();

    LoadMessages(renderer);
    LoadMessages(renderer);

    LoadTexture(renderer,texture,"image\\texture\\PT19.jpg");/////////////////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);

    LoadTexture(renderer,texture,"image\\texture\\PT13.jpg");//////////////////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);

    LoadTexture(renderer,texture,"image\\texture\\PT14.jpg");/////////////////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);

    if(Object_exist(crowbar,inventory)==1)
        {
            all_messages_box[45].ring=1;
            all_messages_box[46].ring=1;

            LoadTexture(renderer,texture,"image\\texture\\PT22.jpg");
            waitUntilKetPressed();
            LoadMessages(renderer);

            LoadMessages(renderer);
            LoadMessage(renderer,texture,"image\\message\\MSPause.png");
        }
    else
        {
            LoadMessages(renderer);
            LoadMessages(renderer);
        }

    LoadTexture(renderer,texture,"image\\texture\\PT13.jpg");
    waitUntilKetPressed();
    if(Object_exist(crowbar,inventory)==0)
        {
            Mix_PauseMusic();

            all_messages_box[47].ring=1;
            all_messages_box[48].ring=1;
            all_messages_box[49].ring=1;
            all_messages_box[50].ring=1;
            all_messages_box[51].ring=1;
            all_messages_box[52].ring=1;
            LoadMessages(renderer);

            LoadMessages(renderer);

            LoadTexture(renderer,texture,"image\\Texture\\PT15.jpg");
            waitUntilKetPressed();
            LoadMessages(renderer);
            LoadMessages(renderer);
            LoadMessages(renderer);
            LoadMessages(renderer);

            Mix_PlayChannel(-1, soundEffect, 0);
            Bad_End(renderer,texture);
            SDL_Delay(4000);

            Mix_FreeMusic(backgroundMusic);
            Mix_FreeChunk(soundEffect);
            Mix_CloseAudio();
            Mix_Quit();
            TTF_Quit();
            CotTruyen.close();

            SDL_DestroyRenderer(renderer);
            SDL_DestroyTexture(texture);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 0;
           // chet do vao nham phong :)))
        }
    else
        {
            for(int i=0;i<6;i++)
            {
                LoadMessages(renderer);
            }
        }
    LoadTexture(renderer,texture,"image\\Texture\\PT6.jpg");////////////////////////////////
    waitUntilKetPressed();
    LoadTexture(renderer,texture,"image\\Texture\\PT4.jpg");////////////////////////////////
    waitUntilKetPressed();
    LoadMessages(renderer);
    SDL_RenderClear(renderer);
    LoadMessages(renderer);
    backgroundMusic = Mix_LoadMUS("sounds\\music2.mp3");
    Mix_PlayMusic(backgroundMusic, -1);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadTexture(renderer,texture,"image\\texture\\PT23.jpg");/////////////////////////////////////////////
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    LoadMessages(renderer);
    if(Object_exist(gun,inventory)==0)
        {
            //end do khong dem theo sung
            Mix_PauseMusic();
            Mix_PlayChannel(-1, soundEffect, 0);
            Bad_End(renderer,texture);
            SDL_Delay(4000);

            Mix_FreeMusic(backgroundMusic);
            Mix_FreeChunk(soundEffect);
            Mix_CloseAudio();
            Mix_Quit();
            TTF_Quit();
            CotTruyen.close();

            SDL_DestroyRenderer(renderer);
            SDL_DestroyTexture(texture);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 0;
        }
    LoadMessages(renderer);
    LoadQuestion(renderer,texture,"image\\Questions\\QS9.png");
    waitUntilKetPressed();
    Yes_No(renderer,texture);
    Pick_Yes_No(ctl);
    SDL_RenderClear(renderer);
    if(ctl==0)
    {
        //end do khong kiem tra bang dan
        all_messages_box[71].ring=1;
        all_messages_box[72].ring=1;
        all_messages_box[73].ring=1;
        LoadMessages(renderer);
        LoadMessages(renderer);
        LoadMessages(renderer);
        Mix_PauseMusic();
        Mix_PlayChannel(-1, soundEffect, 0);
        Bad_End(renderer,texture);
        SDL_Delay(4000);

        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();
        TTF_Quit();
        CotTruyen.close();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
    else
        {
            for(int i=0;i<3;i++)
            {
                LoadMessages(renderer);
            }
        }
    if(Object_exist(bullet,inventory)==0)
    {
        all_messages_box[74].ring=1;
        all_messages_box[75].ring=1;
        LoadMessages(renderer);
        LoadMessages(renderer);
        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();
        TTF_Quit();
        CotTruyen.close();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
        // end do khong co vien dan, open ending
    }
    else
    {
        for(int i=0;i<2;i++)
        {
            LoadMessages(renderer);
        }
        LoadMessages(renderer);
        LoadMessages(renderer);
        LoadMessages(renderer);
        LoadMessages(renderer);
        Mix_PauseMusic();
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        Happy_Ending(renderer,texture);
        waitUntilKetPressed();

        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();
        TTF_Quit();
        CotTruyen.close();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }

//-------------------------------- End ---------------------------------------- //
        Mix_FreeMusic(backgroundMusic);
        Mix_FreeChunk(soundEffect);
        Mix_CloseAudio();
        Mix_Quit();
        TTF_Quit();
        CotTruyen.close();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
}
