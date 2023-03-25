#include "Window.h"
#include <iostream>

Window::Window() {}

/** 
* Singleton function to access single instance of a window object
* 
* \return instance of a window object
*/
Window& Window::GetInstance()
{
	static Window window_;
	return window_;
}

/**
* Initializes SDL window and sets its basic parameters
*
* \param[in] windowTitle - title displayed at the top of the window
* \param[in] width - width of the window (in pixels)
* \param[in] height - height of the window (in pixels)
*/
void Window::initWindow(const char* windowTitle, const int width, const int height)
{
	this->width = width;
	this->height = height;

	sdlWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (sdlWindow == NULL)
	{
		throw std::runtime_error( SDL_GetError() );
	}
}

int Window::getWidth() const { return width; }

int Window::getHeight() const {	return height; }

SDL_Window* Window::getSdlWindow() const { return sdlWindow; }

void Window::destroyWindow()
{
	SDL_DestroyWindow(sdlWindow);
}
