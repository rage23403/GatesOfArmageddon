#pragma once
#include "common.h"
#include "SpriteSheet.h"

enum GameState
{
	Init,
	Running,
	Paused,
	Done,
};
class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	bool run();
protected:
	bool init();
	void quit();
	void update();
	
	GameState state = Init;

private:
	//The window we'll be rendering to

	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	SpriteSheet knightSheet;
	SpriteSheet tileSheet;
	int ani = 0;
	int y = 0;

};

