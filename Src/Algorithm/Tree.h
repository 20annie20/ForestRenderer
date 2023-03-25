#pragma once
#include "Common.h"

class Tree {
public:
	enum Species
	{
		Maple,
		Pine,
		Oak
	};
private:
	Species species;
	float x, z;
	// branches tree struct
	// rules definition

public:

	Tree();
	Tree(Species species);
	void SetLocation(int x, int z);
	Point GetLocation();
};