#ifndef COLLIDER_2D_HPP
#define COLLIDER_2D_HPP

#include <iostream>
#include <SDL2/SDL.h>

#include "SDLAppPosition.hpp"

class Collider2D
{
private:
    SDL_Rect m_rect;
    
public:
    Collider2D();
    ~Collider2D();

    void SetAbsolutePosition(SDLAppPosition position);
    void SetDimension(SDLAppSize size);

    const SDL_Rect & GetRect();

    bool IsColliding(Collider2D & another);

    void DebugRender(SDL_Renderer *renderer);
};


#endif