#include "inputscheme.h"

InputScheme::InputScheme()
{
	schemeInputs.clear();

	//testing values
	this->AddInput(SDL_SCANCODE_RIGHT, true, MOVERIGHT);
	this->AddInput(SDL_SCANCODE_RIGHT, false, STOPMOVERIGHT);
	this->AddInput(SDL_SCANCODE_LEFT, true, MOVELEFT);
	this->AddInput(SDL_SCANCODE_LEFT, false, STOPMOVELEFT);
	this->AddInput(SDL_SCANCODE_UP, true, MOVEUP);
	this->AddInput(SDL_SCANCODE_UP, false, STOPMOVEUP);
	this->AddInput(SDL_SCANCODE_DOWN, true, MOVEDOWN);
	this->AddInput(SDL_SCANCODE_DOWN, false, STOPMOVEDOWN);
}

void InputScheme::AddInput(const SDL_Scancode desiredKey, const bool keyDown, const GameCommand desiredCommand)
{
	if(this->KeyAssigned(desiredKey, keyDown))	//If this key is already assigned to an input
	{
		this->DeleteKey(desiredKey);	//Remove the assignment first
	}

	SingleInput newInput;

	newInput.key = desiredKey;
	newInput.isKeyDown = keyDown;
	newInput.command = desiredCommand;

	schemeInputs.push_back(newInput);

	this->PrintCurrentState();
}

bool InputScheme::DeleteInput(const GameCommand commandToDelete)
{
	std::vector<SingleInput>::iterator itr;

	for(itr = schemeInputs.begin();itr != schemeInputs.end();++itr)
	{
		if(itr->command == commandToDelete)
		{
			schemeInputs.erase(itr);

			this->PrintCurrentState();

			return true;
		}
	}
	this->PrintCurrentState();

	return false;
}

bool InputScheme::DeleteKey(const SDL_Scancode keyToDelete)
{
	std::vector<SingleInput>::iterator itr;

	for(itr = schemeInputs.begin();itr != schemeInputs.end();++itr)
	{
		if(itr->key == keyToDelete)
		{
			schemeInputs.erase(itr);

			this->PrintCurrentState();

			return true;
		}
	}
	this->PrintCurrentState();

	return false;
}

bool InputScheme::KeyAssigned(const SDL_Scancode searchKey, const bool keyDown)
{
	std::vector<SingleInput>::iterator itr;

	for(itr = schemeInputs.begin();itr != schemeInputs.end();++itr)
	{
		if(itr->key == searchKey && itr->isKeyDown == keyDown)
		{
			return true;
		}
	}
	return false;
}

GameCommand InputScheme::getCommand(const SDL_Scancode keyPressed, const bool p_isKeyDown)
{
	std::vector<SingleInput>::iterator itr;

	for(itr = schemeInputs.begin();itr != schemeInputs.end();++itr)
	{
		if(itr->key == keyPressed && itr->isKeyDown == p_isKeyDown)
			return itr->command;
	}
	return UNDEFINED;
}

SDL_Scancode InputScheme::getKey(const GameCommand command)
{
	std::vector<SingleInput>::iterator itr;

	for(itr = schemeInputs.begin();itr != schemeInputs.end();++itr)
	{
		if(itr->command == command)
			return itr->key;
	}
	return DEFAULTSCANCODE;
}

std::string InputScheme::getCommandName(const GameCommand command)
{
	switch(command)
	{
	case UNDEFINED:
		return "UNDEFINED";
	case MOVELEFT:
		return "MOVELEFT";
	case STOPMOVELEFT:
		return "STOPMOVELEFT";
	case MOVERIGHT:
		return "MOVERIGHT";
	case STOPMOVERIGHT:
		return "STOPMOVERIGHT";
	case MOVEUP:
		return "MOVEUP";
	case STOPMOVEUP:
		return "STOPMOVEUP";
	case MOVEDOWN:
		return "MOVEDOWN";
	case STOPMOVEDOWN:
		return "STOPMOVEDOWN";
	default:
		return "COMMAND NOT FOUND";
	}
	return "SOMETHING IS WRONG";
}

void InputScheme::PrintCurrentState()
{
	std::vector<SingleInput>::iterator itr;

	std::cout << "Current inputscheme state:" << std::endl;

	for(itr = schemeInputs.begin();itr != schemeInputs.end();++itr)
	{
		std::cout << "Command: " << this->getCommandName(itr->command) << ", Key: ";
		std::cout << SDL_GetScancodeName(itr->key) << std::endl;
	}
}