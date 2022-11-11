#include "GameEntity.hpp"

GameEntity::GameEntity()
{
    std::cout << "Not implemented yet.\n";
}

GameEntity::GameEntity(SDL_Renderer *renderer, std::string texturedPath)
{
    m_renderer = renderer;
    m_texturedRect = new TexturedRectangle(renderer, texturedPath);
    m_collider = new Collider2D();
}

GameEntity::~GameEntity()
{
    if (nullptr != m_texturedRect)
    {
        delete m_texturedRect;
    }

    if (nullptr != m_collider)
    {
        delete m_collider;
    }
}

void GameEntity::Update()
{
    SDL_Rect rect = m_texturedRect->GetDstRect();
    m_collider->SetAbsolutePosition({rect.x,
                                     rect.y});
    m_collider->SetDimension({rect.w,
                              rect.h});

    SDL_Rect r = m_collider->GetRect();
    std::cout << "Updated collider x =" <<  r.x << " y =" <<  r.y << " w =" <<  r.w << " h =" <<  r.h << "\n";
}

void GameEntity::Render()
{
    if (nullptr != m_texturedRect)
    {
        m_texturedRect->Render();
    }

    if (nullptr != m_collider)
    {
        m_collider->DebugRender(m_renderer);
    }
    
}

TexturedRectangle *GameEntity::GetTexturedRectangle()
{
    return m_texturedRect;
}

Collider2D & GameEntity::GetCollider2D() {
    return *m_collider;
}