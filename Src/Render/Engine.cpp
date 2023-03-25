#include "Engine.h"
#include "SDLRenderer.h"
#include <filesystem>

Engine::Engine()
{
	renderer = new SDLRenderer();
}

Engine::~Engine()
{
	delete renderer;
}

void Engine::Run()
{
	renderer->drawPoints(terrain.getPoints());
	// renderer->Run(); // to show the animation
}

void Engine::Cleanup()
{
}