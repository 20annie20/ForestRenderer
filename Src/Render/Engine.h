#pragma once

#include "Renderer.h"
#include "SDLRenderer.h"
#include "Algorithm\Terrain.h"
#include "Algorithm\AllocatorAlgorithm.h"

#include "Algorithm\AllocatorFactory.h"
#include "Algorithm\RandomAllocatorFactory.h"
#include "Algorithm\OptimisedAllocatorFactory.h"
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
	
	AllocatorFactory* allocatorFactory;
	AllocatorAlgorithm* allocator;
	GrowthSimulator simulator;

	std::vector<Tree> treeVector;

	GUI* gui;

	// TODO move to UI
	Timer timer;
	SDL_Event event;

	// application state
	bool growIndependently;
	EngineState state = EngineState::SETUP_MENU;
	std::unordered_map<Species_ID, int> treesMap;
	uint64_t iterations;

public:
	Engine();
	void Init(AllocatorType allocType);
	void Cleanup();
	//user input will be returning AllocatorType to choose from which allocator call the placement method
	void Run(bool growIndependently);
	void SetState(EngineState state);
	void SetAllocator(const AllocatorFactory &factory);
	int GetIterations() const;
	std::unordered_map<Species_ID, int>& GetSpecies();
	~Engine();
};