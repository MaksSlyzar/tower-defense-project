//
// Created by Maksoni on 03.06.2023.
//

#include "WorldManager.h"

void WorldManager::update() {
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update();
    }
//    cout << gold << endl;
}

void WorldManager::render(SDL_Renderer* renderer, TextureManager *textureManager) {
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->render(textureManager, renderer);
    }
}

void WorldManager::init() {
//    GameObject* mineCave;
    GameObject* terrain;
    GameObject* camera;

//    mineCave = new MineCave("mine1");
    terrain = new Terrain("terrain");
    camera = new Camera("camera");

    gameObjects.push_back(terrain);
    gameObjects.push_back(camera);

    GameObject* buildPanel;
    buildPanel = new BuildPanel("panel");
    gameObjects.push_back(buildPanel);

    GameObject* resourcePanel;
    resourcePanel = new ResourcePanel("respanel");
    gameObjects.push_back(resourcePanel);


    //Mine cave
    struct BuildInfo mineCaveInfo {
        cost: 100,
        limit: -1
    };
    buildsInfo[MINE_CAVE] = mineCaveInfo;

    //Base
    struct BuildInfo baseInfo {
        cost: 0,
        limit: 1
    };

    buildsInfo[BASE] = baseInfo;

    //SplashGun
    struct BuildInfo splashGunInfo {
        cost: 250,
        limit: -1,
    };

    buildsInfo[SPLASH_GUN] = splashGunInfo;

    gold = 600;
}
