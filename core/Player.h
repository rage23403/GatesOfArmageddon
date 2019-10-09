#pragma once

#include "MagicLifeform.h"
#include "Movable.h"

enum PotionSize
{
	Small,
	Normal,
	Large,
};

enum PotionType
{
	Magic,
	Healing,
};

struct Potion
{
	PotionType type;
	PotionSize size;
	string name;
};

class Player : public MagicLifeform , public Movable
{
public:
	Player();
	~Player();
private:
	
};