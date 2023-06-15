//
// Created by Maksoni on 03.06.2023.
//

#ifndef TESINGGAME_TERRAINOBJECT_H
#define TESINGGAME_TERRAINOBJECT_H
#include "../Managers/TextureManager.h"


class TerrainObject {
public:
    virtual void render(TextureManager* textureManager, SDL_Renderer* renderer) {};
    virtual void update();
    virtual void init();
    virtual void checkState() {};

protected:
    int x;
    int y;
};


#endif //TESINGGAME_TERRAINOBJECT_H
