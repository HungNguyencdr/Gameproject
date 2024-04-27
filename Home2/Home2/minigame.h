#ifndef MINIGAME_H_INCLUDED
#define MINIGAME_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
using namespace std;
struct piece_of_paper
{
    const char* path;
    int imageX;
    int imageY;
    int initialMouseX=0;
    int initialMouseY=0;
    int initialImageX=0;
    int initialImageY=0;

void following_paper(piece_of_paper &a,SDL_Texture*texture,SDL_Renderer*renderer)
{
    texture=IMG_LoadTexture(renderer,a.path);
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    // Lưu trữ tọa độ chuột ban đầu
                    a.initialMouseX = event.button.x;
                    a.initialMouseY = event.button.y;
                    // Lưu trữ vị trí ban đầu của hình ảnh
                    a.initialImageX = a.imageX;
                    a.initialImageY = a.imageY;
                }
            }
            else if(event.type==SDL_MOUSEBUTTONUP)
                {
                    if(a.imageX>200&&a.imageX<300&&a.imageY>100&&a.imageY<200)
                        {
                            a.imageX=250;a.imageY=150;
                        }
                    quit=1;
                }
            else if (event.type == SDL_MOUSEMOTION) {
                if (event.motion.state & SDL_BUTTON_LMASK) {
                    // Tính toán sự chênh lệch giữa tọa độ chuột hiện tại và tọa độ ban đầu
                    int deltaX = event.motion.x - a.initialMouseX;
                    int deltaY = event.motion.y - a.initialMouseY;

                    // Cập nhật vị trí của hình ảnh
                    a.imageX = a.initialImageX + deltaX;
                    a.imageY = a.initialImageY + deltaY;
                }
            }
        }
        // Vẽ hình ảnh lên renderer
        SDL_Rect imageRect = { a.imageX, a.imageY, 150, 300 };
        SDL_RenderCopy(renderer, texture, NULL, &imageRect);
    }
}
};
void run_minigame(piece_of_paper &a,piece_of_paper &b,SDL_Renderer *renderer,SDL_Texture *texture)
{
    bool uu_tien_a=0;
    SDL_Texture *textureA=IMG_LoadTexture(renderer,a.path);
    SDL_Texture *textureB=IMG_LoadTexture(renderer,b.path);
    texture=IMG_LoadTexture(renderer,"image\\message\\minigame.png");

    SDL_Event event;
    bool minigame_is_running=0;
    while(minigame_is_running==0)
    {
        bool vi_tri_chuot_thuoc_vung_a=0;
        bool vi_tri_chuot_thuoc_vung_b=0;
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT){minigame_is_running=1;}
            vi_tri_chuot_thuoc_vung_a=(event.button.x<a.imageX+150&&event.button.x>a.imageX&&event.button.y>a.imageY&&event.button.y<a.imageY+300);
            vi_tri_chuot_thuoc_vung_b=(event.button.x<b.imageX+150&&event.button.x>b.imageX&&event.button.y>b.imageY&&event.button.y<b.imageY+300);
            if((vi_tri_chuot_thuoc_vung_a==1&&vi_tri_chuot_thuoc_vung_b==0)||uu_tien_a==1)
                {
                    if (event.type == SDL_MOUSEBUTTONDOWN)
                    {
                        uu_tien_a=1;
                        if (event.button.button == SDL_BUTTON_LEFT)
                        {
                            // Lưu trữ tọa độ chuột ban đầu
                            a.initialMouseX = event.button.x;
                            a.initialMouseY = event.button.y;
                            // Lưu trữ vị trí ban đầu của hình ảnh
                            a.initialImageX = a.imageX;
                            a.initialImageY = a.imageY;
                        }
                    }
                    if (event.type == SDL_MOUSEMOTION) {
                        if (event.motion.state & SDL_BUTTON_LMASK) {
                            // Tính toán sự chênh lệch giữa tọa độ chuột hiện tại và tọa độ ban đầu
                            int deltaX = event.motion.x - a.initialMouseX;
                            int deltaY = event.motion.y - a.initialMouseY;

                            // Cập nhật vị trí của hình ảnh
                            a.imageX = a.initialImageX + deltaX;
                            a.imageY = a.initialImageY + deltaY;
                            uu_tien_a=1;
                        }
                    }
                    if(event.type==SDL_MOUSEBUTTONUP)
                    {
                        uu_tien_a=0;
                        if(abs(a.imageX-b.imageX)<=160&&abs(a.imageY-b.imageY)<=10)
                            {
                                a.imageY=b.imageY;
                                a.imageX=b.imageX-150;
                                if(a.imageY<=230)
                                {
                                        texture=IMG_LoadTexture(renderer,"image\\message\\minigame1.png");
                                }
                                else
                                {
                                        texture=IMG_LoadTexture(renderer,"image\\message\\minigame2.png");
                                }
                                minigame_is_running=1;
                        }

                    }
                }
            else if((vi_tri_chuot_thuoc_vung_a==0&&vi_tri_chuot_thuoc_vung_b==1)||uu_tien_a==0)
                {
                        if (event.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (event.button.button == SDL_BUTTON_LEFT)
                            {
                                // Lưu trữ tọa độ chuột ban đầu
                                b.initialMouseX = event.button.x;
                                b.initialMouseY = event.button.y;
                                // Lưu trữ vị trí ban đầu của hình ảnh
                                b.initialImageX = b.imageX;
                                b.initialImageY = b.imageY;
                            }
                        }

                        if (event.type == SDL_MOUSEMOTION) {
                            if (event.motion.state & SDL_BUTTON_LMASK) {
                                // Tính toán sự chênh lệch giữa tọa độ chuột hiện tại và tọa độ ban đầu
                                int deltaX = event.motion.x - b.initialMouseX;
                                int deltaY = event.motion.y - b.initialMouseY;

                                // Cập nhật vị trí của hình ảnh
                                b.imageX = b.initialImageX + deltaX;
                                b.imageY = b.initialImageY + deltaY;
                            }
                        }
                        if(event.type==SDL_MOUSEBUTTONUP)
                            {
                                if(abs(a.imageX-b.imageX)<=160&&abs(a.imageY-b.imageY)<=10)
                                {
                                        a.imageY=b.imageY;
                                        a.imageX=b.imageX-150;
                                        if(a.imageY<=230)
                                        {
                                                texture=IMG_LoadTexture(renderer,"image\\message\\minigame1.png");
                                        }
                                        else
                                        {
                                                texture=IMG_LoadTexture(renderer,"image\\message\\minigame2.png");
                                        }
                                        minigame_is_running=1;
                                }
                            }
                }
        }
        SDL_Rect imageRectA = { a.imageX, a.imageY, 150, 300 };
        SDL_Rect imageRectB ={b.imageX,b.imageY,150,300};
        SDL_RenderCopy(renderer,texture,NULL,NULL);
        if(uu_tien_a==0){SDL_RenderCopy(renderer, textureA, NULL, &imageRectA);SDL_RenderCopy(renderer,textureB,NULL,&imageRectB);}
        else {SDL_RenderCopy(renderer,textureB,NULL,&imageRectB);SDL_RenderCopy(renderer, textureA, NULL, &imageRectA);}
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
    SDL_DestroyTexture(textureA);
    SDL_DestroyTexture(textureB);
}
void unlocking(SDL_Renderer *renderer,SDL_Texture *texture)
{
    const char* lock[6]={
        "image\\minigame\\Lock1.png",
        "image\\minigame\\Lock2.png",
        "image\\minigame\\Lock3.png",
        "image\\minigame\\Lock4.png",
        "image\\minigame\\Lock5.png",
        "image\\minigame\\Lock6.png"
    };
    bool WhileMiniGameIsRunning=0;
    SDL_Event event;

    while(WhileMiniGameIsRunning==0)
    {
        int i=rand()%6;
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT){WhileMiniGameIsRunning=1;}
            else if(event.type==SDL_KEYDOWN&&event.key.keysym.scancode==SDL_SCANCODE_SPACE&&i==0)
            {
                WhileMiniGameIsRunning=1;
            }
        }
        texture=IMG_LoadTexture(renderer,lock[i]);
        SDL_RenderCopy(renderer,texture,NULL,NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(200);
    }
}
void Find_New_Paper(SDL_Renderer*renderer,SDL_Texture *texture)
{
    const char* bookShell={"image\\minigame\\bookShell.png"};
    SDL_Event event;
    texture=IMG_LoadTexture(renderer,bookShell);
    const int x_IMAGE=943;
    const int y_IMAGE=1357;
    const int w=448;
    const int h=225;
    int current_image_x;
    int current_image_y;
    int x_MOUSE=0;
    int y_MOUSE=0;
    SDL_Rect rectA{0,0,800,600};
    bool whileMinigameIsRunning=0;

    while(whileMinigameIsRunning==0)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                whileMinigameIsRunning=1;
            }

            else if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.x > current_image_x && event.button.x < current_image_x + w && event.button.y < current_image_y + h && event.button. y > current_image_y)
                {
                    whileMinigameIsRunning =1;
                }
            }
        }
        SDL_GetMouseState(&x_MOUSE ,&y_MOUSE);
        if(x_MOUSE>750 && rectA.x<=1200)
            {
                    rectA.x+=2;
                    current_image_x=x_IMAGE-rectA.x;
            }
        if(y_MOUSE>550 && rectA.y<=1200)
            {
                    rectA.y+=2;
                    current_image_y=y_IMAGE-rectA.y;
            }
         if(x_MOUSE<50 && rectA.x>=0)
            {
                    rectA.x-=2;
                    current_image_x=x_IMAGE-rectA.x;
            }
         if(y_MOUSE<50 && rectA.y>=0)
            {
                    rectA.y-=2;
                    current_image_y=y_IMAGE-rectA.y;
            }
        SDL_RenderCopy(renderer,texture,&rectA,NULL);
        SDL_RenderPresent(renderer);
    }

}


#endif // MINIGAME_H_INCLUDED
