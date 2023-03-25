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
	int x, y;
	// branches tree struct
	// rules definition

public:

	Tree();
	Tree(Species species);

	void setLocation(int x, int y);
};