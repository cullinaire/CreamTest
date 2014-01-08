//inputscheme.h - input scheme routines

#ifndef INPUTSCHEME_H_
#define INPUTSCHEME_H_

#include <iostream>

#include "globals.h"

enum GameCommand
{
	UNDEFINED,
	MOVELEFT,
	MOVERIGHT,
	MOVEUP,
	MOVEDOWN
};

struct SingleInput
{
	SDL_Scancode key;
	GameCommand command;
};

class InputScheme
{
public:
	InputScheme();
	~InputScheme() {}
	void AddInput(const SDL_Scancode desiredKey, const GameCommand desiredCommand);
	bool DeleteInput(const GameCommand commandToDelete);
	bool DeleteKey(const SDL_Scancode keyToDelete);
	bool KeyAssigned(const SDL_Scancode searchKey);
	GameCommand getCommand(const SDL_Scancode keyPressed);
	SDL_Scancode getKey(const SDL_Scancode command);
	std::string getCommandName(const GameCommand command);
	void PrintCurrentState();	//Debug only
private:
	std::vector<SingleInput> schemeInputs;
};

#endif