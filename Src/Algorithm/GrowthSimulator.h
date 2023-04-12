#pragma once
#include <span>
#include <utility>
#include "Common.h"
#include "Tree.h"
#include "Terrain.h"

class GrowthSimulator
{
protected:
	// TODO pass by reference through grow method
	std::vector<Tree> treeList;
	std::vector<std::pair<ColoredPoint, ColoredPoint>> ve;
public:
	GrowthSimulator() = default;
	GrowthSimulator(std::vector<Tree> treeList);
	std::vector<std::pair<ColoredPoint, ColoredPoint>>& Grow();
};