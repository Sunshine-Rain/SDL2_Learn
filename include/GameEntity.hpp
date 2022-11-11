#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SDL2/SDL.h>
#include "TexturedRectangle.hpp"
#include "Collider2D.hpp"

class GameEntity
{
private:
    TexturedRectangle *m_texturedRect;
    SDL_Renderer *m_renderer;
    Collider2D *m_collider;

public:
    GameEntity();
    GameEntity(SDL_Renderer *renderer, std::string texturedPath);
    ~GameEntity();

    void Update();
    void Render();

    TexturedRectangle * GetTexturedRectangle();
    Collider2D & GetCollider2D();
};

#endif