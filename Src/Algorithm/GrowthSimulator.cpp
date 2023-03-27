#pragma once
#include "GrowthSimulator.h"

ColorType pickColor(Tree& tree)
{
	switch (tree.species) {
	case MAPLE:
		return Purple;
	case PINE:
		return DarkGreen;
	case OAK:
		return Green;
	}
}

GrowthSimulator::GrowthSimulator(std::vector<Tree> treeList)
{
	this->treeList = treeList;
}

std::vector<std::pair<ColoredPoint, ColoredPoint>> GrowthSimulator::Grow()
{ 
	std::vector<std::pair<Point, Point>> branches;
	ve.clear();

	for (auto& tree : treeList)
	{
		branches = tree.Grow();
		ColorType color = pickColor(tree);
		for (auto& branch : branches) {
			ve.push_back(std::pair<ColoredPoint, ColoredPoint>(
				{ branch.first.x, branch.first.y, branch.first.z, color },
				{ branch.second.x, branch.second.y, branch.second.z, color }));
		}
	}
	return ve;
}