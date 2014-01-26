//player.h - player entity, derived from entity base class

#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"
#include "inputscheme.h"
#include "collision.h"
#include "spritesheet.h"

class Player: public Entity
{
public:
	Player(Spritesheet *spritesheet, const std::string anideffile, std::vector<Box> *boxVector, const int playerId);
	~Player();
	void ExecuteCommand(const GameCommand command);
	void Update(const double dt);
private:
	void ProcessForces();
	void SelectAnim();
	GameCommand lastCommand;
	bool rightPressed, leftPressed, upPressed, downPressed;
	bool movementPressed;	//true if any of the movement keys is pressed
	Collision collider;
	Box playerBox;

	//debug
	cml::vector2f lastForce;
};

#endif