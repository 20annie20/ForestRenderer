#pragma once
#include <SDL.h>
#include <iostream>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer.h>
#include <imgui.h>
#include "App/Window.h"

/// Class responsible for graphical user interface
/** Class that utilizes ImGui library to create, render UI widgets and handle user input from them. 
Based on SDL backend */
class GUI {
	bool showStartupWindow = true;
	ImGuiIO io;
	class Engine& engine;

public:
	GUI(Engine& engine);
	void DrawFrame();
	void DrawStartupFrame();
};