//
// Created by Maksoni on 09.06.2023.
//

#include "Terrain.h"

Terrain::Terrain(string id) : GameObject(id) {
    x = 0;
    y = 0;
    width = 1000;
    height = 1000;
    cameraPositioning = true;
}

void Terrain::render(TextureManager* textureManager, SDL_Renderer* renderer) {
    auto camera = WorldManager::shared_instance().getObjectById("camera");

    if (camera == NULL)
        return;

    //TODO:Optimization

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            int renderX = i * 64 + x - camera->getX();
            int renderY = j * 64 + y - camera->getY();

            //900 width screen
            //600 height screen

            if (renderX > 900 + 64|| renderX < 0 - 64)
                continue;

            if (renderY > 600 + 64 || renderY < 0 - 64)
                continue;

            textureManager->drawFrame("tileset", renderX, renderY, 64, 64, 64, 0, 64, 64, renderer, SDL_FLIP_HORIZONTAL);
        }
    }
}