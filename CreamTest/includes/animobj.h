//animobj.h - animation objects. Includes facilities to play animations at specified location on
//screen. Basically acts as an intermediary that uses an animation to point at the appropriate
//places on a spritesheet.

#ifndef ANIMOBJ_H_
#define ANIMOBJ_H_

#include <vector>
#include <fstream>

#include "globals.h"
#include "spritesheet.h"
#include "parse.h"

//This struct defines one animation frame
struct Frame
{
	SDL_Rect	cutout;		//the portion of the spritesheet to display
	int			duration;	//default duration of frame in ms
};

//This struct defines one animation sequence
struct AnimSequence
{
	int					animId;		//Unique identifier
	int					numFrames;	//Number of frames
	std::vector<Frame>	frames;		//Actual animation frames
};

//Defines animations
class Animation
{
public:
	Animation() {}
	Animation(const std::string defFile);
	~Animation() {}
private:
	std::vector<AnimSequence> seqs;
};

class Animobj
{
public:
	Animobj() {}
	~Animobj() {}
	//Set animation speed factor (0 = stopped, 1 = default, etc.)
	//Place animation at specified location
private:
	Spritesheet		*animSheet;
	Animation		anims;
};

#endif