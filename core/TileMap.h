#pragma once

#include "SpriteSheet.h"

enum TileType
{
	None,
	Wall,
	Floor,
	Lava,
	Water,
};

struct Tile
{
	int x;
	int y;

	TileType type;

};
class TileMap
{
public:
	TileMap();
	~TileMap();
	bool load(const char* fileName);

	Size tileSize;
	Size mapSize;

	void draw(SDL_Surface* surface, Point p);
private:
	void loadMap(const char* mapData, int firstGid);

	SpriteSheet sheet;
	Tile* map;
	Tile* tiles;
};

