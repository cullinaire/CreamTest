#include "globals.h"
#include "init.h"
#include <iostream>

//Temp for testing - these includes may become redundant once wrapper classes are done
#include "spritesheet.h"
#include "animobj.h"

int main(int argc, char **argv)
{
	SDL_Window *window = NULL;
	SDL_Renderer *rend = NULL;

	if(CreamInit(window, rend) != 0)
		return -1;

	/********TEST HARNESS********/
	SDL_Event ev;
	bool quit = false;

	Animation testAnim("../assets/sample.def");
	Spritesheet sample("../assets/sample.bmp", rend);
	SDL_Rect src, dst;
	src.w = 20;
	src.h = 24;
	src.x = 6;
	src.y = 7;

	dst.w = 20;
	dst.h = 24;
	dst.x = 128;
	dst.y = 128;
	
	while(!quit)
	{
		while(SDL_PollEvent(&ev))
		{
			if(ev.type == SDL_QUIT)
				quit = true;
		}
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
		SDL_RenderClear(rend);
		sample.Draw(src, dst);
		SDL_RenderPresent(rend);
	}
	/********TEST HARNESS********/

	CreamCleanUp(window, rend);
	return 0;
}