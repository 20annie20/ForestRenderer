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


/// Terrain generation class
/** Responsible for preparing terrain data to draw and to use in allocation simulation.
* Can read heightmap from file or generate random terrain using PerlinNoise class. 
* Asigns different colors based on the terrain height (assuming soil type depends on the height for simplicity).
*/
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

	/**
	* \brief Loads a heightmap from a bitmap.
	* \param filePath - path to the bitmap file with the terrain's height data.
	*/
	void LoadHeightMapFromFile(const char* filePath);

	/**
	* \brief Generates heightmap using a Perlin noise generator.
	* \param x - Width of the heightmap (max longitude).
	* \param y - Depth of the heightmap (max latitude).
	* \param z - Max height of the generated terrain.
	*/
	void GenerateHeight(int x, int y, int z);

	/**
	* \returns Size of the terrain's heightmap.
	*/
	std::pair<int, int> GetMapSize();

	/**
	* \brief Returns height defined for a given point defined by (x,y) coordinates.
	* \param x - Longitude of the point.
	* \param y - Latitude of the point.
	* \returns Height at the given coordinates.
	*/
	int GetHeight(int x, int y);

	/**
	* \returns Vector of points of given type constructed from positions of points in the terrain.
	*		Coordinates of each point are defined in the terrain's heightmap.
	*/
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