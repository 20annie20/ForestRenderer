#pragma once

#include "Renderer.h"
#include "SDLRenderer.h"
#include "Algorithm\Terrain.h"
#include "Algorithm\AllocatorAlgorithm.h"
#include "Algorithm\RandomAllocator.h"
#include "Algorithm\Tree.h"
#include <filesystem>
#include "Utils\Timer.h"

class Engine
{
	Terrain terrain;
	Renderer* renderer;
	AllocatorAlgorithm* allocator;
	std::vector<Tree> treeVector;
	Timer timer;
	SDL_Event event;

public:
	Engine();
	~Engine();
	//user input will be returning AllocatorType to choose from which allocator call the placement method
	void Run(AllocatorType allocType);
	void Cleanup();
};