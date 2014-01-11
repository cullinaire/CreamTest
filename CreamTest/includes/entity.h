//entity.h - base class for game entities

#ifndef ENTITY_H_
#define ENTITY_H_

#include "animobj.h"

struct EntityState
{
	cml::vector2f pos;
	cml::vector2f vel;
	cml::vector2f acc;
};

class Entity
{
public:
	Entity(Animobj *p_animobj);
	~Entity() {}
	virtual void Update(double dt);
	virtual void Draw(double alpha);

	//Test
	void apply_force();
	void remove_force();
private:
	EntityState currState;
	EntityState prevState;
	cml::vector2f motiveForce;
	float mass;
	bool visible;
	bool collidable;
	Animobj *animObj;
};

#endif