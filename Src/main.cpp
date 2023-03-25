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
	Window::GetInstance().initWindow("Forest Simulator", SCREEN_WIDTH, SCREEN_HEIGHT);
	Window &window = Window::GetInstance();

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// init window
		// init engine
		Engine engine = Engine();

		engine.run(AllocatorType::Random);

		SDL_Surface* windowSurface = NULL;

		//windowSurface = SDL_GetWindowSurface(window.getSdlWindow());
		//SDL_BlitSurface(Loader::GetSurfaceFromBitmap("Resources/Heightmap_Rocky.bmp"), NULL, windowSurface, NULL);
		//SDL_UpdateWindowSurface(window.getSdlWindow());

		SDL_Delay(3000);
	}

	window.destroyWindow();

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
