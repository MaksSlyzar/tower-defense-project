//
// Created by Maksoni on 27.05.2023.
//

#ifndef TESINGGAME_GAMEOBJECT_H
#define TESINGGAME_GAMEOBJECT_H

enum Build {
    NONE,
    MINE_CAVE,
    BASE,
    SPLASH_GUN
};


struct Vector2d {
    int x;
    int y;
};

#include "../Managers/TextureManager.h"
#include "../Managers/EventManager.h"

class GameObject {
public:
    GameObject(string id): _id(id){
        x = 10;
        y = 10;
//        width = 64;
//        height = 64;
        cout << _id << " init" << endl;
    }

    GameObject();

    virtual void render(TextureManager* textureManager, SDL_Renderer* renderer) {};
    virtual void update() {
    };
    virtual void init();
    virtual void checkState() {};
    bool checkInObject (int mx, int my) {
        return mx > getX() && mx < getX() + getWidth() && my > getY() && my < getY() + getHeight();
    }

    virtual void onClick(int x, int y) {};

    string _id;

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    Vector2d getPosition() {
        return Vector2d {
            x: getX(),
            y: getY()
        };
    }

    int getWidth () {
        return width;
    }

    int getHeight () {
        return height;
    }
protected:
    int x;
    int y;
    int width;
    int height;
    bool cameraPositioning = false;
};


#endif //TESINGGAME_GAMEOBJECT_H
