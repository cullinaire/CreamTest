//timekeep.h - timer and timing related routines

#ifndef TIMEKEEP_H_
#define TIMEKEEP_H_

#include "globals.h"

class Timer
{
public:
	Timer() {}
	void Init();
	double Update();
	~Timer() {}
private:
	Uint64	currentTime;
	Uint64	sysCounter;		//persistent time, in format of system counter, not actual time in seconds
	Uint64	lastCount;
	double frameTime;
};

#endif