#ifndef MINIGAME_H_INCLUDED
#define MINIGAME_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
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
                        {a.imageX=250;a.imageY=150;}
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
    bool uu_tien_a=0;bool HD=1;
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
                    if (event.type == SDL_MOUSEBUTTONDOWN) {
                        uu_tien_a=1;
                        if (event.button.button == SDL_BUTTON_LEFT) {
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
                                a.imageY=b.imageY;a.imageX=b.imageX-150;
                                if(a.imageY<=230){texture=IMG_LoadTexture(renderer,"image\\message\\minigame1.png");}
                                else {texture=IMG_LoadTexture(renderer,"image\\message\\minigame2.png");}
                                minigame_is_running=1;
                        }

                    }
                }
            else if((vi_tri_chuot_thuoc_vung_a==0&&vi_tri_chuot_thuoc_vung_b==1)||uu_tien_a==0)
                {
                        if (event.type == SDL_MOUSEBUTTONDOWN) {

                            if (event.button.button == SDL_BUTTON_LEFT) {
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
                                        a.imageY=b.imageY;a.imageX=b.imageX-150;
                                        if(a.imageY<=230){texture=IMG_LoadTexture(renderer,"image\\message\\minigame1.png");}
                                        else {texture=IMG_LoadTexture(renderer,"image\\message\\minigame2.png");}
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


#endif // MINIGAME_H_INCLUDED
