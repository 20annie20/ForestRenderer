#include "Tree.h"

Tree::Tree(Species species)
{
	this->species = species;
	this->x = 0;
	this->y = 0;
}

void Tree::SetLocation(int x, int y)
{
	this->x = x; this->y = y;
}

Point Tree::GetLocation()
{
	Point point = { x, y, 0, ColorType::Green };
	return point;
}
