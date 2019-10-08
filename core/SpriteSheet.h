#pragma once

#include "common.h"


class SpriteSheet
{
public:
	SpriteSheet();
	~SpriteSheet();

	bool init(const char* file, Size size, Size spriteSize);
	

	void draw(SDL_Surface* s, Point sprite, SDL_Rect dst);

private:
	SDL_Surface* surface;
	SDL_Rect** rects;
};

