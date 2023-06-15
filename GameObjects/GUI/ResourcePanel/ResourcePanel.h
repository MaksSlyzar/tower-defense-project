//
// Created by Maksoni on 11.06.2023.
//

#ifndef TESINGGAME_RESOURCEPANEL_H
#define TESINGGAME_RESOURCEPANEL_H
#include "../../GameObject.h"
#include "../../../Managers/WorldManager.h"

class ResourcePanel: public GameObject {
public:
    ResourcePanel(string id);

    void render (TextureManager* textureManager, SDL_Renderer* renderer);
};


#endif //TESINGGAME_RESOURCEPANEL_H
