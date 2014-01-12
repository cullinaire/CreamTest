//player.h - player entity, derived from entity base class

#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"
#include "inputscheme.h"

class Player: public Entity
{
public:
	Player(Animobj *p_animobj);
	~Player() {}
	void ExecuteCommand(const GameCommand command);
private:
	GameCommand lastCommand;
};

#endif