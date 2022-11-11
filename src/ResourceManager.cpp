#include "ResourceManager.hpp"

ResourceManager::ResourceManager() {
     m_cache = new std::unordered_map<std::string, SDL_Surface *>();
}

ResourceManager& ResourceManager::GetInstance() {
    static ResourceManager *manager = new ResourceManager();
    return *manager;
}

ResourceManager& ResourceManager::operator= (ResourceManager & mgr) {
    return mgr;
}

SDL_Surface * ResourceManager::GetSurface(std::string filepath) {
    auto findResult = m_cache->find(filepath);
    if (findResult == m_cache->end())
    {
        std::cout << "Start load " << filepath << std::endl;
        SDL_Surface *surface = SDL_LoadBMP(filepath.c_str());
        if (nullptr != surface)
        {
            m_cache->insert({filepath, surface});
        }
        return surface;        
    }

    return (*m_cache)[filepath];
}