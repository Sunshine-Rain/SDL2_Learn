#ifndef RESUORCE_MAMAGER_HPP
#define RESUORCE_MAMAGER_HPP

#include <iostream>
#include <unordered_map>
#include <SDL2/SDL.h>

class ResourceManager
{
public:
    static ResourceManager& GetInstance();
    ResourceManager& operator= (ResourceManager &);
    ~ResourceManager();

    SDL_Surface * GetSurface(std::string filepath);

private:
    ResourceManager();
    ResourceManager(ResourceManager &manager);

    std::unordered_map<std::string, SDL_Surface *> *m_cache;
};

#endif