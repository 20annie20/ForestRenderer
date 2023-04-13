#pragma once
#include "Common.h"
#include "Tree.h"
#include "Terrain.h"

enum AllocatorType
{
	RANDOM,
	OPTIMISED
};

class AllocatorAlgorithm
{
public:
	virtual ~AllocatorAlgorithm() {};
	virtual	void Allocate(std::unordered_map<Species_ID, int>& tm, std::vector<Tree>& treeList,Terrain& terrain) = 0;
};