#include "Terrain.h"
#include <vector>

Terrain::Terrain()
{
	LoadHeightMapFromFile("Resources/Heightmap_Rocky.bmp");
}

Terrain::~Terrain()
{
}

void Terrain::LoadHeightMapFromFile(const char* filePath)
{
	SDL_Surface* bitmap = Loader::GetSurfaceFromBitmap(filePath);
	heightmapDTO = Heightmap(bitmap->w, bitmap->h);
	heightmapDTO.SetMapBuffer(bitmap->pixels);
}

void Terrain::GenerateHeight()
{
	// perlin noise generation based on user input x, y
}

void Terrain::SaveHeight(Heightmap)
{
}

std::pair<int, int> Terrain::GetMapSize()
{
	std::pair<int, int> pair = { heightmapDTO.GetSizeX(), heightmapDTO.GetSizeY() };
	return pair;
}

int Terrain::GetHeight(int x, int z)
{
	return heightmapDTO.GetHeight(x, z);
}
