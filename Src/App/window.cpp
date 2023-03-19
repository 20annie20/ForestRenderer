#include "window.h"
#include <iostream>

Window::Window() {}

Window& Window::GetInstance()
{
	static Window window_;
	return window_;
}

void Window::initWindow(const char* windowTitle, const int width, const int height)
{
	this->width = width;
	this->height = height;

	sdlWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (sdlWindow == NULL)
	{
		std::cerr << ("Window could not be created! SDL_Error: %s\n", SDL_GetError()); // throw exception
	}
}

int Window::getWidth() const { return width; }

int Window::getHeight() const {	return height; }

SDL_Window* Window::getSdlWindow() const { return sdlWindow; }

void Window::destroyWindow()
{
	SDL_DestroyWindow(sdlWindow);
}
