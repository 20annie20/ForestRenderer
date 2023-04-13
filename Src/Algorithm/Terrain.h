#pragma once
#include "Utils/Heightmap.h"
#include "Utils/Loader.h"
#include <span>
#include <vector>
#include "Common.h"
#include "PerlinNoise.h"

enum TerrainType
{
	FROM_MAP,
	PERLIN
};

class Terrain {

	enum SoilType
	{
		MUD,
		CLAY,
		SAND,
		STONES
	};

	Heightmap heightmapDTO; // composed heightmap

public:
	~Terrain();

	void LoadHeightMapFromFile(const char* filePath); // get surface from loader, transform it to heightmap
	void GenerateHeight(int, int, int);
	std::pair<int, int> GetMapSize(); 
	int GetHeight(int i, int j);

	template <typename T>
	std::vector<T> GetPoints();
};

template <typename T>
std::vector<T> Terrain::GetPoints()
{
	std::vector<T> points;
	points.reserve(heightmapDTO.GetSizeX() * heightmapDTO.GetSizeY());

	for (int i = 0; i < heightmapDTO.GetSizeX(); i++)
	{
		for (int j = 0; j < heightmapDTO.GetSizeY(); j++)
		{
			points.emplace_back(i, heightmapDTO.GetHeight(i,j), j);
		}
	}

	return points;
}