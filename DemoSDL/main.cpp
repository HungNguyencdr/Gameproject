#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Fuction.h"
#include "image_h.h"

using namespace std;

int main(int argc, char* argv[])
{
    //Khởi tạo môi trường đồ họa
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);
    SDL_Texture *texture=IMG_LoadTexture(renderer,"image\\BikiniBottom.jpg");
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    const int BIRD_CLIPS[][4] = {
    {0, 0, 182, 168},
    {181, 0, 182, 168},
    {364, 0, 182, 168},
    {547, 0, 182, 168},
    {728, 0, 182, 168},

    {0, 170, 182, 168},
    {181, 170, 182, 168},
    {364, 170, 182, 168},
    {547, 170, 182, 168},
    {728, 170, 182, 168},

    {0, 340, 182, 168},
    {181, 340, 182, 168},
    {364, 340, 182, 168},
    {547, 340, 182, 168},
};
    SDL_Rect rectA{0,0,182,168};
    SDL_Rect rectB{300,200,182,168};
    int BirdframeI=0;
    int bol=0;
    SDL_Event event;
    while(bol==0)
        {
            while(SDL_PollEvent(&event))
                {
                    if(event.type==SDL_QUIT){bol=1;}


                }
                if(BirdframeI>13){BirdframeI=0;}
                    SDL_Texture *texture=IMG_LoadTexture(renderer,"image\\BikiniBottom.jpg");
                    SDL_RenderCopy(renderer,texture,NULL,NULL);
                    rectA.x=BIRD_CLIPS[BirdframeI][0];
                    rectA.y=BIRD_CLIPS[BirdframeI][1];
                    texture=IMG_LoadTexture(renderer,"image\\birdClips.png");
                    SDL_RenderCopy(renderer,texture,&rectA,&rectB);
                    SDL_RenderPresent(renderer);
                    BirdframeI++;
        }


    SDL_DestroyTexture(texture);
    quitSDL(window, renderer);
    return 0;
}
