#pragma once
#include "Common.h"

/** 
 * \brief Structure stores data for the terrain generation in a form of a buffer
 *		of size X and Y, representing width and length. It is used to transfer data 
 *		from a bitmap surface file to an array of heights that can be indexed as
 *		one dimensional buffer or by using 2D coordinates.
 */
struct Heightmap
{
private:
	int sizeX, sizeY;

	union mapBuffer
	{
		uint8_t* mapBuffer;
		void* pixels;
	};

	union mapBuffer map;

public:
	/**
	* \brief Constructs an empty heightmap.
	*/
	Heightmap();

	/**
	* \brief Constructs a new heightmap of a given size (x,y).
	* \param x - Width of the heightmap (max longitude).
	* \param y - Depth of the heightmap (max latitude).
	*/
	Heightmap(int x, int y);

	Heightmap(const Heightmap&);
	Heightmap(Heightmap&&);
	Heightmap& operator=(const Heightmap&);
	Heightmap& operator=(Heightmap&&);

	/**
	* \brief Destroys the heightmap.
	*/
	~Heightmap();

	//void GenerateHeight(); perlin noise

	/**
	* \returns Width of the heightmap (max longitude) - number of points in X
	*		dimension of the heightmap.
	*/
	int GetSizeX();

	/**
	* \returns Depth of the heightmap (max latitude) - number of points in Y
	*		dimension of the heightmap.
	*/
	int GetSizeY();

	/**
	* \brief Returns height defined for a given point defined by (x,y) coordinates.
	* \param x - Longitude of the point.
	* \param y - Latitude of the point.
	* \returns Height at the given coordinates.
	*/
	float GetHeight(int x, int y);

	/**
	* \brief Returns height defined for a given point defined by an index to the
	*		heightmap buffer.
	* \param i - Index to the buffer.
	* \returns Height at the given index.
	*/
	float GetHeight(int i);

	/**
	* \brief Sets a new height for a given point defined by (x,y) coordinates.
	* \param x - Longitude of the point.
	* \param y - Latitude of the point.
	* \param value - New height.
	*/
	void SetHeight(int x, int y, float value);

	/**
	* \brief Copies height data from a pixel array to the heightmap buffer.
	* \param pixels - Pixel array. Pixels must be arranged row-by-row. Each row must
	*		contain SizeX bytes. There must be SizeY rows in the array.
	*/
	void SetMapBuffer(void* pixels);

	/**
	* \brief Swaps two heightmaps.
	*/
	void Swap(Heightmap&);
};