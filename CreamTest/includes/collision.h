//collision.h - collision detect stuff

#ifndef COLLISION_H_
#define COLLISION_H_

#include "globals.h"
#include "entity.h"

#include <vector>
#include <algorithm>

struct AABB
{
	cml::vector2i A;	//[xmin][ymin] (upper left corner)
	cml::vector2i B;	//[xmax][ymax] (lower right corner)
};

struct Box
{
	AABB aabb;
	int id;
};

struct Endpoint
{
	int ownerId;
	bool trueIfmax;	//falseIfmin
};

bool operator==(const Box &lhs, const Box &rhs);

bool collide(const AABB boxA, const AABB boxB);

class Collision
{
public:
	Collision() {};
	void AssignDatabase(std::vector<Box> *boxVector);
	~Collision() {}
	bool Add(const Box newBox);
	void Remove(const int id);
	void Update(const Box updateBox);
private:
	std::vector<Box> *boxes;	//pointer to external vector
	std::vector<Endpoint> *endpoints;	//pointer to external vector
};

#endif