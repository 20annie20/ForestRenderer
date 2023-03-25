#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>

enum ColorType
{
	Orange,
	Brown,
	Yellow,
	Grey
};

struct Point {
	float x, y, z;
	ColorType color;
};