#pragma once
#include "Utils/Heightmap.h"
#include "Utils/Loader.h"
#include <span>
#include <vector>
#include "Common.h"

class Terrain {
	enum SoilType
	{
		Mud,
		Clay,
		Sand,
		Stones
	};

	Heightmap heightmapDTO; // composed heightmap
	std::vector<Point> terrainPoints;

public:
	Terrain();
	~Terrain();

	void LoadHeightMapFromFile(const char* filePath); // get surface from loader, transform it to heightmap
	void GenerateHeight();
	std::span<Point> getPoints();
	void SaveHeight(Heightmap); 
};