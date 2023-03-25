#include "Terrain.h"

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
}

void Terrain::SaveHeight(Heightmap)
{
}
