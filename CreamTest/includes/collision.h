//collision.h - collision detect stuff

#ifndef COLLISION_H_
#define COLLISION_H_

#include "globals.h"
#include "entity.h"

#include <vector>

struct AABB
{
	cml::vector2i A;	//[xmin][ymin] (upper left corner)
	cml::vector2i B;	//[xmax][ymax] (lower right corner)
};

struct Box
{
	AABB aabb;
	Entity *owner;
};

bool collide(const AABB boxA, const AABB boxB);

class Collision
{
public:
	Collision();
	~Collision() {}
	void AddBox(const Box newBox);
	void naiveCollide();
private:
	std::vector<Box> boxes;
};

#endif