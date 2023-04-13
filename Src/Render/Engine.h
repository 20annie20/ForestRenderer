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

/// Main class of the application that binds together components
/** Engine is a class called from main and it is responsible for reacting to a state of application,
calling rendering and algorithmic components. */
class Engine
{
	Terrain* terrain;
	Point terrainSize;
	Renderer* renderer;
	
	AllocatorFactory* allocatorFactory;
	AllocatorAlgorithm* allocator;
	GrowthSimulator simulator;

	std::vector<Tree> treeVector;
	std::vector<std::pair<ColoredPoint, ColoredPoint>> lines;

	GUI* gui;

	Timer timer;
	SDL_Event event;

	// application state
	bool growIndependently;
	EngineState state = EngineState::SETUP_MENU;
	std::unordered_map<Species_ID, int> treesMap;
	uint64_t iterations;
	uint64_t branches;
	float speed = 0.001;

public:
	Engine();
	void Init(AllocatorType allocType, TerrainType terrainType);
	void Cleanup();
	//user input will be returning AllocatorType to choose from which allocator call the placement method
	void Run();
	void SetState(EngineState state);
	void SetTerrainSize(Point size);
	void SetAllocator(const AllocatorFactory &factory);
	void SetSpeed(float speed);
	int GetIterations() const;
	int GetBranches() const;
	std::unordered_map<Species_ID, int>& GetSpecies();
	~Engine();
};