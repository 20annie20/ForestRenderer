#pragma once
#include <SDL.h>
#include <iostream>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer.h>
#include <imgui.h>

class GUI {

public:
	GUI();
	void DrawFrame();
};