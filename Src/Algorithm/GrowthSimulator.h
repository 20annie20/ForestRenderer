#pragma once
#include <span>
#include <utility>
#include "Common.h"
#include "Tree.h"
#include "Terrain.h"

class GrowthSimulator
{
protected:
	std::vector<Tree> treeList;
	Terrain terrain;
	std::vector<std::pair<ColoredPoint, ColoredPoint>> ve;
public:
	GrowthSimulator() = default;
	GrowthSimulator(std::vector<Tree> treeList, Terrain terrain);
	std::vector<std::pair<ColoredPoint, ColoredPoint>> Grow();
};