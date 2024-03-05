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

    SDL_Texture* background = loadTexture("image\\bikiniBottom.jpg", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();

    SDL_Texture* spongeBob = loadTexture("image\\Spongebob.png", renderer);
    renderTexture(spongeBob, 200, 200, renderer);

    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();

    SDL_DestroyTexture( spongeBob );
    spongeBob = NULL;

    SDL_DestroyTexture( background );
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}
