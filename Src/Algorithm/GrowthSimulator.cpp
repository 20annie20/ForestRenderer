#pragma once
#include "GrowthSimulator.h"

GrowthSimulator::GrowthSimulator(std::vector<Tree> treeList, Terrain terrain)
{
	this->treeList = treeList;
	this->terrain = terrain;
}

std::span<std::pair<Point, Point>> GrowthSimulator::Grow()
{ 
	std::vector<std::pair<Point, Point>> branches;
	for (auto& tree : treeList)
	{
		branches = tree.Grow();
	}
	for( auto& branch : branches )
		ve.push_back(branch);

	return ve;
}