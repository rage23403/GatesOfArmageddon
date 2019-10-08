#pragma once
#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

struct Size
{
	int width;
	int height;
};

struct Point
{
	int x;
	int y;
};