#pragma once
#include "Common.h"
#include "Rule.h"
#include "SpeciesTable.h"
#include <span>
#include <deque>

class Tree {
	
// TODO add getters and setters and make private
public:
	struct TreeData
	{
		Point beginning;
		int stackDepth;
		int splitAmount;
		float branchLength;
		Point angleSplit;
		std::vector<std::string> axioms;
	};

	struct TreeStacks
	{
		std::deque<IRule*> rules;		  // running rules stack ( replacements happen so vector not queue)
		std::deque<Point> startingPoints; // starting points stack
		std::deque<Point> startingAngles; // starting angles stack
	};
	// TODO add getters and setters and make private
	Species_ID species;
	TreeData td;
	TreeStacks stacks;	

	std::pair<Point, Point> branch; // can be only one branch per iteration

public:

	Tree() = default;
	Tree(Species_ID species);
	void SetLocation(int x, int z);
	void SetLocation(Point p);
	Point GetLocation();


	std::pair<Point, Point> Grow();

	inline void ApplyRule(IRule* Rule)
	{
		Rule->Apply(*this);
	}

};


