#pragma once
#include "Common.h"

class Loader
{
	/** Path to all resources */
	const char* resourcesPath = "./resources/";

	/// function loading SDL surface from bitmap file
	/**
	* Tries to open file from path and load data into SDL_Surface
	*/
public:
	static SDL_Surface* GetSurfaceFromBitmap(const char* resourceName);
};