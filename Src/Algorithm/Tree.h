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
	float x, y;
	// branches tree struct
	// rules definition

public:

	Tree();
	Tree(Species species);
	void SetLocation(int x, int y);
	Point GetLocation();
};