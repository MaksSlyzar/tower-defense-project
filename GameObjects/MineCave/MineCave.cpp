//
// Created by Maksoni on 08.06.2023.
//

#include "MineCave.h"
void MineCave::render(TextureManager *textureManager, SDL_Renderer *renderer) {
    auto camera = WorldManager::shared_instance().getObjectById("camera");

    if (camera == NULL)
        return;

    // Розмір та координати круга
    int radius = 28;

    SDL_SetRenderDrawColor(renderer,  255, 215, 0, 1);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1000");

    // Малювання заповненого круга
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // Зсув по x
            int dy = radius - h; // Зсув по y
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx + 31, y + dy + 32);
            }
        }
    }

    textureManager->drawFrame("tileset", x - camera->getX(), y - camera->getY(), 64, 64, 0, 0, 64, 64, renderer, SDL_FLIP_NONE);
}

void MineCave::onClick(int x, int y) {
    auto camera = WorldManager::shared_instance().getObjectById("camera");

    if (camera == NULL)
        return;

//    cout << checkInObject(x + camera->getX(), y + camera->getY()) << endl;
}

MineCave::MineCave(string id, int _x, int _y) : GameObject(id) {
    x = _x;
    y = _y;
    width = 64;
    height = 64;
    cameraPositioning = true;
    level = 1;

    //TODO:Level up
}

void MineCave::update() {
    WorldManager::shared_instance().gold += 0.2 * level;
}