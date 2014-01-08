//entity.h - base class for game entities

#ifndef ENTITY_H_
#define ENTITY_H_

#include "animobj.h"
#include "inputscheme.h"

class Entity
{
public:
	Entity();
	~Entity();
	virtual void Update();
private:
	cml::vector2f pos;
	cml::vector2f vel;
	cml::vector2f acc;
	bool visible;
	bool collidable;
};

#endif