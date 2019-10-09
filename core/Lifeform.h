#pragma once

#include "common.h"
#include "SpriteSheet.h"
#include "TileMap.h"

using namespace std;

class Lifeform
{
public:
	Lifeform();
	~Lifeform();
	string Name;
	int HP;
	int MaxHP;
	int Mons;
	int Exp;
	int Dmg;
	int Def;
private:
	SpriteSheet InBattle;
};