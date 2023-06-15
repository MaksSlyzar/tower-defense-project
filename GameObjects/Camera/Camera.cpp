//
// Created by Maksoni on 04.06.2023.
//

#include "Camera.h"

void Camera::update() {
    //W
    if (EventManager::shared_instance().keyPress(119)) {
        y -= speed;
    }

    //A
    if (EventManager::shared_instance().keyPress(97)) {
        x -= speed;
    }

    //D
    if (EventManager::shared_instance().keyPress((100))) {
        x += speed;
    }

    //S
    if (EventManager::shared_instance().keyPress(115)) {
        y += speed;
    }
}


Camera::Camera(string id) : GameObject(id) {
    x = 0;
    y = 0;
    width = 64;
    height = 64;
    speed = 10;
}