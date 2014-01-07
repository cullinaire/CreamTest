#include "timekeep.h"

void Timer::Init()
{
	currentTime = SDL_GetPerformanceCounter();
	sysCounter = 0;
	lastCount = sysCounter;
	frameTime = 0;
}

double Timer::Update()
{
	Uint64 newTime = SDL_GetPerformanceCounter();
	Uint64 diff = newTime - currentTime;

	sysCounter += diff;
	currentTime = newTime;

	frameTime = (double)(sysCounter - lastCount)/SDL_GetPerformanceFrequency();
	lastCount = sysCounter;

	if(frameTime > MAXFRAMETIME)
		frameTime = MAXFRAMETIME;	//Max frame time to avoid spiral of death

	return frameTime;
}