//
// Created by Maksoni on 08.06.2023.
//

#ifndef TESINGGAME_BUILDPANEL_H
#define TESINGGAME_BUILDPANEL_H

#include "../GameObject.h"
#include "../MineCave/MineCave.h"
#include "../Base/Base.h"
#include "../SplashGun/SplashGun.h"
#include "../../Managers/WorldManager.h"

class BuildBlock {
public:
    int x;
    int y;
    int width;
    int height;
    int imageX;
    int imageY;
    string imageId;
    Build buildType;
    bool enable;

    bool inObject (int mx, int my) {
        return mx > x && mx < x + width && my > y && my < y + height;
    }

    BuildBlock (Build build_type, int _x, int _y, int _width, int _height, int image_x, int image_y, string image_id): buildType(build_type), x(_x), y(_y), width(_width), height(_height), imageX(image_x), imageY(image_y), imageId(image_id) {
        enable = true;
    }

    void render (TextureManager* textureManager, SDL_Renderer* renderer) {

        if (!enable)
            textureManager->drawFrameAlpha(imageId, x, y, width, height, imageX, imageY, 64, 64, renderer, SDL_FLIP_NONE, 100);
        else
            textureManager->drawFrame(imageId, x, y, width, height, imageX, imageY, 64, 64, renderer, SDL_FLIP_NONE);
    }
};

class BuildPanel: public GameObject  {
public:
    BuildPanel (string id);
    void init();
    void render(TextureManager* textureManager, SDL_Renderer* renderer);
    void update();
    void onClick (int x, int y);

    vector <BuildBlock> buildBlocks;

    Vector2d getBuildPosition (int _x, int _y) {
        return Vector2d {
                x: _x - (_x % 64),
                y: _y - (_y % 64)
        };
    }
private:
    BuildBlock *selectedBuild;
};


#endif //TESINGGAME_BUILDPANEL_H
