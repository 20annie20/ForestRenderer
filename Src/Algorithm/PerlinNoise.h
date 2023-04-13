#pragma once
#include <vector>

#ifndef PERLINNOISE_H
#define PERLINNOISE_H

/// Perlin noise generating class
/** Taken from: https://github.com/sol-prog/Perlin_Noise/blob/master/PerlinNoise.cpp
Generates heights for the terrain using perlin noise.
Copyright 2012 Sol
*/
class PerlinNoise {
	// The permutation vector
	std::vector<int> p;

public:
	/**
	* \brief Constructs a perlin noise generator with a reference permutation vector.
	*/
	PerlinNoise();

	/**
	* \brief Constructs a perlin noise generator with a permutation vector based on the value of seed.
	* \param seed - Seed used for generation of the permutation vector.
	*/
	PerlinNoise(unsigned int seed);

	/**
	* \brief Computes perlin noise for a given (x,y,z) coordinates.
	* \param x - X coordinate of the point.
	* \param y - Y coordinate of the point.
	* \param z - Z coordinate of the point. Ignored if the image is 2D.
	* \returns A noise value at given 3D point defined by (x,y,z) coordinates.
	*/
	double Noise(double x, double y, double z);

private:
	double Fade(double t);
	double Lerp(double t, double a, double b);
	double Grad(int hash, double x, double y, double z);
};