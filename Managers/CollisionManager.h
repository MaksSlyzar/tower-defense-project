//
// Created by Maksoni on 28.05.2023.
//

#ifndef TESINGGAME_COLLISIONMANAGER_H
#define TESINGGAME_COLLISIONMANAGER_H

#include <vector>
#include "../GameObjects/GameObject.h"

class CollisionManager {
public:
    static CollisionManager &shared_instance() {static CollisionManager game; return game;}

    vector<GameObject*> gameobjects;
private:
    bool isCollision(vector<GameObject*> gameObjects, string selfId);
};


#endif //TESINGGAME_COLLISIONMANAGER_H
