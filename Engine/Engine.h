//
// Created by Maksoni on 27.05.2023.
//

#ifndef TESINGGAME_ENGINE_H
#define TESINGGAME_ENGINE_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//Managers
#include "../Managers/WorldManager.h"
#include "../Managers/TextureManager.h"
#include "../Managers/EventManager.h"

//GameObjects
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Player/Player.h"

using namespace std;

class Engine {
public:
    void init();
    void render();
    void update();
    void loop();
    void eventHandler();
    void clear();

    bool getRunning () {
        return running;
    }

    TextureManager textureManager;
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;

    bool running = false;
};


#endif //TESINGGAME_ENGINE_H
