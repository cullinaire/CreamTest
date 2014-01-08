#include "entity.h"

Entity::Entity(Animobj *p_animobj)
{
	visible = true;
	collidable = true;
	animObj = p_animobj;

	//temp values for testing
	pos[0] = 64.0f;
	pos[1] = 64.0f;
	vel[0] = 0;
	vel[1] = 0;
	acc[0] = 0;
	acc[1] = 0;
	animObj->Play(0, true, false);
}

void Entity::Update(double dt)
{
	pos += vel * dt + acc * dt * dt;

	vel += acc * dt;

	if(vel[0] >= MAXVEL)
		vel[0] = MAXVEL;
	if(vel[1] >= MAXVEL)
		vel[1] = MAXVEL;

	vel *= FRICTION;

	animObj->Update(dt);
}

void Entity::Draw(double alpha)
{
	animObj->Draw(pos[0]*alpha, pos[1]*alpha);
}