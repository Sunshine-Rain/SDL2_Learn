#include "Collider2D.hpp"

Collider2D::Collider2D()
{
    m_rect.x = 0;
    m_rect.y = 0;
    m_rect.w = 0;
    m_rect.h = 0;
}

Collider2D::~Collider2D()
{
}

void Collider2D::SetAbsolutePosition(SDLAppPosition position) {
    m_rect.x = position.x;
    m_rect.y = position.y;
}

void Collider2D::SetDimension(SDLAppSize size) {
    m_rect.w = size.width;
    m_rect.h = size.height;
}

bool Collider2D::IsColliding(Collider2D & another) {
    return SDL_HasIntersection(&m_rect, &another.GetRect());
}

const SDL_Rect & Collider2D::GetRect() {
    return m_rect;
}

void Collider2D::DebugRender(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xff, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &m_rect);
}