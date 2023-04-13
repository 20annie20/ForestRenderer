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
	/**
	* \brief Constructor that passes treeList that is then used in the growing simulation
	*/
	GrowthSimulator(std::span<Tree> treeList);
	/**
	* \brief Runs one iteration of growth process on all the trees  stored in the treeList
	* \returns all the branches that were created in this iteration
	*/
	std::vector<std::pair<ColoredPoint, ColoredPoint>>& Grow();
};