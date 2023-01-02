#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <time.h>

#define W 1200
#define H 600
#define DL 60
#define DJ 20


typedef struct {
		int x, y;
		SDL_Texture *jabuka;
		int x_vocka, y_vocka;
		SDL_Texture *lik;
}Pos;

short prav;

void cntrlEvent(SDL_Window *window, int *end, Pos *poz){
		
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
		const uint8_t *state = SDL_GetKeyboardState(NULL);

		if((state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) && (poz->x > 0)) poz->x -= 2;
		if((state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) && (poz->x + DL < W)) poz->x += 2;
		if((state[SDL_SCANCODE_W] ||state[SDL_SCANCODE_UP]) && (poz->y > 0)) poz->y -= 2;
		if((state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]) && (poz->y + DL < H)) poz->y += 2;
}

void rend(SDL_Renderer *renderer, Pos *poz){

				SDL_SetRenderDrawColor(renderer,  243, 135, 21 , 255);
		
				SDL_RenderClear(renderer);

				//SDL_SetRenderDrawColor(renderer,62, 254, 35, 255);

				SDL_Rect jabukarect = { poz->x_vocka, poz->y_vocka, DJ, DJ };
				SDL_RenderCopy(renderer, poz->jabuka, NULL, &jabukarect);
			
				SDL_Rect sefrect = { poz->x, poz->y, DL, DL };
				SDL_RenderCopy(renderer, poz->lik, NULL, &sefrect);

				SDL_RenderPresent(renderer);
				
			//	if(poz->x > W - 100  && poz->y > H - 100 ) prav = 2;
			//	else if(!poz->x && !poz->y) prav = 1;


			}
void podesi(Pos *poz){

		srand(time(NULL));
		int w = W - DJ;
		int h = H - DJ;
		poz->x_vocka = rand()%w;
		poz->y_vocka = rand()%h;
}
void provera(SDL_Surface **surf){
	if(surf == NULL){
				printf("Ne moze da nadje\n");
				SDL_Quit();
				exit(1);
		}
}

int main(int argc, char *argv[]){
		
		Pos poz;
		int end = 1;

		
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Surface *surf;

		SDL_Init(SDL_INIT_VIDEO);

		window = SDL_CreateWindow("Window",
								  SDL_WINDOWPOS_UNDEFINED,
								  SDL_WINDOWPOS_UNDEFINED,
								  W,
								  H,
								  0
						);

		poz.x = W/2 - DL;
		poz.y = H/2 - DL;
		podesi(&poz);

		renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		
		surf = IMG_Load("slika/jabuka.png");
		provera(&surf);
		poz.jabuka = SDL_CreateTextureFromSurface(renderer, surf);
		SDL_FreeSurface(surf);

		surf = IMG_Load("slika/sefko.png");
		provera(&surf);
		poz.lik = SDL_CreateTextureFromSurface(renderer, surf);
		SDL_FreeSurface(surf);

		uint8_t semafor = 0;

		while(end){
		
				cntrlEvent(window, &end, &poz);
				
				rend(renderer, &poz);
//|| poz.x <= poz.x_vocka + 50
				//desno || right 1 && left || levo 2
				if(((poz.x + DL >= poz.x_vocka && poz.x + DL <= poz.x_vocka + DJ) ||
				    (poz.x <= poz.x_vocka + DJ && poz.x >= poz.x_vocka)) && (poz.y >= poz.y_vocka - DL && poz.y <= poz.y_vocka + 50))
						semafor = 1;
				//gore dole
				if(((poz.y + DL >= poz.y_vocka && poz.y + DL <= poz.y_vocka + DJ) ||
				   (poz.y <= poz.y_vocka + DJ && poz.y >= poz.y_vocka)) && (poz.x >= poz.x_vocka - DL && poz.x <= poz.x_vocka + 50))
						semafor = 1;

				if(semafor) podesi(&poz);

				semafor = 0;

			//	SDL_Delay(15);

		}
				SDL_DestroyTexture(poz.jabuka);
				SDL_DestroyWindow(window);
				SDL_DestroyRenderer(renderer);

				SDL_Quit();

		return 0;
}
