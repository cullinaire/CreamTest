#include "spritesheet.h"

Spritesheet::Spritesheet(const std::string bmpfilename, SDL_Renderer *&renderer)
{
    rend = renderer;
    texture = NULL;
    image = SDL_LoadBMP(bmpfilename.c_str());

	std::cout << "Loading " << bmpfilename << "..." << std::endl;

    if(image != NULL)
    {
        //Set transparent pixel as pixel at (0,0)
        if(image->format->palette)
        {
            SDL_SetColorKey(image, 1, *(Uint8 *) image->pixels);
			std::cout << "is paletted image" << std::endl;
        }
        else
        {
            switch(image->format->BitsPerPixel)
            {
            case 15:
                SDL_SetColorKey(image, 1, (*(Uint16 *) image->pixels) & 0x00007FFF);
				std::cout << "is 15 bpp image" << std::endl;
                break;
            case 16:
                SDL_SetColorKey(image, 1, *(Uint16 *) image->pixels);
				std::cout << "is 16 bpp image" << std::endl;
                break;
            case 24:
                SDL_SetColorKey(image, 1, (*(Uint32 *) image->pixels) & 0x00FFFFFF);
				std::cout << "is 24 bpp image" << std::endl;
                break;
            case 32:
                SDL_SetColorKey(image, 1, *(Uint32 *) image->pixels);
				std::cout << "is 32 bpp image" << std::endl;
                break;
            }
        }

        texture = SDL_CreateTextureFromSurface(rend, image);
        //Surface is freed here; texture will be freed in destructor
        SDL_FreeSurface(image);
        if(texture == NULL)
            std::cout << SDL_GetError() << std::endl;	//Could not convert surface to texture
        else
            std::cout << "Successfully loaded image." << std::endl;
    }
    else
        std::cout << SDL_GetError() << std::endl;	//Could not load bitmap from file
}

void Spritesheet::Draw(const SDL_Rect src, const SDL_Rect dst)
{
    SDL_RenderCopy(rend, texture, &src, &dst);
}

Spritesheet::~Spritesheet()
{
    SDL_DestroyTexture(texture);
}