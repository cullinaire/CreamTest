#include "globals.h"
#include "init.h"
#include <iostream>

//Temp for testing - these includes may become redundant once wrapper classes are done
#include "spritesheet.h"
#include "animobj.h"
#include "timekeep.h"
#include "inputscheme.h"
#include "entity.h"

int main(int argc, char **argv)
{
	SDL_Window *window = NULL;
	SDL_Renderer *rend = NULL;

	if(CreamInit(window, rend) != 0)
		return -1;

	/********TEST HARNESS********/
	SDL_Event ev;
	bool quit = false;
	double frameTime;
	double accumulator = 0;
	double t = 0;
	double alpha = 0;

	Timer testTimer;

	testTimer.Init();

	InputScheme testInput;

	testInput.AddInput(SDL_SCANCODE_0, MOVEUP);
	testInput.AddInput(SDL_SCANCODE_2, MOVEDOWN);
	testInput.DeleteInput(MOVEUP);
	testInput.DeleteKey(SDL_SCANCODE_2);
	std::cout << testInput.getCommandName(testInput.getCommand(SDL_SCANCODE_4)) << std::endl;
	testInput.AddInput(SDL_SCANCODE_4, MOVERIGHT);
	std::cout << testInput.getCommandName(testInput.getCommand(SDL_SCANCODE_4)) << std::endl;

	Spritesheet testSheet = Spritesheet("../assets/sample.bmp", rend);
	Animobj testAnim = Animobj("../assets/sample.def", &testSheet);
	Entity testEntity = Entity(&testAnim);

	while(!quit)
	{
		while(SDL_PollEvent(&ev))
		{
			if(ev.type == SDL_QUIT)
				quit = true;
			if(ev.type == SDL_KEYDOWN)
			{
				switch(ev.key.keysym.scancode)
				{
				case SDL_SCANCODE_ESCAPE:
					quit = true;
					break;
				case SDL_SCANCODE_0:
					break;
				case SDL_SCANCODE_1:
					break;
				}
			}
		}
		
		frameTime = testTimer.Update();
		accumulator += frameTime;

		while(accumulator >= FIXEDTIMESTEP)
		{
			accumulator -= FIXEDTIMESTEP;
			//Do fixed timestep stuff
			testEntity.Update(FIXEDTIMESTEP);
			t += FIXEDTIMESTEP;
		}

		alpha = accumulator/FIXEDTIMESTEP;

		SDL_RenderClear(rend);
		//Draw something now
		testEntity.Draw(alpha);
		SDL_RenderPresent(rend);
	}
	/********TEST HARNESS********/

	CreamCleanUp(window, rend);
	return 0;
}