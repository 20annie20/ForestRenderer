#include "Terrain.h"
#include <vector>

Terrain::~Terrain()
{
}

void Terrain::LoadHeightMapFromFile(const char* filePath)
{
	SDL_Surface* bitmap = Loader::GetSurfaceFromBitmap(filePath);
	heightmapDTO = Heightmap(bitmap->w, bitmap->h);
	heightmapDTO.SetMapBuffer(bitmap->pixels);
}

void Terrain::GenerateHeight(int width, int length, int height)
{
	heightmapDTO = Heightmap(width, length);
	PerlinNoise pn;

	for (unsigned int i = 0; i < length; ++i) {     // y
		for (unsigned int j = 0; j < width; ++j) {  // x
			double x = (double)j / ((double)width);
			double y = (double)i / ((double)length);

			// Typical Perlin noise
			double n = pn.Noise(10 * x, 10 * y, 0.8) * height;
			heightmapDTO.SetHeight(j, i, n);
		}
	}
	
}

void Terrain::SaveHeight()
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
