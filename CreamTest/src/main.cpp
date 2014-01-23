#include "globals.h"
#include "init.h"
#include <iostream>

//Temp for testing - these includes may become redundant once wrapper classes are done
#include "spritesheet.h"
#include "animobj.h"
#include "timekeep.h"
#include "player.h"
#include "inputscheme.h"
#include "collision.h"

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

	Spritesheet *testSheet = new Spritesheet("../assets/sample.bmp", rend);
	Animobj *testAnim = new Animobj("../assets/sample.def", testSheet);
	Player *testEntity = new Player(testAnim);
	Player *anotherEnt = new Player(testAnim);
	InputScheme *playerInput = new InputScheme();
	std::vector<Box> boxes;
	Collision *collider = new Collision(&boxes);
	Box aBox;
	aBox.id = 677;
	collider->Add(aBox);
	aBox.id = 92314;
	collider->Add(aBox);
	aBox.id = 134;
	collider->Add(aBox);
	aBox.id = 21;
	std::cout << "Index of aBox is: " << collider->Add(aBox) << std::endl;

	GameCommand lastInput = UNDEFINED;

	while(!quit)
	{
		while(SDL_PollEvent(&ev))
		{
			if(ev.type == SDL_QUIT)
				quit = true;
			if(ev.type == SDL_KEYDOWN)
			{
				lastInput = playerInput->getCommand(ev.key.keysym.scancode, true);
			}
			else if(ev.type == SDL_KEYUP)
			{
				lastInput = playerInput->getCommand(ev.key.keysym.scancode, false);
			}
			testEntity->ExecuteCommand(lastInput);
		}
		
		frameTime = testTimer.Update();
		accumulator += frameTime;

		while(accumulator >= FIXEDTIMESTEP)
		{
			accumulator -= FIXEDTIMESTEP;

			//Do fixed timestep stuff
			testEntity->Update(FIXEDTIMESTEP);

			t += FIXEDTIMESTEP;
		}

		alpha = accumulator/FIXEDTIMESTEP;

		SDL_RenderClear(rend);
		//Draw something now
		testEntity->Draw(alpha);
		
		SDL_RenderPresent(rend);
	}

	delete testSheet;
	delete testAnim;
	delete testEntity;
	delete anotherEnt;
	delete playerInput;
	delete collider;
	/********TEST HARNESS********/

	CreamCleanUp(window, rend);
	return 0;
}