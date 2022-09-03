#include "function.h"

int	main(void)
{
	ft_creation_sdl();
	return (0);
}
void	SDL_Test(void)
{
	SDL_version test;
	SDL_VERSION(&test);

	printf("Hello world on sdl %d : %d : %d ! \n", test.major, test.minor, test.patch);
}

void	ft_creation_sdl(void)
{
	SDL_Window	*window;
	SDL_Renderer	*renderer;
	SDL_Event	event;

	if (SDL_Init(SDL_INIT_VIDEO))
		SDL_Exit_Error("SDL initialisation");
	window = SDL_CreateWindow("age of crux", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_FULLSCREEN
);
	renderer = SDL_CreateRenderer(window, -1, 0);

	ft_sdl_present(renderer, event);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	ft_sdl_present(SDL_Renderer *renderer,  SDL_Event event)
{
	SDL_bool isRunning = SDL_TRUE;
	
	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT :
					isRunning = SDL_FALSE;
					break ;
				case SDL_KEYUP:
					if (event.key.keysym.sym == SDLK_ESCAPE)
						isRunning = SDL_FALSE;
					break ;
				default : 
					break ;
			}

		}
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 107, 28, 35, 255);
	}
}
