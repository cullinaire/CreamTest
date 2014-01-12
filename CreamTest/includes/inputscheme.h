//inputscheme.h - input scheme routines

#ifndef INPUTSCHEME_H_
#define INPUTSCHEME_H_

#include <iostream>

#include "globals.h"

enum GameCommand
{
	UNDEFINED,
	MOVELEFT,
	STOPMOVELEFT,
	MOVERIGHT,
	STOPMOVERIGHT,
	MOVEUP,
	STOPMOVEUP,
	MOVEDOWN,
	STOPMOVEDOWN
};

struct SingleInput
{
	SDL_Scancode key;
	bool isKeyDown;
	GameCommand command;
};

class InputScheme
{
public:
	InputScheme();
	~InputScheme() {}
	void AddInput(const SDL_Scancode desiredKey, const bool keyDown, const GameCommand desiredCommand);
	bool DeleteInput(const GameCommand commandToDelete);
	bool DeleteKey(const SDL_Scancode keyToDelete);
	bool KeyAssigned(const SDL_Scancode searchKey, const bool keyDown);
	GameCommand getCommand(const SDL_Scancode keyPressed, const bool p_isKeyDown);
	SDL_Scancode getKey(const GameCommand command);
	std::string getCommandName(const GameCommand command);
	void PrintCurrentState();	//Debug only
private:
	std::vector<SingleInput> schemeInputs;
};

#endif