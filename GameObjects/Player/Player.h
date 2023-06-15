//
// Created by Maksoni on 28.05.2023.
//

#ifndef TESINGGAME_PLAYER_H
#define TESINGGAME_PLAYER_H
#include <iostream>
#include <vector>
using namespace std;

#include "../GameObject.h"
#include "../../Managers/CollisionManager.h"

class Player: public GameObject {
public:
    int width = 64;
    int height = 64;
    Player (string id);
    void update(vector<GameObject*> gameObjects);
    void render(TextureManager* textureManager, SDL_Renderer* renderer);
};


#endif //TESINGGAME_PLAYER_H
