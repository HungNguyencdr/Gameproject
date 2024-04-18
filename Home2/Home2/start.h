#ifndef START_H_INCLUDED
#define START_H_INCLUDED
#include <SDL.h>
#include <vector>
#include <SDL_image.h>
#include <iostream>

using namespace std;
int frameI =0;
int countMHC=0;
int count0_1=0;
int countEYE=0;
const char*Eyes[25]=
{

    "image\\eye\\eyeClip1.png",
    "image\\eye\\eyeClip2.png",
    "image\\eye\\eyeClip3.png",
    "image\\eye\\eyeClip4.png",
    "image\\eye\\eyeClip5.png",
    "image\\eye\\eyeClip6.png",
    "image\\eye\\eyeClip7.png",
    "image\\eye\\eyeClip8.png",
    "image\\eye\\eyeClip9.png",
    "image\\eye\\eyeClip10.png",
    "image\\eye\\eyeClip11.png",
    "image\\eye\\eyeClip12.png",
    "image\\eye\\eyeClip13.png",
    "image\\eye\\eyeClip12.png",
    "image\\eye\\eyeClip11.png",
    "image\\eye\\eyeClip10.png",
    "image\\eye\\eyeClip9.png",
    "image\\eye\\eyeClip8.png",
    "image\\eye\\eyeClip7.png",
    "image\\eye\\eyeClip6.png",
    "image\\eye\\eyeClip5.png",
    "image\\eye\\eyeClip4.png",
    "image\\eye\\eyeClip3.png",
    "image\\eye\\eyeClip2.png",
    "image\\eye\\eyeClip1.png",

};
const char*eye2[13]=
{
    "image\\eyeTest\\mat1.jpg",
    "image\\eyeTest\\mat2.jpg",
    "image\\eyeTest\\mat3.jpg",
    "image\\eyeTest\\mat4.jpg",
    "image\\eyeTest\\mat5.jpg",
    "image\\eyeTest\\mat6.jpg",
    "image\\eyeTest\\mat7.jpg",
    "image\\eyeTest\\mat6.jpg",
    "image\\eyeTest\\mat5.jpg",
    "image\\eyeTest\\mat4.jpg",
    "image\\eyeTest\\mat3.jpg",
    "image\\eyeTest\\mat2.jpg",
    "image\\eyeTest\\mat1.jpg",

};
const char* Presses[13]=
{
    "image\\Press\\press1.png",
    "image\\Press\\press2.png",
    "image\\Press\\press3.png",
    "image\\Press\\press4.png",
    "image\\Press\\press5.png",
    "image\\Press\\press6.png",
    "image\\Press\\press7.png",
    "image\\Press\\press8.png",
    "image\\Press\\press9.png",
    "image\\Press\\press10.png",
    "image\\Press\\press11.png",
    "image\\Press\\press12.png",
    "image\\Press\\press13.png",
};
void Bad_End(SDL_Renderer *renderer,SDL_Texture*texture)
{
    const char* Skull_Cry[50]=
    {
      "image\\End1\\Skull1.png",
      "image\\End1\\Skull2.png",
      "image\\End1\\Skull3.png",
      "image\\End1\\Skull4.png",
      "image\\End1\\Skull5.png",
      "image\\End1\\Skull6.png",
      "image\\End1\\Skull7.png",
      "image\\End1\\Skull8.png",
      "image\\End1\\Skull9.png",
      "image\\End1\\Skull10.png",
      "image\\End1\\Skull11.png",
      "image\\End1\\Skull12.png",
      "image\\End1\\Skull13.png",
      "image\\End1\\Skull14.png",
      "image\\End1\\Skull15.png",
      "image\\End1\\Skull16.png",
      "image\\End1\\Skull17.png",
      "image\\End1\\Skull18.png",
      "image\\End1\\Skull19.png",
      "image\\End1\\Skull20.png",
      "image\\End1\\Skull21.png",
      "image\\End1\\Skull22.png",
      "image\\End1\\Skull23.png",
      "image\\End1\\Skull24.png",
      "image\\End1\\Skull25.png",
      "image\\End1\\Skull26.png",
      "image\\End1\\Skull27.png",
      "image\\End1\\Skull28.png",
      "image\\End1\\Skull29.png",
      "image\\End1\\Skull30.png",
      "image\\End1\\Skull31.png",
      "image\\End1\\Skull32.png",
      "image\\End1\\Skull33.png",
      "image\\End1\\Skull34.png",
      "image\\End1\\Skull35.png",
      "image\\End1\\Skull36.png",
      "image\\End1\\Skull37.png",
      "image\\End1\\Skull38.png",
      "image\\End1\\Skull39.png",
      "image\\End1\\Skull40.png",
      "image\\End1\\Skull41.png",
      "image\\End1\\Skull42.png",
      "image\\End1\\Skull43.png",
      "image\\End1\\Skull44.png",
      "image\\End1\\Skull45.png",
      "image\\End1\\Skull46.png",
      "image\\End1\\Skull47.png",
      "image\\End1\\Skull48.png",
      "image\\End1\\Skull49.png",
      "image\\End1\\Skull50.png",
    };
    bool GameIsEnding=0;
    SDL_Event event;
    int current_frame=0;
    while(GameIsEnding==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT){GameIsEnding=1;}
        }
        SDL_RenderClear(renderer);
        if(current_frame>49){GameIsEnding=1;}
        else{
        texture=IMG_LoadTexture(renderer,Skull_Cry[current_frame]);
        SDL_RenderCopy(renderer,texture,NULL,NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(40);
        current_frame++;}
    }
}
void End2_1(SDL_Renderer *renderer,SDL_Texture*texture)
{
    bool GameIsEnding=0;
    SDL_Event event;
    SDL_Rect rectA{0,0,0,0};
    texture=IMG_LoadTexture(renderer,"image\\End2\\End2_2.png");
    while(GameIsEnding==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT){GameIsEnding=1;}
        }
        if(rectA.w>=792&&rectA.h>=594){GameIsEnding=1;}
        rectA.w+=8;rectA.h+=6;
        SDL_RenderCopy(renderer,texture,&rectA,&rectA);
        SDL_RenderPresent(renderer);
        SDL_Delay(30);
    }
}
void End2_2(SDL_Renderer *renderer,SDL_Texture *texture)
{
    const char* End2[15]={

        "image\\End2\\End2_3.png",
        "image\\End2\\End2_4.png",
        "image\\End2\\End2_5.png",
        "image\\End2\\End2_6.png",
        "image\\End2\\End2_7.png",
        "image\\End2\\End2_8.png",
        "image\\End2\\End2_9.png",
        "image\\End2\\End2_10.png",
        "image\\End2\\End2_11.png",
        "image\\End2\\End2_12.png",
        "image\\End2\\End2_13.png",
        "image\\End2\\End2_14.png",
        "image\\End2\\End2_15.png",
        "image\\End2\\End2_16.png",
        "image\\End2\\End2_17.png",
    };
    bool GameIsEnding=0;
    SDL_Event event;
    SDL_Rect rectA{0,0,800,600};
    int current_frame=0;
    texture=IMG_LoadTexture(renderer,"image\\End2\\End2_2.png");
    while(GameIsEnding==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT){GameIsEnding=1;}
        }
        if(rectA.x<-100)
        {
            if(current_frame>14){GameIsEnding=1;}
            else
                {
                    texture=IMG_LoadTexture(renderer,End2[current_frame]);
                    SDL_RenderCopy(renderer,texture,NULL,NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(40);
                    current_frame++;
                }
        }
        else{
        rectA.x-=2 ;
        SDL_RenderCopy(renderer,texture,NULL,&rectA);
        SDL_RenderPresent(renderer);
        SDL_Delay(30);
        }
    }
}
void Happy_Ending(SDL_Renderer*renderer,SDL_Texture*texture)
{
    const char* Ending[18]={
        "image\\Happy_Ending\\E1.png",
        "image\\Happy_Ending\\E2.png",
        "image\\Happy_Ending\\E3.png",
        "image\\Happy_Ending\\E4.png",
        "image\\Happy_Ending\\E5.png",
        "image\\Happy_Ending\\E6.png",
        "image\\Happy_Ending\\E7.png",
        "image\\Happy_Ending\\E8.png",
        "image\\Happy_Ending\\E9.png",
        "image\\Happy_Ending\\E10.png",
        "image\\Happy_Ending\\E11.png",
        "image\\Happy_Ending\\E12.png",
        "image\\Happy_Ending\\E13.png",
        "image\\Happy_Ending\\E14.png",
        "image\\Happy_Ending\\E15.png",
        "image\\Happy_Ending\\E16.png",
        "image\\Happy_Ending\\E17.png",
        "image\\Happy_Ending\\E18.png",
    };
    bool GameIsEnding=0;
    SDL_Event event;
    int currentFrame=0;
    while(GameIsEnding==0)
    {
        while(SDL_PollEvent(&event))
              {
                 if(event.type==SDL_QUIT){GameIsEnding=1;}
              }
        if(currentFrame==18){GameIsEnding=1;}
        else
            {
                texture=IMG_LoadTexture(renderer,Ending[currentFrame]);
                SDL_RenderCopy(renderer,texture,NULL,NULL);
                SDL_RenderPresent(renderer);
                SDL_Delay(50);
                currentFrame++;
            }
    }
}
void startEye(SDL_Renderer*renderer,SDL_Texture*texture,const char* path)
{
    SDL_Rect rectB{0,0,305,184};
    texture=IMG_LoadTexture(renderer,path);
    SDL_RenderCopy(renderer,texture,NULL,&rectB);
}
void BlinkEye_PressW(int &frameI,SDL_Renderer*renderer,SDL_Texture*texture)
{
    SDL_Rect rectB{233,210,305,184};
    texture=IMG_LoadTexture(renderer,"image\\start.png");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    texture=IMG_LoadTexture(renderer,Eyes[frameI]);
    SDL_RenderCopy(renderer,texture,NULL,&rectB);
    frameI++;
}
void PressW(int &frameI,SDL_Renderer*renderer,SDL_Texture*texture)
{
    SDL_Rect rectB{560,559,232,39};
    if(frameI>12)
    {
        if(count0_1!=0)
        {
            texture=IMG_LoadTexture(renderer,"image\\start.png");
            SDL_RenderCopy(renderer,texture,NULL,NULL);
            texture=IMG_LoadTexture(renderer,"image\\Press\\press14.png");
            SDL_RenderCopy(renderer,texture,NULL,&rectB);
            count0_1=0;
            SDL_Delay(300);
        }
        else
        {
            texture=IMG_LoadTexture(renderer,"image\\start.png");
            SDL_RenderCopy(renderer,texture,NULL,NULL);
            texture=IMG_LoadTexture(renderer,"image\\Press\\press13.png");
            SDL_RenderCopy(renderer,texture,NULL,&rectB);
            count0_1=1;
            SDL_Delay(300);
        }
    }
    else
    {
        texture=IMG_LoadTexture(renderer,"image\\start.png");
        SDL_RenderCopy(renderer,texture,NULL,NULL);
        texture=IMG_LoadTexture(renderer,Presses[frameI]);
        SDL_RenderCopy(renderer,texture,NULL,&rectB);
        frameI++;
        SDL_Delay(150);
    }

}
void wordsPressToStart(SDL_Renderer*renderer,SDL_Texture*texture,const char* path)
{
    SDL_Rect rectB{100,100,232,39};
    texture=IMG_LoadTexture(renderer,path);
    SDL_RenderCopy(renderer,texture,NULL,&rectB);
}
void arrow(SDL_Renderer*renderer,SDL_Texture*texture)
{
    SDL_Rect rect{50,306,700,100};
    int timer=0;
    SDL_Event event;
    bool b=0;
    while(b==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.key.keysym.scancode==SDL_SCANCODE_SPACE)
                {
                    b=1;
                }
        }
        if(timer>3000000)
        {
           texture=IMG_LoadTexture(renderer,"image\\arrow.png");
           SDL_RenderCopy(renderer,texture,NULL,&rect);
           SDL_RenderPresent(renderer);

        }
        else{timer++;}
    }
}


#endif // START_H_INCLUDED

