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
	Spell();
	~Spell();
private:
	int MPCost;
	int Damage;
};

