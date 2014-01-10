#include "globals.h"
#include "init.h"
#include <iostream>

//Temp for testing - these includes may become redundant once wrapper classes are done
#include "spritesheet.h"
#include "animobj.h"
#include "timekeep.h"
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

	//Spritesheet testSheet = Spritesheet("../assets/sample.bmp", rend);
	//Animobj testAnim = Animobj("../assets/sample.def", &testSheet);
	//Entity testEntity = Entity(&testAnim);

	SDL_Texture *texture;
	SDL_Surface *image;

	texture = NULL;
    image = SDL_LoadBMP("../assets/sample.bmp");

	std::cout << "Loading " << "../assets/sample.bmp" << "..." << std::endl;

    if(image != NULL)
    {
        //Set transparent pixel as pixel at (0,0)
        if(image->format->palette)
        {
            SDL_SetColorKey(image, 1, *(Uint8 *) image->pixels);
			std::cout << "is paletted image" << std::endl;
        }
        else
        {
            switch(image->format->BitsPerPixel)
            {
            case 15:
                SDL_SetColorKey(image, 1, (*(Uint16 *) image->pixels) & 0x00007FFF);
				std::cout << "is 15 bpp image" << std::endl;
                break;
            case 16:
                SDL_SetColorKey(image, 1, *(Uint16 *) image->pixels);
				std::cout << "is 16 bpp image" << std::endl;
                break;
            case 24:
                SDL_SetColorKey(image, 1, (*(Uint32 *) image->pixels) & 0x00FFFFFF);
				std::cout << "is 24 bpp image" << std::endl;
                break;
            case 32:
                SDL_SetColorKey(image, 1, *(Uint32 *) image->pixels);
				std::cout << "is 32 bpp image" << std::endl;
                break;
            }
        }

        texture = SDL_CreateTextureFromSurface(rend, image);
        //Surface is freed here; texture will be freed in destructor
        SDL_FreeSurface(image);
        if(texture == NULL)
            std::cout << SDL_GetError() << std::endl;	//Could not convert surface to texture
        else
            std::cout << "Successfully loaded image." << std::endl;
    }
    else
        std::cout << SDL_GetError() << std::endl;	//Could not load bitmap from file

	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	src.w = 5;
	src.h = 6;
	dst = src;
	dst.x = 64;
	dst.y = 64;

	//testAnim.Play(0, true, false);

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
			//testEntity.Update(FIXEDTIMESTEP);
			//testAnim.Update(FIXEDTIMESTEP);

			t += FIXEDTIMESTEP;
		}

		alpha = accumulator/FIXEDTIMESTEP;

		SDL_RenderClear(rend);
		//Draw something now
		//testEntity.Draw(alpha);
		//testAnim.Draw(54, 54);
		//testSheet.Draw(src, dst);
		SDL_RenderCopy(rend, texture, &src, &dst);
		SDL_RenderPresent(rend);
	}
	/********TEST HARNESS********/

	CreamCleanUp(window, rend);
	return 0;
}