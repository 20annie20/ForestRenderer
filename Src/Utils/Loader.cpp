#pragma once
#include "Loader.h"

SDL_Surface* Loader::GetSurfaceFromBitmap(const char* resourceName)
{
	SDL_Surface* image = SDL_LoadBMP(resourceName);
	if (image == NULL)
	{
		throw std::invalid_argument("Heightmap not found");
	}
	return image;
}
