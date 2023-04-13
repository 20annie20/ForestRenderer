#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"
#include <random>

/// Allocator of trees that places them randomly
/** Allocator finds placement of each tree on the terrain surface. It first picks the placement randomly
but then find a random centroid for each species and moves tree towards it.
Allocation points are to be used in growth simulation. */
class RandomAllocator : public AllocatorAlgorithm
{
	void Allocate(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList, Terrain& terrain);
};