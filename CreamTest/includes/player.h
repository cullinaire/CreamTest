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
	void Update(double dt);
private:
	void ProcessForces();
	void SelectAnim();
	GameCommand lastCommand;
	bool rightPressed, leftPressed, upPressed, downPressed;
	bool movementPressed;	//true if any of the movement keys is pressed

	//debug
	cml::vector2f lastForce;
};

#endif