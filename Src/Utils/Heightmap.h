#pragma once
#include "Common.h"

struct Heightmap
{
private:
	int sizeX, sizeY;

	union mapBuffer
	{
		uint8_t* mapBuffer;
		void* pixels;
	};

	union mapBuffer map;

public:
	Heightmap() = default;
	Heightmap(int x, int y);
	//void GenerateHeight(); perlin noise
	int GetSizeX();
	int GetSizeY();
	float GetHeight(int x, int y);
	float GetHeight(int i);
	void SetHeight(int x, int y, float value);
	void SetMapBuffer(void* pixels);
};