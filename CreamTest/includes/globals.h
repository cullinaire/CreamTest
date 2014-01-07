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
/*********DEFINES**********/

#endif

