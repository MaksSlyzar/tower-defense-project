//
// Created by Maksoni on 12.06.2023.
//

#include "Base.h"

void Base::render(TextureManager *textureManager, SDL_Renderer *renderer) {
    auto camera = WorldManager::shared_instance().getObjectById("camera");

    if (camera == NULL)
        return;

    textureManager->drawFrame("tileset", x - camera->getX(), y - camera->getY(), 64, 64, 128, 0, 64, 64, renderer, SDL_FLIP_HORIZONTAL);
}

void Base::update() {

}

Base::Base(string _id, int _x, int _y): GameObject(_id) {
    x = _x;
    y = _y;
}