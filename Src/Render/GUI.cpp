#include "GUI.h"
#include "Engine.h"
#include "Algorithm\AllocatorAlgorithm.h"
#include <string> 

#define stringify( name ) # name

const char* SpeciesNames[] =
{
	stringify(MAPLE),
	stringify(PINE),
	stringify(OAK)
};

GUI::GUI(Engine& engine) : engine(engine)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	ImGui::StyleColorsDark();
}

void GUI::DrawFrame()
{
	ImGui::NewFrame();
	// rysowanie
	ImGui::SetNextWindowSize(ImVec2(400, 120));
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("Statistics");
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
		1000.0 / (double)(ImGui::GetIO().Framerate), (double)(ImGui::GetIO().Framerate));
	ImGui::Text("Iteration: %i", engine.GetIterations());
	ImGui::Text("Branches: %i", engine.GetBranches());
	
	static float speed = 0.0;
	if (ImGui::SliderFloat("Speed", &speed, 0.0, 10.0, "%.3f", 0))
	{
		engine.SetSpeed(speed);
	}

	if (ImGui::Button("New Simulation"))
		engine.SetState(EngineState::SETUP_MENU);
	ImGui::End();

	ImGui::Render();
}

void GUI::DrawStartupFrame()
{
	ImGui::NewFrame();
	ImGui::SetNextWindowSize(ImVec2(500, 300));
	ImGui::SetNextWindowPos(ImVec2(Window::GetInstance().GetWidth() / 2 - 250, Window::GetInstance().GetHeight() / 2 - 150));
	ImGui::Begin("New Simulation");
	
	static int val[3] = { 0 };
	for (auto& i : engine.GetSpecies())
	{
		if (ImGui::InputInt(SpeciesNames[i.first], &val[i.first]))
		{
			if (val[i.first] >= 0)
			{
				i.second = val[i.first];
			}
			else
			{
				val[i.first] = 0;
			}
		}	
	}

	AllocatorType allocType = RANDOM;
	ImGui::Text("Trees allocation type:");
	ImGui::SameLine();
	static int e = 0;
	ImGui::RadioButton("Random", &e, 0); ImGui::SameLine();
	ImGui::RadioButton("Optimised", &e, 1);
	if (e == 1)
	{
		allocType = OPTIMISED;
	}
	else
	{
		allocType = RANDOM;
	}

	TerrainType terrainType = FROM_MAP;
	ImGui::Text("Terrain generation type:");
	ImGui::SameLine();
	static int t = 0;
	ImGui::RadioButton("From Heightmap", &t, 0); ImGui::SameLine();
	ImGui::RadioButton("From Perlin Noise", &t, 1);
	if (t == 1)
	{
		terrainType = PERLIN;
	}
	else
	{
		terrainType = FROM_MAP;
	}

	static int terrSize[3] = { 0 };
	ImGui::Text("Terrain size:");
	if (ImGui::InputInt("width", &terrSize[0]))
	{
		if (terrSize[0] > 0)
			engine.SetTerrainSize(Point(terrSize[0], terrSize[1], terrSize[2]));
		else
			terrSize[0] = 1;
	}
	if (ImGui::InputInt("length", &terrSize[1]))
	{
		if (terrSize[1] > 0)
			engine.SetTerrainSize(Point(terrSize[0], terrSize[1], terrSize[2]));
		else
			terrSize[1] = 1;
	}
	if (ImGui::InputInt("height", &terrSize[2]))
	{
		if (terrSize[2] > 0)
			engine.SetTerrainSize(Point(terrSize[0], terrSize[1], terrSize[2]));
		else
			terrSize[2] = 1;
	}

	if (ImGui::Button("Begin"))
	{
		engine.SetState(EngineState::SIMULATION);
		engine.Init(allocType, terrainType);
	}

	ImGui::End();
	ImGui::Render();
}
