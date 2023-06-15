//
// Created by Maksoni on 27.05.2023.
//

#include "Engine.h"

void Engine::update() {
    WorldManager::shared_instance().update();
}

void Engine::render()
{
    if ( TTF_Init() < 0 ) {
        cout << "Error initializing SDL_ttf: " << TTF_GetError() << endl;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    WorldManager::shared_instance().render(renderer, &textureManager);

    SDL_RenderPresent(renderer);
}

void Engine::eventHandler() {
    SDL_Event event;
    int mx, my;
    if(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONUP:
                SDL_GetMouseState(&mx, &my);
                for (int i = 0; i < WorldManager::shared_instance().gameObjects.size(); i++) {
                    GameObject* gameObject = WorldManager::shared_instance().gameObjects[i];
//                    gameObject->selfOnClick(mx, my);

                    gameObject->onClick(mx, my);
                }
                break;

            case SDL_KEYDOWN:
                EventManager::shared_instance().keyDownEngine(event.key.keysym.sym);
                break;

            case SDL_KEYUP:
                EventManager::shared_instance().keyUpEngine(event.key.keysym.sym);
                break;

            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&mx, &my);
                EventManager::shared_instance().handleMousePosition(mx, my);
                break;

            default:
                break;
        }
    }
}

void Engine::clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    running = false;
}

void Engine::loop() {
    while (getRunning()) {
        eventHandler();
        update();
        render();
        SDL_Delay(5);
    }

    clear();
}

void Engine::init() {
    window = SDL_CreateWindow("Title", 200, 200, 900, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    running = true;

    //init managers
    textureManager = TextureManager();

    //load sprites
    cout << textureManager.load("../assets/tilemap-td.png", "tileset", renderer) << " tileset output" << endl;

    //init objects
    GameObject* player;
    player = new Player("player");
    WorldManager::shared_instance().gameObjects.push_back(player);

    WorldManager::shared_instance().init();
    loop();
}
