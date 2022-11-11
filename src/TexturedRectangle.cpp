#include "TexturedRectangle.hpp"
#include "ResourceManager.hpp"


TexturedRectangle::TexturedRectangle(SDL_Renderer *renderer, std::string filepath)
:m_renderer(renderer)
{
    m_surface = ResourceManager::GetInstance().GetSurface(filepath);
    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    m_dst_rect = { 0, 0, 100, 100 };
}

TexturedRectangle::~TexturedRectangle()
{
    SDL_DestroyTexture(m_texture);
}

void TexturedRectangle::Render() {
    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_dst_rect);
}

void TexturedRectangle::UpdatePosition(int x, int y) {
    m_dst_rect.x = x;
    m_dst_rect.y = y;
}


void TexturedRectangle::UpdateDimensition(int w, int h) {
    m_dst_rect.w = w;
    m_dst_rect.h = h;
}

bool TexturedRectangle::HasCollision(TexturedRectangle * another) {
    SDL_bool ret = SDL_HasIntersection(&m_dst_rect, &another->m_dst_rect);
    return ret == SDL_TRUE;
}

SDL_Rect& TexturedRectangle::GetDstRect() {
    return m_dst_rect;
}
