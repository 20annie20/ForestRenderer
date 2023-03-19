//Using SDL and standard IO
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "App\window.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[])
{
	Window::GetInstance().initWindow("Forest Simulator", SCREEN_WIDTH, SCREEN_HEIGHT);
	Window &window = Window::GetInstance();

	SDL_Surface* image = SDL_LoadBMP("Resources/Heightmap_Rocky.bmp"); //add error loading if null
	if (image == NULL)
	{
		std::cerr << "image not loaded";
	}
	SDL_Surface* windowSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{	
		windowSurface = SDL_GetWindowSurface(window.getSdlWindow());
		SDL_BlitSurface(image, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window.getSdlWindow());

		SDL_Delay(6000);

		SDL_Quit();
	}

	window.destroyWindow();

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
