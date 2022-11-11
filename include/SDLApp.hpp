#ifndef SDL_APP_HPP
#define SDL_APP_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "SDLAppPosition.hpp"

class SDLApp
{
public:
    SDLApp(const char * title, int x, int y, int w, int h);
    ~SDLApp();

    void Runloop();
    void SetEventHandler(std::function<void(void)>);
    void SetUpdateHandler(std::function<void(void)>);
    void SetRendererHandler(std::function<void(SDL_Renderer *)>);

    void SetIsRunning(bool);
    void SetFrameRate(int);

    int GetWindowWidth();
    int GetWindowHeight();

    SDL_Window *GetWindow();
    SDL_Renderer *GetRenderer();
    SDLAppPosition& GetMousePosition();

private:
    bool isRunning;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDLAppPosition m_mouse_position;

    int m_fps;
    int m_per_seconds_delay;

    int m_window_width;
    int m_window_height;

    std::function<void(void)> m_eventHandler;
    std::function<void(void)> m_updateHandler;
    std::function<void(SDL_Renderer *)> m_rendererHandler;

    void HandleEvent();
    void HandleUpdate();
    void HandleRender(SDL_Renderer *);

    void Clean();
};

#endif