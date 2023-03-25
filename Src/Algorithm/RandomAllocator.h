#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"


class RandomAllocator : public AllocatorAlgorithm
{
	void setTreeList(std::vector<Tree> treeList);
	void setTerrain(Terrain terrain);
	std::span<Point> allocate();
};