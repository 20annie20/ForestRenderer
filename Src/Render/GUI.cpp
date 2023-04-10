#include "GUI.h"

GUI::GUI()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	ImGui::StyleColorsDark();
}

void GUI::DrawFrame()
{
	ImGui::NewFrame();
	// rysowanie
	ImGui::Begin("Some panel");
	ImGui::Text("Hello World");
	ImGui::End();
	ImGui::Render();
}
