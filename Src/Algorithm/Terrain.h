#pragma once
#include "Utils/Heightmap.h"
#include "Utils/Loader.h"
#include "Common.h"

class Terrain {
	Heightmap heightmapDTO; // composed heightmap

public:
	Terrain();
	~Terrain();

	void LoadHeightMapFromFile(const char* filePath); // get surface from loader, transform it to heightmap
	void GenerateHeight();
	void SaveHeight(Heightmap); 
	// ewentualnie jakieœ info o kolorze
};