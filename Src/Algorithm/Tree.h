#pragma once
#include "Common.h"
#include "Rule.h"
#include "SpeciesTable.h"
#include <span>

class Tree {

private:
	Species_ID species;
	Point beginning;
	float branchLength;
	std::vector<IRule*> rules;
	std::vector<std::pair<Point, Point>> branches;

	template <typename T>
	void ApplyRule(T& Rule);

public:

	Tree() = default;
	Tree(Species_ID species);
	void SetLocation(int x, int z);
	void SetLocation(Point p);
	Point GetLocation();
	std::vector<std::pair<Point, Point>> Grow();
};

template<typename T>
inline void Tree::ApplyRule(T& Rule)
{
	Rule->apply(); //aplly(this)
}
