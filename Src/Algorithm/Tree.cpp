#include "Tree.h"

Tree::Tree(Species_ID species)
{
	this->species = species;
	this->beginning = Point(0, 0, 0);
	SpeciesTable st = SpeciesTable();
	SpeciesEntry& tableEntry = st.at(species);
	if (tableEntry.id == species)
	{
		this->branchLength = tableEntry.branchLength;
		this->rules = tableEntry.rules;
	}
	else
		throw std::domain_error("Tree species doesn't match the table entry.");
}

void Tree::SetLocation(int x, int z)
{
	this->beginning.x = x; this->beginning.z = z;
}

void Tree::SetLocation(Point p)
{
	this->beginning = p;
}

Point Tree::GetLocation()
{
	Point point = { beginning.x, 0, beginning.z, ColorType::Green };
	return point;
}

std::vector<std::pair<Point, Point>> Tree::Grow()
{
	for (auto& rule : rules)
	{
		ApplyRule(rule);
	}
	return branches;
}
