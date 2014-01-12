#include "entity.h"

Entity::Entity(Animobj *p_animobj)
{
	visible = true;
	collidable = true;
	animObj = p_animobj;
	
	//temp values for testing
	mass = 0.2f;
	motiveForce.zero();
	currState.pos.set(64.0f, 64.0f);
	currState.vel.zero();
	currState.acc.zero();

	prevState = currState;

	animObj->Play(0, true, false);
}

void Entity::Update(double dt)
{
	prevState = currState;

	cml::vector2f lastAcc = currState.acc;

	currState.pos += currState.vel * dt + (0.5f * lastAcc * dt * dt);

	cml::vector2f newAcc = motiveForce / mass;

	cml::vector2f avgAcc = (lastAcc + newAcc) / 2;

	currState.acc = newAcc;

	currState.vel += avgAcc * dt;

	currState.vel *= FRICTION;

	//if(currState.vel.length() > STATICTHRESH)
	//	currState.vel.zero();	//Hopefully eliminates the "jitters"

	animObj->Update(dt);
}

void Entity::Draw(double alpha)
{
	float rendx = currState.pos[0]*alpha + prevState.pos[0]*(1.0f - alpha);
	float rendy = currState.pos[1]*alpha + prevState.pos[1]*(1.0f - alpha);
	
	animObj->Draw(rendx, rendy);
}