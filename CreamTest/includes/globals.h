//globals.h - global constants and such

#ifndef GLOBALS_H_
#define GLOBALS_H_

/********INCLUDES**********/
#ifdef __linux
	#include "SDL2/SDL.h"
#elif _WIN32
	#include "SDL.h"
#endif

#include "cml/cml.h"
/********INCLUDES**********/

/*********DEFINES**********/
#define round(x) ((x) >= 0 ? (long)((x)+0.5) : (long)((x)-0.5))	//round float to nearest int
#define FIXEDTIMESTEP	0.01f
#define MAXFRAMETIME	0.25f
#define DEFAULTSCANCODE	SDL_SCANCODE_NONUSHASH
#define MAXVEL			40.0f
#define FRICTION		0.95f
#define STATICTHRESH	0.01f
#define DEFMOTIVEFORCE	400.0f
/*********DEFINES**********/

#endif

