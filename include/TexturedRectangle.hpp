#ifndef TEXTURED_RECTANGLE_HPP
#define TEXTURED_RECTANGLE_HPP

#include <iostream>
#include <SDL2/SDL.h>

class TexturedRectangle
{
private:
    /* data */
public:
    TexturedRectangle(SDL_Renderer *, std::string filepath);
    ~TexturedRectangle();

    void Render();
    void UpdatePosition(int x, int y);
    void UpdateDimensition(int w, int h);
    bool HasCollision(TexturedRectangle * another);

    SDL_Rect& GetDstRect();

private:
    SDL_Renderer *m_renderer;
    SDL_Surface *m_surface;
    SDL_Texture *m_texture;
    SDL_Rect m_dst_rect;
};

#endif