#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>

enum ColorType
{
	Brown,
	Orange,
	Yellow,
	Grey,
	Green
};

struct Point {
	float x, y, z;
	ColorType color;
};