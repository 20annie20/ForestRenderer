#pragma once
#include "Common.h"
#include "AllocatorAlgorithm.h"
#include <random>

class OptimisedAllocator : public AllocatorAlgorithm
{
	std::unordered_map<Species_ID, Point> centroids;

	void FindCentroids(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList);
	void Allocate(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList, Terrain& terrain);
};