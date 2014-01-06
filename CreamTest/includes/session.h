//session.h - defines a session: a unit of the game that encapsulates all needed for a game
//session. They are: interactive entities, animation sequences that represent the entities,
//input schemes that allow the player to input commands directed at specific entities

#ifndef SESSION_H_
#define SESSION_H_

class Session
{
public:
	Session();
	~Session();
	//Load animobjs
	//Add entity
	//Remove entity
	//Associate input scheme to entity
	//Associate animobj to entity
	//Process input
	//Collide entities
	//Resolve collisions
	//Update positions
	//Compose screen
private:
	//Array of entities
	//Array of animobjs
	//Array of inputschema
	//Collider
};

#endif