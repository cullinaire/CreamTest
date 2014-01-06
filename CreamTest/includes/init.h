//init.h - initialization stuff

#ifndef INIT_H_
#define INIT_H_

#include <iostream>

#include "globals.h"

int CreamInit(SDL_Window *&window, SDL_Renderer *&rend);
void CreamCleanUp(SDL_Window *&window, SDL_Renderer *&rend);

#endif