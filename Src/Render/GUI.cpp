#include "GUI.h"
#include "Engine.h"
#include <string> 

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
	ImGui::SetNextWindowSize(ImVec2(400, 100));
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("Statistics");
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
		1000.0 / (double)(ImGui::GetIO().Framerate), (double)(ImGui::GetIO().Framerate));
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
	if (ImGui::Button("Begin"))
		engine.SetState(EngineState::SIMULATION);

	ImGui::End();
	ImGui::Render();
}
