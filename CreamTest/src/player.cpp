#include "player.h"

Player::Player(Animobj *p_animobj)
{
	visible = true;
	collidable = true;
	animObj = p_animobj;
	lastCommand = UNDEFINED;
	rightPressed = false;
	leftPressed = false;
	upPressed = false;
	downPressed = false;
	movementPressed = false;

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
		rightPressed = true;
		movementPressed = true;
		lastCommand = command;
		break;

	case STOPMOVERIGHT:
		rightPressed = false;
		lastCommand = command;
		break;

	case MOVELEFT:
		leftPressed = true;
		movementPressed = true;
		lastCommand = command;
		break;

	case STOPMOVELEFT:
		leftPressed = false;
		lastCommand = command;
		break;

	case MOVEUP:
		upPressed = true;
		movementPressed = true;
		lastCommand = command;
		break;

	case STOPMOVEUP:
		upPressed = false;
		lastCommand = command;
		break;

	case MOVEDOWN:
		downPressed = true;
		movementPressed = true;
		lastCommand = command;
		break;

	case STOPMOVEDOWN:
		downPressed = false;
		lastCommand = command;
		break;

	default:
		break;
	}

	if(!rightPressed && !leftPressed && !upPressed && !downPressed)
		movementPressed = false;
}

void Player::Update(double dt)
{
	ProcessForces();
	
	prevState = currState;

	cml::vector2f lastAcc = currState.acc;

	currState.pos += currState.vel * dt + (0.5f * lastAcc * dt * dt);

	cml::vector2f newAcc = motiveForce / mass;

	cml::vector2f avgAcc = (lastAcc + newAcc) / 2;

	currState.acc = newAcc;

	currState.vel += avgAcc * dt;

	currState.vel *= FRICTION;

	if(currState.vel.length() > STATICTHRESH && !movementPressed)
		currState.vel.zero();	//Hopefully eliminates the "jitters"

	SelectAnim();
	animObj->Update(dt);
}

void Player::ProcessForces()
{
	if(rightPressed)
	{
		motiveForce[0] = 1;
		if(leftPressed)
			motiveForce[0] = 0;
	}
	else if(leftPressed)
	{
		motiveForce[0] = -1;
		if(rightPressed)
			motiveForce = 0;
	}
	else
		motiveForce[0] = 0;

	if(upPressed)
	{
		motiveForce[1] = -1;
		if(downPressed)
			motiveForce[1] = 0;
	}
	else if(downPressed)
	{
		motiveForce[1] = 1;
		if(upPressed)
			motiveForce[1] = 0;
	}
	else
		motiveForce[1] = 0;

	//Only normalize if nonzero vector
	if(motiveForce[0] != 0 || motiveForce[1] != 0)
		motiveForce.normalize();

	motiveForce *= DEFMOTIVEFORCE;
}

void Player::SelectAnim()
{
	if(currState.vel.length() > 0)
		animObj->Play(1, true, false);
	else
		animObj->Play(0, false, false);
}