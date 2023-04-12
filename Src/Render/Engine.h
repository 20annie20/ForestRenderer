#pragma once

#include "Renderer.h"
#include "SDLRenderer.h"
#include "Algorithm\Terrain.h"
#include "Algorithm\AllocatorAlgorithm.h"
#include "Algorithm\RandomAllocator.h"
#include "Algorithm\Tree.h"
#include <filesystem>
#include "Utils\Timer.h"
#include "Algorithm\GrowthSimulator.h"

enum class EngineState
{
	SETUP_MENU,
	SIMULATION
};

class Engine
{
	Terrain* terrain;
	Renderer* renderer;
	GUI* gui;
	AllocatorAlgorithm* allocator;
	GrowthSimulator simulator;
	std::vector<Tree> treeVector;
	// to do move to UI
	Timer timer;
	SDL_Event event;
	bool growIndependently = true;
	EngineState state = EngineState::SETUP_MENU;

public:
	Engine();
	void Init(AllocatorType allocType);
	void Cleanup();
	//user input will be returning AllocatorType to choose from which allocator call the placement method
	void Run(bool growIndependently);
	void SetState(EngineState state);
	~Engine();
};