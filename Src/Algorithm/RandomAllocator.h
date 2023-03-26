#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"
#include <random>

class RandomAllocator : public AllocatorAlgorithm
{
	void SetTerrain(Terrain terrain);
	void Allocate(std::vector<Tree>& treeList);
};