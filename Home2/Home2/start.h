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

#endif // START_H_INCLUDED

