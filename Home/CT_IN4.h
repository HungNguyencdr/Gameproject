#ifndef CT_IN4_H_INCLUDED
#define CT_IN4_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include "Map_And_Background.h"

using namespace std;

struct CT_IN4
{
    int walking_Frame_I;
    int frame;
    const char * Walk_Right;
    const char * Walk_Left;
    CT_IN4() {};

};
void move_Jame_Event_1(CT_IN4 &nv,SDL_Texture *texture,SDL_Renderer*renderer,SDL_Rect VitriXuatHien_Rect)
{
    SDL_Event event;
    int bol=0;
    int trangThai=0;
    while(bol==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                bol=1;
            }
            else if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT && event.type==SDL_KEYDOWN)
            {
                rectPT318_5_jpg_ng.x +=1;
                rectPC1_png_ng.x+=10;
                if(rectPT318_5_jpg_ng.x>200){rectPT318_5_jpg_ng.x=200;}
                if(rectPC1_png_ng.x>300){rectPC1_png_ng.x=300;}
                texture=IMG_LoadTexture(renderer,PT3185);
                SDL_RenderCopy(renderer,texture,&rectPT318_5_jpg_ng,&rectPT318_5_jpg_DST);
                texture=IMG_LoadTexture(renderer,PC1);
                SDL_RenderCopy(renderer,texture,&rectPC1_png_ng,&rectPC1_png_DST);

                if(nv.walking_Frame_I>nv.frame-1)
                {
                    nv.walking_Frame_I=0;
                }
                SDL_Rect RectA1{nv.walking_Frame_I*122,0,122,272};
                texture=IMG_LoadTexture(renderer,nv.Walk_Right);
                SDL_RenderCopy(renderer,texture,&RectA1,&VitriXuatHien_Rect);

                if(nv.walking_Frame_I==0&&trangThai==0)
                {
                    SDL_Delay(400);
                    trangThai++;
                }
                SDL_RenderPresent(renderer);

                nv.walking_Frame_I++;
                SDL_RenderClear(renderer);
            }

            else if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT&&event.type==SDL_KEYUP)
            {
                rectPT318_5_jpg_ng.x +=1;
                rectPC1_png_ng.x+=10;
                if(rectPT318_5_jpg_ng.x>200){rectPT318_5_jpg_ng.x=200;}
                if(rectPC1_png_ng.x>300){rectPC1_png_ng.x=300;}

                texture=IMG_LoadTexture(renderer,PT3185);
                SDL_RenderCopy(renderer,texture,&rectPT318_5_jpg_ng,&rectPT318_5_jpg_DST);
                texture=IMG_LoadTexture(renderer,PC1);
                SDL_RenderCopy(renderer,texture,&rectPC1_png_ng,&rectPC1_png_DST);

                texture=IMG_LoadTexture(renderer,"image\\Jame\\Jame_2.png");

                SDL_RenderCopy(renderer,texture,NULL,&VitriXuatHien_Rect);
                SDL_RenderPresent(renderer);
                SDL_RenderClear(renderer);
                nv.walking_Frame_I=0;
                trangThai=0;
            }

            else if(event.key.keysym.scancode==SDL_SCANCODE_LEFT&&event.type==SDL_KEYUP)
            {
                rectPT318_5_jpg_ng.x -=1;
                rectPC1_png_ng.x-=10;
                if(rectPT318_5_jpg_ng.x<192){rectPT318_5_jpg_ng.x=192;}
                if(rectPC1_png_ng.x<0){rectPC1_png_ng.x=0;}

                texture=IMG_LoadTexture(renderer,PT3185);
                SDL_RenderCopy(renderer,texture,&rectPT318_5_jpg_ng,&rectPT318_5_jpg_DST);
                texture=IMG_LoadTexture(renderer,PC1);
                SDL_RenderCopy(renderer,texture,&rectPC1_png_ng,&rectPC1_png_DST);

                texture=IMG_LoadTexture(renderer,"image\\Jame\\Jame_1.png");

                SDL_RenderCopy(renderer,texture,NULL,&VitriXuatHien_Rect);
                SDL_RenderPresent(renderer);
                SDL_RenderClear(renderer);
                nv.walking_Frame_I=0;
                trangThai=0;
            }

            else if(event.key.keysym.scancode==SDL_SCANCODE_LEFT && event.type==SDL_KEYDOWN)
            {
                rectPT318_5_jpg_ng.x -=1;
                rectPC1_png_ng.x-=10;
                if(rectPT318_5_jpg_ng.x<192){rectPT318_5_jpg_ng.x=192;}
                if(rectPC1_png_ng.x<0){bol=1;}

                texture=IMG_LoadTexture(renderer,PT3185);
                SDL_RenderCopy(renderer,texture,&rectPT318_5_jpg_ng,&rectPT318_5_jpg_DST);
                texture=IMG_LoadTexture(renderer,PC1);
                SDL_RenderCopy(renderer,texture,&rectPC1_png_ng,&rectPC1_png_DST);

                if(nv.walking_Frame_I>nv.frame-1)
                {
                    nv.walking_Frame_I=0;
                }
                SDL_Rect RectA1{nv.walking_Frame_I*122,0,122,272};

                texture=IMG_LoadTexture(renderer,nv.Walk_Left);
                SDL_RenderCopy(renderer,texture,&RectA1,&VitriXuatHien_Rect);
                if(nv.walking_Frame_I==0&&trangThai==0)
                {
                    SDL_Delay(400);
                    trangThai++;
                }
                SDL_RenderPresent(renderer);

                nv.walking_Frame_I++;
                SDL_RenderClear(renderer);
            }



        }
    }
}






#endif // CT_IN4_H_INCLUDED
