#include "player.h"

Player::Player(Animobj *p_animobj)
{
	visible = true;
	collidable = true;
	animObj = p_animobj;
	lastCommand = UNDEFINED;

	//temp values for testing
	mass = 0.2f;
	motiveForce.zero();
	currState.pos.set(64.0f, 64.0f);
	currState.vel.zero();
	currState.acc.zero();

	prevState = currState;

	animObj->Play(0, true, false);
}

void Player::ExecuteCommand(const GameCommand command)
{
	switch(command)
	{
	case MOVERIGHT:
		this->motiveForce[0] = 1;
		lastCommand = command;
		break;
	case STOPMOVERIGHT:
		this->motiveForce[0] = 0;
		lastCommand = command;
		break;
	case MOVELEFT:
		this->motiveForce[0] = -1;
		lastCommand = command;
		break;
	case STOPMOVELEFT:
		this->motiveForce[0] = 0;
		lastCommand = command;
		break;
	case MOVEUP:
		this->motiveForce[1] = -1;
		lastCommand = command;
		break;
	case STOPMOVEUP:
		this->motiveForce[1] = 0;
		lastCommand = command;
		break;
	case MOVEDOWN:
		this->motiveForce[1] = 1;
		lastCommand = command;
		break;
	case STOPMOVEDOWN:
		this->motiveForce[1] = 0;
		lastCommand = command;
		break;
	default:
		break;
	}
}