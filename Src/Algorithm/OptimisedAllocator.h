#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"
#include <random>

class OptimisedAllocator : public AllocatorAlgorithm
{
	void Allocate(std::vector<Tree>& treeList, Terrain& terrain);
};