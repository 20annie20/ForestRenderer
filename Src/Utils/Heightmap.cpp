#include "Heightmap.h"
#include <iostream>

Heightmap::Heightmap() 
{
	map.mapBuffer = nullptr;
	sizeX = 0;
	sizeY = 0;
}

Heightmap::Heightmap(const Heightmap& hm) : Heightmap()
{
	if (hm.map.mapBuffer != nullptr)  
	{
		sizeX = hm.sizeX;
		sizeY = hm.sizeY;
		try
		{
			map.mapBuffer = new uint8_t[sizeX * sizeY];
			memcpy(map.mapBuffer, hm.map.mapBuffer, sizeX * sizeY);
		}
		catch (const std::bad_alloc& e) {
			std::cerr << "Allocation failed: " << e.what() << '\n';
		}
	}
}

Heightmap::Heightmap(Heightmap&& hm)
{
	sizeX = std::exchange(hm.sizeX, 0);
	sizeY = std::exchange(hm.sizeY, 0);
	map.mapBuffer = std::exchange(hm.map.mapBuffer, nullptr);
}

Heightmap::Heightmap(int x, int y)
{
	sizeX = x;
	sizeY = y;
	try 
	{
		map.mapBuffer = new uint8_t[sizeX * sizeY];
	}
	catch (const std::bad_alloc& e) 
	{
		std::cerr << "Allocation failed: " << e.what() << '\n';
	}
}

Heightmap& Heightmap::operator=(const Heightmap& hm)
{
	Heightmap(hm).Swap(*this);
	return *this;
}

Heightmap& Heightmap::operator=(Heightmap&& hm)
{
	Heightmap(std::move(hm)).Swap(*this);
	return *this;
}

int Heightmap::GetSizeX()
{
	return sizeX;
}

int Heightmap::GetSizeY()
{
	return sizeY;
}

float Heightmap::GetHeight( int x, int y )
{
	return map.mapBuffer[x + y * sizeX];
}

float Heightmap::GetHeight( int i )
{
	return map.mapBuffer[i];
}

void Heightmap::SetHeight( int x, int y, float value )
{
	map.mapBuffer[x + y * sizeX] = value;
}

void Heightmap::SetMapBuffer( void* pixels )
{
	memcpy(map.pixels, pixels, sizeX * sizeY);
}

Heightmap::~Heightmap()
{
	delete[] map.mapBuffer;
}

void Heightmap::Swap(Heightmap& hm)
{
	std::swap(sizeX, hm.sizeX);
	std::swap(sizeY, hm.sizeY);
	std::swap(map.mapBuffer, hm.map.mapBuffer);
}
