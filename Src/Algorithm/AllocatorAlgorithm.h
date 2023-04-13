#pragma once
#include "Common.h"
#include "Tree.h"
#include "Terrain.h"

enum AllocatorType
{
	RANDOM,
	OPTIMISED
};

/// Allocator algorithm interface
/** Interface for classes responsible for assinging location on a terrain for each tree. Based on terrain data
for each given tree it allocates a width and length coordinate and beginning height of this place terrain height */
class AllocatorAlgorithm
{
public:
	virtual ~AllocatorAlgorithm() {};
	/**
	* \brief Asigns each tree a Point coordinate using terrain height and width, length coordinates
	* \param[in] tm tree map with amount of trees for each species
	* \param[out] treeList contains all trees with their location to set
	* \param[in] terrain is the terrain data with heights needed to set starting points of the trees
	*/
	virtual	void Allocate(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList, Terrain& terrain) = 0;
};