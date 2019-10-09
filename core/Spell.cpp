#include "Spell.h"

Spell::Spell(int m, int d)
{
	MPCost = m;
	Damage = d;
}

Spell::~Spell()
{
	
}

int Spell::Cast(int MP)
{
	if(MP < MPCost)
	{
		return 0;
	}
	return Damage;
}
int Spell::CastTwo(int MP)
{
	MP -= MPCost;
	return MP;
}