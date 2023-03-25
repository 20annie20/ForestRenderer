#pragma once
#include "Common.h"

struct Heightmap
{
private:
	int sizeX, sizeY;

	union mapBuffer
	{
		float* mapBuffer;
		void* pixels;
	};

	union mapBuffer map;

public:
	Heightmap() = default;
	Heightmap(int x, int y);
	//void GenerateHeight(); perlin noise
	float GetPoint(int x, int y);
	void SetPoint(int x, int y, float value);
	void SetMapBuffer(void* pixels);
};