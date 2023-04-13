#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"
#include <random>

class RandomAllocator : public AllocatorAlgorithm
{
	void Allocate(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList, Terrain& terrain);
};