//entity.h - base class for game entities

#ifndef ENTITY_H_
#define ENTITY_H_

#include "animobj.h"

class Entity
{
public:
	Entity(Animobj *p_animobj);
	~Entity() {}
	virtual void Update(double dt);
	virtual void Draw(double alpha);
private:
	cml::vector2f pos;
	cml::vector2f vel;
	cml::vector2f acc;
	float mass;
	bool visible;
	bool collidable;
	Animobj *animObj;
};

#endif