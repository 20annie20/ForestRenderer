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
protected:
	Terrain terrain;

public:
	virtual	void SetTerrain(Terrain terrain) = 0;
	virtual	void Allocate(std::vector<Tree>& treeList) = 0;
};