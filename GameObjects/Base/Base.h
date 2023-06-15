//
// Created by Maksoni on 12.06.2023.
//

#ifndef TESINGGAME_BASE_H
#define TESINGGAME_BASE_H

#include "../GameObject.h"
#include "../../Managers/WorldManager.h"

class Base: public GameObject {
public:
    Base(string id, int _x, int _y);
    void update();
    void render(TextureManager* textureManager, SDL_Renderer* renderer);

};


#endif //TESINGGAME_BASE_H
