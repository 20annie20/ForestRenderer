#pragma once
#include "Common.h"
#include "Rule.h"
#include "SpeciesTable.h"
#include <span>
#include <deque>

/// Class used for each tree simulation
/** Tracks information about the tree using information from SpeciesTable.
* Has to be initalized with a value of SpeciesID enum to determine the generation behaviour.
* Keeps track of the tree state using three double-sided lists: rules to process, starting points for the beginning
* of new branches, angles of the new branches. In each iteration one from each list is taken from the end like from
* a stack. New items are put at the beginning or end of the list depending on the rule that invoked them.
*/
class Tree 
{
	
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
		std::deque<Rule*> rules;		  // running rules stack ( replacements happen so vector not queue)
		std::deque<Point> startingPoints; // starting points stack
		std::deque<Point> startingAngles; // starting angles stack
	};

	Species_ID species;
	TreeData td;
	TreeStacks stacks;	

	std::pair<Point, Point> branch; // can be only one branch per iteration

public:
	Tree() = default;
	Tree(Species_ID species);

	/**
	* \brief Sets the location of the tree in the terrain.
	* \param x - Longitude of the tree's root.
	* \param y - Latitude of the tree's root.
	*/
	void SetLocation(int x, int y);

	/**
	* \brief Sets the location of the tree in the terrain.
	* \param p - Point that defines longitude and latitude of the tree's root.
	*/
	void SetLocation(Point p);

	/**
	* \returns Location (longitude and latitude) of the tree's root.
	*/
	Point GetLocation();

	/**
	* \brief Applies the next grow rule to the tree.
	* \returns Points that define the edge of the new branch.
	*/
	std::pair<Point, Point> Grow();

	/**
	* \brief Applies a grow rule to the tree.
	* \param rule - Rule to apply.
	*/
	inline void ApplyRule(Rule* Rule)
	{
		Rule->Apply(*this);
	}

};


