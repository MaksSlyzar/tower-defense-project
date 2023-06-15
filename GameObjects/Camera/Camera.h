//
// Created by Maksoni on 04.06.2023.
//

#ifndef TESINGGAME_CAMERA_H
#define TESINGGAME_CAMERA_H
#include "../GameObject.h"


class Camera: public GameObject {
public:
    int speed;
    Camera(string id);
    void update ();
};


#endif //TESINGGAME_CAMERA_H
