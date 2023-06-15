//
// Created by Maksoni on 13.06.2023.
//

#include "SplashGun.h"

void SplashGun::render(TextureManager *textureManager, SDL_Renderer *renderer) {
    auto camera = WorldManager::shared_instance().getObjectById("camera");

    if (camera == NULL)
        return;

    textureManager->drawFrame("tileset", x - camera->getX(), y - camera->getY(), 64, 64, 192, 0, 64, 64, renderer, SDL_FLIP_NONE);
}

SplashGun::SplashGun (string id, int _x, int _y) : GameObject(id) {
    x = _x;
    y = _y;
    width = 64;
    height = 64;
    cameraPositioning = true;
    level = 1;

    //TODO:Level up
}

void SplashGun::update() {
    GameObject::update();
}
