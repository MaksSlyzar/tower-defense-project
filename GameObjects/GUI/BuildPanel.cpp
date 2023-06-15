//
// Created by Maksoni on 08.06.2023.
//

#include "BuildPanel.h"

void BuildPanel::update() {
    //ESC
    if (EventManager::shared_instance().keyPress(27)) {
        selectedBuild = NULL;
    }
}

void BuildPanel::render(TextureManager* textureManager, SDL_Renderer* renderer) {
//    textureManager->drawFrame("tileset", x, y, width, height, , imageY, 64, 64, renderer, SDL_FLIP_HORIZONTAL);



    for (int i = 0; i < buildBlocks.size(); i++) {
        Build buildType = buildBlocks[i].buildType;
        buildBlocks[i].enable = WorldManager::shared_instance().buildsInfo[buildType].buildsLength != WorldManager::shared_instance().buildsInfo[buildType].limit;
        buildBlocks[i].render(textureManager, renderer);
    }

    if (selectedBuild != NULL) {
        textureManager->drawFrameAlpha("tileset",
                                  EventManager::shared_instance().mouseX - selectedBuild->width / 2,
                                  EventManager::shared_instance().mouseY - selectedBuild->height / 2,
                                  selectedBuild->width,
                                  selectedBuild->height,
                                  selectedBuild->imageX,
                                  selectedBuild->imageY,
                                  64,
                                  64,
                                  renderer,
                                  SDL_FLIP_NONE,
                                  100);
    }

    char text[100];
    sprintf(text, "Gold: %.1f", WorldManager::shared_instance().gold);
    SDL_Color color {
        r: 255,
        g: 215,
        b: 0
    };

    //255, 215, 0
    textureManager->drawText(renderer, text, 16, 0, 0, color);
}

void BuildPanel::init() {
    selectedBuild = NULL;
}

void BuildPanel::onClick(int x, int y) {
    for (int i = 0; i < buildBlocks.size(); i++) {
        BuildBlock buildBlock = buildBlocks[i];

        if (buildBlock.inObject(x, y)) {
            if (buildBlock.enable) {
                selectedBuild = &buildBlocks[i];
            }

            return;
        }
    }

    if (selectedBuild == NULL)
        return;

    GameObject* newBuild;
    Vector2d cameraPosition = WorldManager::shared_instance().getObjectById("camera")->getPosition();
    Vector2d buildPosition = getBuildPosition(x + cameraPosition.x, y + cameraPosition.y);

    switch (selectedBuild->buildType) {
        case MINE_CAVE:
            newBuild = new MineCave("cave", buildPosition.x, buildPosition.y);
            break;

        case BASE:
            newBuild = new Base("base", buildPosition.x, buildPosition.y);
            break;

        case SPLASH_GUN:
            newBuild = new SplashGun("splashgun", buildPosition.x, buildPosition.y);
            break;
    }

    bool builded = WorldManager::shared_instance().buildController(newBuild, selectedBuild->buildType, buildPosition.x, buildPosition.y);

    if (builded)
        selectedBuild = NULL;
}



BuildPanel::BuildPanel(string id) : GameObject(id) {
    x = 10;
    y = 500;
    width = 900;
    height = 100;

    //MineCaves
    buildBlocks.push_back(BuildBlock(MINE_CAVE, 96+x, 0+y, 64, 64, 0, 0, "tileset"));
    //Base
    buildBlocks.push_back(BuildBlock(BASE, 0+x, 0+y, 64, 64, 128, 0, "tileset"));
    //SplashGun
    buildBlocks.push_back(BuildBlock(SPLASH_GUN, 192+x, 0+y, 64, 64, 192, 0, "tileset"));
}