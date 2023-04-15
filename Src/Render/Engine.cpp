#pragma once
#include "Engine.h"
#include <chrono>
#include <thread>

#include <Windows.h>

#define MAX_TICKS 10000

Engine::Engine()
{
	gui = new GUI(*this);
	renderer = new SDLRenderer();
	iterations = 0;
	growIndependently = true;
	terrainSize = Point(0, 0, 0);
	branches = 0;
	speed = 0.001;
	
	for (const auto& i : allSpecies)
	{
		treesMap[i] = 0;
	}
}

void Engine::Init(AllocatorType allocType, TerrainType terrainType)
{
	switch (allocType)
	{
	case RANDOM:
		allocatorFactory = new RandomAllocatorFactory();
	break;
	case OPTIMISED:
		allocatorFactory = new OptimisedAllocatorFactory();
		break;
	default:
		allocatorFactory = new RandomAllocatorFactory();
		break;
	}
	terrain = new Terrain();
	if (terrainType == FROM_MAP)
	{
		terrain->LoadHeightMapFromFile("Resources/Heightmap_Rocky.bmp");
	}
	else
	{
		terrain->GenerateHeight(terrainSize.x, terrainSize.y, terrainSize.z);
	}

	SetAllocator(*allocatorFactory);
}

Engine::~Engine()
{
	Cleanup();
	delete renderer;
}

void Engine::Run()
{
	allocator->Allocate(treesMap, treeVector, *terrain);
	Point range = Point(200, terrain->GetMapSize().first / 3, terrain->GetMapSize().second);

	simulator = GrowthSimulator(treeVector);

	bool doQuit = false;
	bool startedSim = false;
	float timeSinceLastGrow = 10;
	
	std::vector<ColoredPoint> points = terrain->GetPoints<ColoredPoint>();
	std::vector<std::pair<ColoredPoint, ColoredPoint>> lines;
	
	while (!doQuit)
	{
		while (SDL_PollEvent(&event)) 
		{
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT || (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE))
				doQuit = true;
			break;
		}
		renderer->Clear();

		if (state == EngineState::SETUP_MENU)
		{
			if (startedSim) // clean up previous simulation data
			{
				startedSim = false;
				iterations = 0;
				branches = 0;
				timeSinceLastGrow = 10;
				lines.clear();
				treeVector.clear();
				if (allocatorFactory)
				{
					delete allocatorFactory;
				}
				if (allocator)
				{
					delete allocator;
				}
			}
			renderer->DrawGUI(*gui, &GUI::DrawStartupFrame);
		}

		else
		{
			if (!startedSim)
			{
				for (const auto& i : treesMap)
				{
					for (auto j = 0; j < i.second; j++)
					{
						treeVector.push_back(Tree(i.first));
					}
				}
				startedSim = true;
				allocator->Allocate(treesMap, treeVector, *terrain);
				range = Point(200, terrain->GetMapSize().second / 3, terrain->GetMapSize().first);
				simulator = GrowthSimulator(treeVector);
				points = terrain->GetPoints<ColoredPoint>();
				renderer->DrawPoints(points, range);
			}
			
			if (iterations < MAX_TICKS && timeSinceLastGrow > (10 - speed)) {
				lines = simulator.Grow();
				branches += lines.size();
				timeSinceLastGrow = 0;
				iterations++;
			}

			renderer->DrawEdges(lines, range);
			renderer->RenderFromTexture();
			renderer->DrawGUI(*gui, &GUI::DrawFrame);
			const auto sec = timer.Mark(); // seconds counter
			timeSinceLastGrow += sec;
		}
		renderer->Present();
	}
}

void Engine::Cleanup()
{
	delete allocator;
	delete terrain;
}

void Engine::SetState(EngineState state)
{
	this->state = state;
}

void Engine::SetSpeed(float speed)
{
	this->speed = speed;
}

void Engine::SetTerrainSize(Point size)
{
	terrainSize = size;
}

void Engine::SetAllocator(const AllocatorFactory &factory)
{
	this->allocator = factory.CreateAllocator();
}

std::unordered_map<Species_ID, int>& Engine::GetSpecies()
{
	return treesMap;
}

int Engine::GetIterations() const
{
	return iterations;
}

int Engine::GetBranches() const
{
	return branches;
}