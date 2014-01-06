#include "init.h"

int CreamInit(SDL_Window *&window, SDL_Renderer *&rend)
{
	/**********SDL INIT**********/
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow("CreamTest", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		return 2;
	}

	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if(rend == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		return 3;
	}
	/**********SDL INIT**********/

	return 0;
}

void CreamCleanUp(SDL_Window *&window, SDL_Renderer *&rend)
{
	/**********CLEAN UP**********/
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);
	SDL_Quit();
	/**********CLEAN UP**********/
}