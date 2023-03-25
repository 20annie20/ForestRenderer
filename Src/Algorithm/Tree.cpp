#include "Tree.h"

Tree::Tree(Species species)
{
	this->species = species;
	this->x = 0;
	this->z = 0;
}

void Tree::SetLocation(int x, int z)
{
	this->x = x; this->z = z;
}

Point Tree::GetLocation()
{
	Point point = { x, 0, z, ColorType::Green };
	return point;
}
