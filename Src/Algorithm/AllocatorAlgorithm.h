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
	virtual	void Allocate(std::vector<Tree>& treeList,Terrain& terrain) = 0;
};