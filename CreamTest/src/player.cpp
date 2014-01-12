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
		motiveForce[0] = DEFMOTIVEFORCE;
		lastCommand = command;
		break;
	case STOPMOVERIGHT:
		motiveForce[0] = 0;
		lastCommand = command;
		break;
	case MOVELEFT:
		motiveForce[0] = -DEFMOTIVEFORCE;
		lastCommand = command;
		break;
	case STOPMOVELEFT:
		motiveForce[0] = 0;
		lastCommand = command;
		break;
	case MOVEUP:
		motiveForce[1] = -DEFMOTIVEFORCE;
		lastCommand = command;
		break;
	case STOPMOVEUP:
		motiveForce[1] = 0;
		lastCommand = command;
		break;
	case MOVEDOWN:
		motiveForce[1] = DEFMOTIVEFORCE;
		lastCommand = command;
		break;
	case STOPMOVEDOWN:
		motiveForce[1] = 0;
		lastCommand = command;
		break;
	default:
		break;
	}
}