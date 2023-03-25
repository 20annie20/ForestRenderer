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

std::span<Point> Terrain::getPoints()
{
	Point tp;

	for( int i = 0; i < heightmapDTO.GetSizeX(); i++)
	{
		for (int j = 0; j < heightmapDTO.GetSizeY(); j++)
		{
			tp = Point();
			tp.x = float(i);
			tp.y = float(j);
			tp.z = heightmapDTO.GetHeight(i, j);
			tp.color = (ColorType) SoilType::Clay;
			terrainPoints.push_back(tp);
		}
	}
	std::span<Point> spanOut{ terrainPoints };
	
	return spanOut;
}

void Terrain::SaveHeight(Heightmap)
{
}
