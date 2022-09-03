#include "function.h"

void	SDL_Exit_Error(const char *error)
{
	SDL_Log("ERROR : %s > %s .", error, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
