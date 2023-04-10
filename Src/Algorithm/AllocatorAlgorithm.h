#pragma once
#include "Common.h"
#include "Tree.h"
#include "Terrain.h"

enum AllocatorType
{
	Random,
	Cluster
};

class AllocatorAlgorithm
{
public:
	virtual	void Allocate(std::vector<Tree>& treeList,Terrain& terrain) = 0;
};