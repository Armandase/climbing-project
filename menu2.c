#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int	main(void)
{
	SDL_bool loopShouldStop = SDL_FALSE;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){printf("%s\n", SDL_GetError());exit(-1);}
	if (TTF_Init() == -1){printf("%s\n", TTF_GetError());exit(-1);}

	SDL_Window *window;
	window = SDL_CreateWindow("Test", 100, 100, 500, 500, SDL_WINDOW_OPENGL);
	if (window == NULL){printf("%s\n", SDL_GetError()); exit(-1);}

	SDL_Renderer	*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Rect	rect;
	rect.x = 150;
	rect.y = 10;
	rect.w = 200;
	rect.h = 40;

	SDL_Color defaultColor = {0, 0, 0, 255};
	TTF_Font *titleFont = TTF_OpenFont("AmaticSC-Regular.ttf", 600);
	SDL_Surface *surfaceText = NULL; 
	surfaceText = TTF_RenderText_Solid(titleFont, "Bienvenue", defaultColor);
	SDL_Texture *textureText = SDL_CreateTextureFromSurface(renderer, surfaceText);

	SDL_FreeSurface(surfaceText);

	while (!loopShouldStop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					loopShouldStop = SDL_TRUE;
				break;
			}
			switch (event.key.keysym.sym)
			{
				case SDLK_RIGHT:
					rect.x += 5; break;
				case SDLK_LEFT:
					rect.x -= 5; break;
				case SDLK_UP:
					rect.y -= 5; break;
				case SDLK_DOWN:
					rect.y += 5; break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 64, 224, 208, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, textureText, NULL, &rect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(textureText);
	SDL_DestroyWindow(window);
	TTF_CloseFont(titleFont);
	TTF_Quit();
	SDL_Quit();

	return (0);
}
