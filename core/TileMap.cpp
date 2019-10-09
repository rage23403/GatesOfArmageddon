#include "TileMap.h"
#include "pugixml.hpp"

#include <map>

using namespace pugi;


TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

bool TileMap::load(const char* fileName)
{
	xml_document mapFile;

	pugi::xml_parse_result result = mapFile.load_file("resources\\level_01.tmx");
	// width="50" height="50" tilewidth="32" tileheight="32"

	xml_node map = mapFile.first_child();
	mapSize.width = map.attribute("width").as_int();
	mapSize.height = map.attribute("height").as_int();
	tileSize = { map.attribute("tilewidth").as_int(), map.attribute("tileheight").as_int()};

	this->map = new Tile[mapSize.width * mapSize.height];

	_RPT1(0, "MAP SIZE: %d\r\n", tileSize.width * tileSize.height);

	int firstGid = map.child("tileset").attribute("firstgid").as_int();

	const char* tileMap = map.child("tileset").attribute("source").as_string();
	char tileMapName[255];
	strcpy(tileMapName, "resources\\");
	strcat(tileMapName, tileMap);

	xml_document tileMapFile;
	result = tileMapFile.load_file(tileMapName);
	xml_node image = tileMapFile.first_child().child("image");
	strcpy(tileMapName, "resources\\");
	strcat(tileMapName, image.attribute("source").as_string());

	std::map<int, int> typeMap;
	auto tiles = tileMapFile.first_child().children("tile");
	typeMap[0] = 0;

	for (auto tileNode : tiles) {
		typeMap[tileNode.attribute("id").as_int()] = tileNode.attribute("type").as_int();
	}

	/*
	 <image source="D:/work/tileset_new.png" width="512" height="512"/>
 <tile id="1" type="1"/>
 <tile id="6" type="2"/>
 <tile id="7" type="2"/>
 <tile id="17" type="2"/>
	*/


	Size tileMapSize = { image.attribute("width").as_int(), image.attribute("height").as_int() };

	if(!sheet.init(tileMapName, tileMapSize, tileSize))
	{
		cout << "Failed to load sprite sheet" << endl;
		return false;
	}

	int columns = tileMapSize.width / tileSize.width;
	int rows = tileMapSize.height / tileSize.height;

	this->tiles = new Tile[(columns) * (rows)];

	_RPT1(0, "NUM TILES: %d\r\n", (columns) * (rows));

	int tileId = 0;

	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			tileId++;

			this->tiles[tileId - 1] = { x, y, (TileType)tileMap[tileId] };
		}
	}

	this->tiles[0] = { -1, -1, (TileType)0 };


	const char* mapData = map.child("layer").child("data").first_child().value();
	loadMap(mapData, firstGid);

	return true;
}

void TileMap::draw(SDL_Surface* surface, Point p)
{
	for(int y = 0; y < mapSize.height - 1; y++)
	{
		for (int x = 0; x < mapSize.width - 1; x++)
		{
			SDL_Rect dst = { p.x + (x * tileSize.width), p.y + (y * tileSize.height), tileSize.width, tileSize.height };
			Tile t = map[x + (y * mapSize.width)];

			if (t.x != -1) {
				sheet.draw(surface, { t.x, t.y }, dst);
			}
		}
	}
}

void TileMap::loadMap(const char* mapData, int firstGid)
{
	size_t len = strlen(mapData);
	char buff[8];
	int bufflen = 0;
	int curTile = 0;

	for(int i = 0; i < len; i++)
	{
		char c = mapData[i];
		
		if(isdigit(c))
		{
			buff[bufflen] = c;
			bufflen++;
			buff[bufflen] = 0;
		}
		else if(c == ',')
		{
			int n = atoi(buff);

			if (n != 0) {
				n -= firstGid;
			}

			map[curTile] = tiles[n];

			_RPT2(0, "SET TILES: %d to %d\r\n", curTile, n);

			curTile++;
			bufflen = 0;
		}
	}
}
