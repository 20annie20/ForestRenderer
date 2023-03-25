//Using SDL and standard IO
#pragma once
#include "Common.h"
#include "Utils\Loader.h"
#include "App\Window.h"
#include "Render\Engine.h"

/** Screen dimension constants */
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 600;

/// main function of the program
/** 
* main function initializes and destroys simulator components: window, engine, input, etc.
* loop of the program is run in main
*/
int main(int argc, char* args[])
{
	Window::GetInstance().InitWindow("Forest Simulator", SCREEN_WIDTH, SCREEN_HEIGHT);
	Window &window = Window::GetInstance();

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		Engine engine = Engine();
		engine.Run(AllocatorType::Random);
	}

	window.DestroyWindow();

	SDL_Quit();

	return 0;
}
