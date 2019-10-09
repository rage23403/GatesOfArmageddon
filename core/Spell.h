#pragma once

#include "common.h"

enum CastType
{
	Shoot,
	Connect,
	Ontop,
};

enum SpellType
{
	Fire,
	Ice,
	Electric,
	Water,
	Dark,
};

class Spell
{
public:
	Spell(int m, int d);
	~Spell();
	int Cast(int MP);
	int CastTwo(int MP);
private:
	int MPCost;
	int Damage;
};

