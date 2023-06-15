//
// Created by Maksoni on 09.06.2023.
//

#ifndef TESINGGAME_TERRAIN_H
#define TESINGGAME_TERRAIN_H
#include "../GameObject.h"
#include "../../Managers/WorldManager.h"

class Terrain: public GameObject {
public:
    Terrain(string id);

    void render(TextureManager* textureManager, SDL_Renderer* renderer);
};


#endif //TESINGGAME_TERRAIN_H
