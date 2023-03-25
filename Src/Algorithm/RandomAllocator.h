#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"
#include <random>

class RandomAllocator : public AllocatorAlgorithm
{
	void SetTreeList(std::vector<Tree> treeList);
	void SetTerrain(Terrain terrain);
	std::span<Point> Allocate();
};