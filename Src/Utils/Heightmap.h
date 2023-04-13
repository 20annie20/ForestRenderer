#pragma once
#include "Common.h"

/// Heightmap data structure
/** Structure stores data for the terrain generation in a form of a buffer
of size X and Y, representing width and length. It is used to transfer data 
from a bitmap surface file to an array of heights that can be indexed as
one dimensional buffer or by using 2D coordinates.*/
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
	Heightmap();
	Heightmap(const Heightmap&);
	Heightmap(Heightmap&&); // (move constructor)
	Heightmap& operator=(const Heightmap&);
	Heightmap& operator=(Heightmap&&);
	~Heightmap();
	Heightmap(int x, int y);
	//void GenerateHeight(); perlin noise
	int GetSizeX();
	int GetSizeY();
	float GetHeight(int x, int y);
	float GetHeight(int i);
	void SetHeight(int x, int y, float value);
	void SetMapBuffer(void* pixels);
	void Swap(Heightmap&);
};