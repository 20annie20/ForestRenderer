#include "Tree.h"

SpeciesTable st = SpeciesTable();

Tree::Tree(Species_ID species)
{
	this->species = species;
	this->td.beginning = Point(0, 0, 0);
	SpeciesEntry tableEntry = st.at(species);
	if (tableEntry.id == species)
	{
		this->td.stackDepth = tableEntry.stackDepth;
		this->td.branchLength = tableEntry.branchLength;
		this->td.splitAmount = tableEntry.splitAmount;
		this->td.axioms = tableEntry.axioms;
		this->td.angleSplit = tableEntry.angle;
		this->stacks.rules = tableEntry.rules;
		this->stacks.startingAngles.push_back(Point(0.0f, 1.0f, 0.0f));
	}
	else
		throw std::domain_error("Tree species doesn't match the table entry.");
}

void Tree::SetLocation(int x, int z)
{
	this->td.beginning.x = x; this->td.beginning.z = z;
}

void Tree::SetLocation(Point p)
{
	this->td.beginning = p;
	this->stacks.startingPoints.push_back(td.beginning);
}

Point Tree::GetLocation()
{
	return td.beginning;
}

std::pair<Point, Point> Tree::Grow()
{
	td.angleSplit.x *= 1.005;
	td.angleSplit.y *= 1.005;
	td.angleSplit.z *= 1.005;

	if (!stacks.rules.empty())
	{
		IRule* rule = stacks.rules.back();
		stacks.rules.pop_back();
		ApplyRule(rule);
	}
	
	return branch;
}
