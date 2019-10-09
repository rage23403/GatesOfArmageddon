#pragma once

#include "common.h"
#include "SpriteSheet.h"

enum Direction
{
	North,
	South,
	East,
	West,
};

class Movable
{
public:
	Movable();
	~Movable();
	int x;
	int y;
private:
	SpriteSheet OutofBattle;
};