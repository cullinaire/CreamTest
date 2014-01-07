#include "session.h"

Session::Session(SDL_Renderer *&renderer)
{
	rend = renderer;
	sheets.clear();
	animobjs.clear();
}

Session::~Session()
{
	for(std::vector<Spritesheet*>::iterator itr = sheets.begin();itr != sheets.end();++itr)
	{
		if(*itr != NULL)
			delete *itr;
	}

	for(std::vector<Animobj*>::iterator itr = animobjs.begin();itr != animobjs.end();++itr)
	{
		if(*itr != NULL)
			delete *itr;
	}
}

void Session::LoadSpriteSheets()
{
	Spritesheet *newSheet = new Spritesheet("../assets/sample.bmp", rend);
	sheets.push_back(newSheet);
}

void Session::LoadAnimObjs()
{
	Animobj *newAnim = new Animobj("../assets/sample.def", sheets[0]);
	animobjs.push_back(newAnim);
}

void Session::ComposeScreen()
{
	//Draw background stuff
	//Draw active elements
	//Draw interface stuff
}