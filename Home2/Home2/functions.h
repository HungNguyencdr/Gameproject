#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
bool ctl=0;
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
    SDL_Rect rect{0,306,700,100};
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
                    else if(event.type==SDL_MOUSEBUTTONUP&&x>50&&x<400&&y>=406&&y<=550){ctl=1;bn=1;}
                    else if(event.type==SDL_MOUSEBUTTONUP&&x>400&&x<750&&y>=406&&y<=550){ctl=0;bn=1;}

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
                    if(event.key.keysym.scancode==SDL_SCANCODE_SPACE&&event.type==SDL_KEYUP)
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
}


#endif // FUNCTIONS_H_INCLUDED
