#pragma once

#include "Renderer.h"
#include "SDLRenderer.h"
#include "Algorithm\Terrain.h"
#include "Algorithm\AllocatorAlgorithm.h"
#include "Algorithm\RandomAllocator.h"
#include "Algorithm\Tree.h"
#include <filesystem>

class Engine
{
	Terrain terrain;
	Renderer* renderer;
	AllocatorAlgorithm* allocator;
	std::vector<Tree> treeVector;

public:
	Engine();
	~Engine();
	//user input will be returning AllocatorType to choose from which allocator call the placement method
	void run(AllocatorType allocType);
	void cleanup();
};