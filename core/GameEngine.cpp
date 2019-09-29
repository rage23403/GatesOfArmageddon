#include "GameEngine.h"

const int TARGET_FPS = 60;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
}

bool GameEngine::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	SDL_Init(IMG_INIT_PNG);

	//Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	screenSurface = SDL_GetWindowSurface(window);


	knightSheet.init("d:\\work\\knightframes.png", { 256, 256 }, { 32, 32 });
	//tileSheet.init("d:\\work\\tileset_new.png", { 512, 512 }, { 32, 32 });

	if (!map.load("resources\\level_01.tmx")) {
		cout << "Failed to load map" << endl;
		return false;
	}

	return true;
}

void GameEngine::quit() 
{
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
}

bool GameEngine::run()
{
	if (!init()) 
	{
		return false;
	}
	state = Running;

	long targetFrameTime = 1000 / TARGET_FPS;
	long start = SDL_GetTicks();
	int count = 0;

	while(state != Done)
	{
		long prev = SDL_GetTicks();
		update();

		long end = SDL_GetTicks();
		long frameTime = end - prev;

		if (frameTime < targetFrameTime) 
		{
			SDL_Delay(targetFrameTime - frameTime);
		}

		if (end - start >= 1000) {
			_RPT1(0, "FPS: %d\r\n", count);
			count = 0;
			start = end;
		}

		count++;
	}

	quit();

	return true;
}

void GameEngine::update()
{
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	map.draw(screenSurface, { 0, -y });

	ani++;

	if (ani > 7) {
		ani = 0;
	}

	SDL_Rect dst;
	dst.x = 32;
	dst.y = y;
	dst.w = 32;
	dst.h = 32;

	y += 1;

	knightSheet.draw(screenSurface, { ani, 0 }, dst);
	SDL_UpdateWindowSurface(window);

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			state = Done;
			break;
		}
	}
}
