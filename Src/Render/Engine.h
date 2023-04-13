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
calling rendering and algorithmic components. Two main states are: setup and actual simulation. In 
setup user chooses parameters for the next simulation, in simulation firstly terrain generation is 
called, then trees are allocated and lastly the actual forest is rendered as it grows in time. */
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
	~Engine();

	/**
	* \brief Initializes the engine.
	* \param allocType - Tree allocator type to use.
	* \param terrainType - Terrain type to use.
	*/
	void Init(AllocatorType allocType, TerrainType terrainType);

	/**
	* \brief Releases all engine's resources.
	*/
	void Cleanup();

	/**
	* \brief Runs the application's main loop.
	*/
	void Run();

	/**
	* \brief Moves the engine into a new state.
	* \param state - New engine state.
	*/
	void SetState(EngineState state);

	/**
	* \brief Sets the size of terrain to generate on the next call to Init.
	* \param size - Size of the terrain.
	*/
	void SetTerrainSize(Point size);

	/**
	* \brief Sets the new tree allocator to use in the next simulation.
	* \param factory - Allocator factory.
	*/
	void SetAllocator(const AllocatorFactory &factory);

	/**
	* \brief Sets the speed of the simulation.
	* \param speed - Simulation speed.
	*/
	void SetSpeed(float speed);

	/**
	* \returns The current iteration number.
	*/
	int GetIterations() const;

	/**
	* \returns The number of branches in the current iteration.
	*/
	int GetBranches() const;

	/**
	* \returns The number of each tree species.
	*/
	std::unordered_map<Species_ID, int>& GetSpecies();
};