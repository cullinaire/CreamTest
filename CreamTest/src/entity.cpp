#include "entity.h"

void Entity::Draw(double alpha)
{
	float rendx = currState.pos[0]*alpha + prevState.pos[0]*(1.0f - alpha);
	float rendy = currState.pos[1]*alpha + prevState.pos[1]*(1.0f - alpha);
	
	animObj->Draw(rendx, rendy);
}