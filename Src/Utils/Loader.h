#pragma once
#include "Common.h"

/**
 * \brief Utility class that reads data from system files and stores them in the program datatypes
 *		for further processing.
 */
class Loader
{
	const char* resourcesPath = "./resources/";
	
public:
	/**
	* \brief Tries to open file from path and load data into SDL_Surface
	* \param resourceName - relative path to the accessed resource
	* \returns SDL surface type read from file
	*/
	static SDL_Surface* GetSurfaceFromBitmap(const char* resourceName);
};