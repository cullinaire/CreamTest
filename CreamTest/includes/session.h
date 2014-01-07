//session.h - defines a session: a unit of the game that encapsulates all needed for a game
//session. They are: interactive entities, animation sequences that represent the entities,
//input schemes that allow the player to input commands directed at specific entities

#ifndef SESSION_H_
#define SESSION_H_

#include <vector>

#include "animobj.h"
#include "spritesheet.h"

class Session
{
public:
	Session(SDL_Renderer *&renderer);
	~Session();
	void LoadSpriteSheets();
	void LoadAnimObjs();
	//Add entity
	//Remove entity
	//Associate input scheme to entity
	//Associate animobj to entity
	//Process input
	//Collide entities
	//Resolve collisions
	//Update positions
	void ComposeScreen();
private:
	std::vector<Spritesheet*> sheets;
	SDL_Renderer *rend; //deinitialized separately - do not touch in destructor!
	//Array of entities
	std::vector<Animobj*> animobjs;
	//Array of inputschema
	//Collider
};

#endif