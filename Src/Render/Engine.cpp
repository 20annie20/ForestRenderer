#include "Engine.h"
#include <filesystem>

Engine::Engine() : renderer(nullptr)
{
	//renderer = new SDLEngine();
	terrain = Terrain();
}

Engine::~Engine()
{
	delete renderer;
}

void Engine::Init() // pass path to shader?
{
	std::filesystem::current_path(std::filesystem::current_path() / "../");
	renderer->Init();
}

void Engine::Run()
{
	renderer->Run();
}

void Engine::Cleanup()
{
	renderer->Cleanup();
}