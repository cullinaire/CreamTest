//spritesheet.h - defines a sprite sheet that allows drawing of selected areas of the image

#ifndef SPRITESHEET_H_
#define SPRITESHEET_H_

#include "globals.h"

class Spritesheet
{
public:
        Spritesheet(const std::string bmpfilename, SDL_Renderer *&renderer);
        void Draw(const SDL_Rect src, const SDL_Rect dst);
        ~Spritesheet();
private:
        SDL_Texture *texture;
        SDL_Surface *image;
        SDL_Renderer *rend;	//deinitialized separately - do not touch in destructor!
};

#endif