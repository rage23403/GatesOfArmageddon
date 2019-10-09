#pragma once

#include "Lifeform.h"

 

class MagicLifeform : public Lifeform
{
public:
	MagicLifeform();
	~MagicLifeform();
	int MP;
	int MaxMP;
private:
};