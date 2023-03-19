#pragma once
#include <SDL.h>

/*! A singleton window class, helps maintaining instance of an SDL window */
class Window {

    SDL_Window* sdlWindow = NULL;
    int width = 0;
    int height = 0;

    Window();

public:
    
    Window(Window& other) = delete;
    void operator=(const Window&) = delete;

    static Window& GetInstance();
    void initWindow(const char* windowTitle, const int width, const int height);

    int getWidth() const;
    int getHeight() const;
    SDL_Window* getSdlWindow() const;
    void destroyWindow();
};