#include "SDLApp.hpp"

SDLApp::SDLApp(const char * title, int x, int y, int w, int h) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL Init video error.\n" << SDL_GetError() << "\n";
        return;
    }

    std::cout << "SDL video system is ready to go.\n";

    m_window = SDL_CreateWindow(
        title,
        x,
        y,
        w,
        h,
        SDL_WINDOW_SHOWN
    );

    if (nullptr == m_window)
    {
        std::cout << "Create SDL window failed.\n";
        std::cout << SDL_GetError() << "\n";
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == m_renderer)
    {
        std::cout << "Create SDL renderer failed.\n";
        std::cout << SDL_GetError() << "\n";
        return;
    }
    
    m_window_width = w;
    m_window_height = h;
    isRunning = true;
    SetFrameRate(60);
}

void SDLApp::Runloop() {
    m_mouse_position = {0, 0};
    while (isRunning) {
        Uint32 startTicks = SDL_GetTicks();
        SDL_GetMouseState(&m_mouse_position.x, &m_mouse_position.y);
        HandleEvent();
        HandleUpdate();
        HandleRender(m_renderer);

        uint32_t endTicks = SDL_GetTicks();

        int execTicks = endTicks - startTicks;
        if (execTicks < m_per_seconds_delay)
        {
            SDL_Delay(m_per_seconds_delay - execTicks);
        }
        
    }
    Clean();
}

void SDLApp::HandleEvent() {
    if (nullptr != m_eventHandler)
        m_eventHandler();
}

void SDLApp::HandleUpdate() {
    if (nullptr != m_updateHandler)
    {
        m_updateHandler();
    }
    
}

void SDLApp::HandleRender(SDL_Renderer * renderer) {
    if (nullptr != m_rendererHandler)
        m_rendererHandler(renderer);
    
}

void SDLApp::SetEventHandler(std::function<void(void)> func) {
    m_eventHandler = func;
}

void SDLApp::SetUpdateHandler(std::function<void(void)> func) {
    m_updateHandler = func;
}

void SDLApp::SetRendererHandler(std::function<void(SDL_Renderer *)> func) {
    m_rendererHandler = func;
}

void SDLApp::SetIsRunning(bool running) {
    isRunning = running;
}

void SDLApp::SetFrameRate(int fps) {
    m_fps = fps;
    m_per_seconds_delay = 1000/fps;
}

int SDLApp::GetWindowWidth() {
    return m_window_width;
}

int SDLApp::GetWindowHeight() {
    return m_window_height;
}

SDL_Window * SDLApp::GetWindow() {
    return m_window;
}

SDL_Renderer * SDLApp::GetRenderer() {
    return m_renderer;
}

SDLAppPosition& SDLApp::GetMousePosition() {
    return m_mouse_position;
}

SDLApp::~SDLApp() {
}

void SDLApp::Clean() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}