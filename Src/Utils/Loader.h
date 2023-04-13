#pragma once
#include "Common.h"

/// File content loader class
/** Utility class that reads data from system files and stores them in the program datatypes
for further processing. */
class Loader
{
	const char* resourcesPath = "./resources/";
	
public:
	/// function reading SDL surface from a bitmap file
	/**
	* Tries to open file from path and load data into SDL_Surface
	* \param resourceName - relative path to the accessed resource
	* \return SDL surface type read from file
	*/
	static SDL_Surface* GetSurfaceFromBitmap(const char* resourceName);
};