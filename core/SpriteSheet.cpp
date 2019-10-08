#include "SpriteSheet.h"



SpriteSheet::SpriteSheet()
{
}


SpriteSheet::~SpriteSheet()
{
}

bool SpriteSheet::init(const char* file, Size size, Size spriteSize)
	{
		surface = IMG_Load(file);

		if(!surface)
		{
			return false;
		}

		int columns = size.width / spriteSize.width;
		int rows = size.height / spriteSize.height;

		rects = new SDL_Rect * [rows];
		for (int x = 0; x < rows; x++) {
			rects[x] = new SDL_Rect[columns];
			for (int y = 0; y < columns; y++)
			{
				rects[x][y] = { x * spriteSize.width, y * spriteSize.height, spriteSize.width, spriteSize.height };
			}
		}
		return true;
	}
	
	void SpriteSheet::draw(SDL_Surface* s, Point sprite, SDL_Rect dst)
	{
		SDL_BlitSurface(surface, &rects[sprite.x][sprite.y], s, &dst);
	}
