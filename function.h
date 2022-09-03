#ifndef FUNCTION_H
#define FUNCTION_H

#include <SDL2/SDL.h>
#include <SDL_rect.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void	ft_creation_sdl(void);
void    ft_sdl_present(SDL_Renderer *renderer, SDL_Event event);
void    SDL_Exit_Error(const char *error);

#endif
