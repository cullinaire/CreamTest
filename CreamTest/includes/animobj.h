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

//Defines animations - is not used directly. Is only to be used as part of Animobj
class Animation
{
public:
	Animation() {}
	Animation(const std::string defFile);
	void Play(const int idToPlay, const bool looping, const bool backNforth);
	void Stop();
	SDL_Rect Update(const double dt);
	~Animation() {}
private:
	std::vector<AnimSequence> seqs;
	int currentPlayingId;
	int currentFrameId;
	bool isPlaying;
	bool loopAnim;
	bool bNfAnim;
	bool reverse;
	double elapsed;
};

//Encapsulates animations and associated spritesheets
class Animobj
{
public:
	Animobj() {}
	Animobj(const std::string defFile, Spritesheet *spritesheet);
	void Play(const int idToPlay, const bool looping, const bool backNforth);
	int whichIdisPlaying();
	void Stop();
	void Update(const double dt);
	void Draw(const float x, const float y);
	~Animobj() {}
	//Set animation speed factor (0 = stopped, 1 = default, etc.)
	//Place animation at specified location
private:
	Spritesheet		*animSheet;
	Animation		anims;
	int				lastPlayingId;
	SDL_Rect		src;
	SDL_Rect		dst;
};

#endif