//
// Created by Maksoni on 13.06.2023.
//

#ifndef TESINGGAME_SPLASHGUN_H
#define TESINGGAME_SPLASHGUN_H

#include "../GameObject.h"
#include "../../Managers/WorldManager.h"

class SplashGun: public GameObject {
public:
    SplashGun (string _id, int _x, int _y);
    void update();
    void render (TextureManager* textureManager, SDL_Renderer* renderer);

private:
    int level = 1;
};

//TODO: Working with gun


#endif //TESINGGAME_SPLASHGUN_H
