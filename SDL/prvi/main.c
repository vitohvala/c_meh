#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 800


typedef struct {
    int x, y;
}Pos;

short prav;

void cntrlEvent(SDL_Window *window, int *end){

    SDL_Event event;

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_WINDOWEVENT_CLOSE:
                if(window){
                    SDL_DestroyWindow(window);
                    window = NULL;
                    (*end) = 0;
                }
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        (*end) = 0;
                        break;
                }
                break;
            case SDL_QUIT:
                (*end) = 0;
                break;

        }
    }
}

void rend(SDL_Renderer *renderer, Pos *poz){

    SDL_SetRenderDrawColor(renderer,  243, 135, 21 , 255);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,62, 254, 35, 255);
    SDL_Rect rect = { poz->x, poz->y, 100, 100 };
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    if(poz->x > WIDTH - 100  && poz->y > HEIGHT - 100 ) prav = 2;
    else if(!poz->x && !poz->y) prav = 1;

    if(prav == 1){
        poz->x += 6;
        poz->y += 3;
    }
    else if(prav == 2) {
        poz->x -= 6;
        poz->y -= 3;
    }

}
#ifdef __WIN32__
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char *argv[])
#endif
{
    Pos poz;
    int end = 1;

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Window",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WIDTH,
            HEIGHT,
            0
            );

    poz.x = 0;
    poz.y = 0;

    renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED);

    while(end){

        cntrlEvent(window, &end);

        rend(renderer, &poz);

        SDL_Delay(15);

    }	
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();

    return 0;
}
