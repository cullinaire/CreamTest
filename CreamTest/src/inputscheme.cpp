#include "inputscheme.h"

InputScheme::InputScheme()
{
	schemeInputs.clear();
}

void InputScheme::AddInput(const SDL_Scancode desiredKey, const GameCommand desiredCommand)
{
	if(this->KeyAssigned(desiredKey))	//If this key is already assigned to an input
	{
		this->DeleteKey(desiredKey);	//Remove the assignment first
	}

	SingleInput newInput;

	newInput.key = desiredKey;
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

bool InputScheme::KeyAssigned(const SDL_Scancode searchKey)
{
	std::vector<SingleInput>::iterator itr;

	for(itr = schemeInputs.begin();itr != schemeInputs.end();++itr)
	{
		if(itr->key == searchKey)
		{
			return true;
		}
	}
	return false;
}

GameCommand InputScheme::getCommand(const SDL_Scancode keyPressed)
{
	std::vector<SingleInput>::iterator itr;

	for(itr = schemeInputs.begin();itr != schemeInputs.end();++itr)
	{
		if(itr->key == keyPressed)
			return itr->command;
	}
	return UNDEFINED;
}

SDL_Scancode InputScheme::getKey(const SDL_Scancode command)
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
	case MOVERIGHT:
		return "MOVERIGHT";
	case MOVEUP:
		return "MOVEUP";
	case MOVEDOWN:
		return "MOVEDOWN";
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