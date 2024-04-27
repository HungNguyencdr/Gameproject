#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <fstream>
#include <cstring>
#include <SDL_ttf.h>
#include <string>
#include "messages.h"
bool ctl=0;
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
void LoadTexture(SDL_Renderer *renderer,SDL_Texture *texture,const char* path)
{
    texture =IMG_LoadTexture(renderer,path);
    SDL_Rect rect{50,50,384,256};
    SDL_RenderCopy(renderer,texture,NULL,&rect);
    SDL_RenderPresent(renderer);
}
void LoadMessage(SDL_Renderer *renderer,SDL_Texture *texture,const char* path)
{
    texture =IMG_LoadTexture(renderer,path);
    SDL_Rect rect{434,50,316,256};
    SDL_RenderCopy(renderer,texture,NULL,&rect);
    SDL_RenderPresent(renderer);
}
void LoadQuestion(SDL_Renderer *renderer,SDL_Texture *texture,const char* path)
{
    texture =IMG_LoadTexture(renderer,path);
    SDL_Rect rect{50,306,700,100};
    SDL_RenderCopy(renderer,texture,NULL,&rect);
    SDL_RenderPresent(renderer);
}
void Pick_Yes_No(bool &ctl)
{
    SDL_Event event;
    int x,y;
    bool bn=0;
    while(bn==0)
        {
            while(SDL_PollEvent(&event))
                {
                    SDL_GetMouseState(&x,&y);
                    if(event.type==SDL_QUIT){bn=1;}
                    else if(event.type==SDL_MOUSEBUTTONUP&&x>50&&x<400&&y>=406&&y<=550)
                        {
                            ctl=1;bn=1;
                        }
                    else if(event.type==SDL_MOUSEBUTTONUP&&x>400&&x<750&&y>=406&&y<=550)
                        {
                            ctl=0;bn=1;
                        }
                }
        }
}
void Yes_No(SDL_Renderer *renderer,SDL_Texture *texture)
{
    texture=IMG_LoadTexture(renderer,"image\\Yes_No.png");
    SDL_Rect rect{50,406,700,144};
    SDL_RenderCopy(renderer,texture,NULL,&rect);
    SDL_RenderPresent(renderer);
}
void waitUntilKetPressed()
{
    SDL_Event event;
    bool bn=0;
    while(bn==0)
        {
            while(SDL_PollEvent(&event))
                {
                    if(event.type==SDL_QUIT){bn=1;}
                    if(event.key.keysym.scancode==SDL_SCANCODE_SPACE && event.type==SDL_KEYUP)
                    {
                        bn=1;
                    }
                }
        }
}
void Present_Clear_Renderer(SDL_Renderer*renderer)
{
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    SDL_DestroyRenderer(renderer);
}
ifstream CotTruyen("CotTruyen.txt");
void READ_STORY()
{

    if(!CotTruyen.is_open())
    {
        cerr<<"failed to open story file";
        return;
    }
    string line;

    while(getline(CotTruyen,line))
    {
        if(line.find("\/")!=string::npos)
        {
            messages_box x;
            char t=line[3];
            int u=line[0]-48;
            int result=int(t)-48;
            x.ring=result;

            for(int i=0;i<u;i++)
            {
               getline(CotTruyen,line);
               x.content.push_back(line);
           }
            all_messages_box.push_back(x);
        }
    }
}
int counter=0;
void LoadMessages(SDL_Renderer*renderer)
{
    TTF_Font* font = TTF_OpenFont("assets\\Roboto-Bold.ttf", 24);
    if(font==nullptr){cerr<<"error to up font";}
    SDL_Color textColor = { 255, 255, 255 };
    SDL_Rect rect{434,50,316,20};
    SDL_Rect rectPause{434,50,316,224};

        for(int i=0;i<all_messages_box[counter].content.size();i++)
        {
            string line=all_messages_box[counter].content[i];
            char*lineto=new char[line.length()+1];
            lineto[line.length()]='\0';
            strncpy(lineto, line.c_str(), line.length());
            SDL_Surface* surface=TTF_RenderUTF8_Blended(font, lineto, textColor);
            SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,surface);
            SDL_RenderCopy(renderer,texture,NULL,&rect);
            rect.y+=20;
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
            delete []lineto;
        }
        if(all_messages_box[counter].ring==1)
        {
            SDL_RenderPresent(renderer);
            waitUntilKeyPressed();
            SDL_Texture *texturePause=IMG_LoadTexture(renderer,"image\\message\\MSPause.png");
            SDL_RenderCopy(renderer,texturePause,NULL,&rectPause);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(texturePause);
        }
        else
        {
            SDL_Texture *texturePause=IMG_LoadTexture(renderer,"image\\message\\MSPause.png");
            SDL_RenderCopy(renderer,texturePause,NULL,&rectPause);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(texturePause);
        }

    counter++;
    TTF_CloseFont(font);
}

#endif // FUNCTIONS_H_INCLUDED
