#pragma once
#include <SDL.h>
#include <iostream>

/// Window class
/** Singleton window class, maintaining instance of an SDL window */
class Window {

    SDL_Window* sdlWindow = NULL;
    int width = 0;
    int height = 0;
    bool showDemoWindow = true;
    Window();

public:
    
    Window(Window& other) = delete;
    void operator=(const Window&) = delete;

    static Window& GetInstance();
    void InitWindow(const char* windowTitle, const int width, const int height);

    int GetWidth() const;
    int GetHeight() const;
    SDL_Window* GetSdlWindow() const;
    void DestroyWindow();
};