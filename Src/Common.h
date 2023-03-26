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
	Green,
	DarkGreen,
	Purple
};

// TODO move to point file and include 
struct Point {
	float x, y, z;
	
	Point() = default;
	Point(float x, float y, float z) : x(x), y(y), z(z) {};

	Point operator+ (const Point& first) const
	{
		return Point(x + first.x, y + first.y, z + first.z);
	}
	
	Point operator- (const Point& first) const
	{
		return Point(x - first.x, y - first.y, z - first.z);
	}
};

struct ColoredPoint : Point {
	ColorType color;

	ColoredPoint() = default;

	ColoredPoint(float x, float y, float z) : Point(x,y,z) {
		if (y < 160.0)
			color = Brown;
		else if (y < 180.0)
			color = Orange;
		else if (y < 200.0)
			color = Yellow;
		else
			color = Grey;
	};

	ColoredPoint(float x, float y, float z, ColorType color) : Point(x, y, z), color(color) {};
};