//
// Created by Maksoni on 08.06.2023.
//

#ifndef TESINGGAME_MINECAVE_H
#define TESINGGAME_MINECAVE_H
#include "../GameObject.h"
#include "../../Managers/WorldManager.h"
#include <vector>

class MineCave: public GameObject {
public:
    MineCave(string id, int _x, int _y);

    void render(TextureManager* textureManager, SDL_Renderer* renderer);
    void onClick (int x, int y);
    void update();

private:
    int level;
};


#endif //TESINGGAME_MINECAVE_H
