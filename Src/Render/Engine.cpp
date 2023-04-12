#pragma once
#include "Engine.h"
#include <chrono>
#include <thread>

#include <Windows.h>

#define MAX_TICKS 1000

Engine::Engine()
{
	gui = new GUI(*this);
	renderer = new SDLRenderer();
	iterations = 0;
	growIndependently = true;
	terrainSize = Point(0, 0, 0);
	
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

void Engine::Run(bool growIndependently)
{
	allocator->Allocate(treeVector, *terrain);
	Point range = Point(200, terrain->GetMapSize().first / 3, terrain->GetMapSize().second);

	simulator = GrowthSimulator(treeVector);

	bool doQuit = false;
	bool startedSim = false;
	float timeSinceLastGrow = 0;
	std::vector<std::pair<ColoredPoint, ColoredPoint>> lines;
	std::vector<ColoredPoint> points = terrain->GetPoints<ColoredPoint>();
	lines.reserve(2'000'000'000 / 16);
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
				timeSinceLastGrow = 0;
				lines.clear();
				treeVector.clear();
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
				allocator->Allocate(treeVector, *terrain);
				range = Point(200, terrain->GetMapSize().second / 3, terrain->GetMapSize().first);
				simulator = GrowthSimulator(treeVector);
				points = terrain->GetPoints<ColoredPoint>();
			}
			
			if (iterations < MAX_TICKS && timeSinceLastGrow > 0.001) {
				auto& newLines = simulator.Grow();
				lines.insert(lines.end(), newLines.begin(), newLines.end());
				timeSinceLastGrow = 0;
				iterations++;
			}
			
			renderer->DrawPoints(points, range);
			renderer->DrawEdges(lines, range);
			renderer->DrawGUI(*gui, &GUI::DrawFrame);
			const auto sec = timer.Mark(); // seconds counter
			timeSinceLastGrow += sec;

			char buf[32];
			sprintf(buf, "%f\n", sec);
			OutputDebugStringA(buf);
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