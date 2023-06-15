//
// Created by Maksoni on 03.06.2023.
//

#ifndef TESINGGAME_WORLDMANAGER_H
#define TESINGGAME_WORLDMANAGER_H
#include <vector>
#include "../GameObjects/GameObject.h"
#include "../TerrainObjects/TerrainObject.h"
#include "../GameObjects/MineCave/MineCave.h"
#include "../GameObjects/Terrain/Terrain.h"
#include "../GameObjects/Camera/Camera.h"
#include "../GameObjects/GUI/BuildPanel.h"
#include "../GameObjects/GUI/ResourcePanel/ResourcePanel.h"
#include <map>

class WorldManager {
public:
    void init ();
    static WorldManager &shared_instance() {static WorldManager worldManager; return worldManager;}
    vector<GameObject*> gameObjects;
    void update ();
    void render (SDL_Renderer* renderer, TextureManager* textureManager);

    struct BuildInfo {
        int cost;
        int limit;
        int buildsLength = 0;
    };

    map<Build, BuildInfo> buildsInfo;

    float gold;

    GameObject* getObjectById (string objectId) {
        for (int i = 0; i < gameObjects.size(); i++) {
            if (gameObjects[i]->_id == objectId) {
                return gameObjects[i];
            }
         }

        return NULL;
    }

    bool buildController (GameObject* build, Build buildType, int x, int y) {
        int cost = buildsInfo[buildType].cost;

        if (gold < cost) {
            cout << "You need more gold." << endl;
            return false;
        }

        if (buildsInfo[buildType].buildsLength == buildsInfo[buildType].limit) {
            cout << "Limit " << endl;
            return false;
        }

        gold -= cost;
        buildsInfo[buildType].buildsLength++;
        WorldManager::shared_instance().gameObjects.push_back(build);
        return true;
    }
};


#endif //TESINGGAME_WORLDMANAGER_H
