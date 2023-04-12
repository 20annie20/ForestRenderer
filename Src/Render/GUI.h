#pragma once
#include <SDL.h>
#include <iostream>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer.h>
#include <imgui.h>
#include "App/Window.h"

class GUI {
	bool showStartupWindow = true;
	ImGuiIO io;
	class Engine& engine;

public:
	GUI(Engine& engine);
	void DrawFrame();
	void DrawStartupFrame();
};