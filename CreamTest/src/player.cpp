#include "player.h"

Player::Player(Animobj *p_animobj)
{
	animObj = p_animobj;
	animObj->Play(0, true, false);
	lastCommand = UNDEFINED;
}

void Player::ExecuteCommand(const GameCommand command)
{
	switch(command)
	{
	case MOVERIGHT:
		this->motiveForce[0] = 25.0f;
		break;
	case STOPMOVERIGHT:
		this->motiveForce[0] = 0;
		break;
	default:
		break;
	}
}