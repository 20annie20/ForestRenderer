#pragma once
#include <span>
#include <utility>
#include "Common.h"
#include "Tree.h"
#include "Terrain.h"

/// Simulator of trees growth
/** Prepares vector of all currently used branches from the tree vector data 
adds according colors to be ready for rendering */
class GrowthSimulator
{
protected:
	std::span<Tree> treeList;
	std::vector<std::pair<ColoredPoint, ColoredPoint>> ve;
public:
	GrowthSimulator() = default;
	GrowthSimulator(std::span<Tree> treeList);
	std::vector<std::pair<ColoredPoint, ColoredPoint>>& Grow();
};