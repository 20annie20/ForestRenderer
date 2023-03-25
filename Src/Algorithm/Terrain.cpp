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
			tp.y = heightmapDTO.GetHeight(i, j);
			tp.z = float(j);
			if (tp.y < 160.0)
				tp.color = (ColorType) SoilType::Stones;
			else if (tp.y < 180.0)
				tp.color = (ColorType) SoilType::Sand;
			else if (tp.y < 200.0)
				tp.color = (ColorType) SoilType::Clay;
			else
				tp.color = (ColorType) SoilType::Mud;
			
			terrainPoints.push_back(tp);
		}
	}
	std::span<Point> spanOut{ terrainPoints };
	
	return spanOut;
}

void Terrain::SaveHeight(Heightmap)
{
}
