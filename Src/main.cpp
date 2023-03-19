//Using SDL and standard IO
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
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
		//Create window
		window = SDL_CreateWindow("Forest Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			windowSurface = SDL_GetWindowSurface(window);
			SDL_BlitSurface(image, NULL, windowSurface, NULL);
			SDL_UpdateWindowSurface(window);

			SDL_Delay(6000);

			SDL_DestroyWindow(window);
			SDL_Quit();
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
