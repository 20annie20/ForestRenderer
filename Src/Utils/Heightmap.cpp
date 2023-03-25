#include "Heightmap.h"
#include <iostream>

Heightmap::Heightmap(int x, int y)
{
	sizeX = x;
	sizeY = y;
	try {
		map.mapBuffer = new float(sizeX * sizeY);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Allocation failed: " << e.what() << '\n';
	}
}

float Heightmap::GetPoint(int x, int y)
{
	return map.mapBuffer[x * sizeX + y];
}

void Heightmap::SetPoint(int x, int y, float value)
{
	map.mapBuffer[x * sizeX + y] = value;
}

void Heightmap::SetMapBuffer(void* pixels)
{
	map.pixels = pixels;
}
