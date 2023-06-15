//
// Created by Maksoni on 09.06.2023.
//

#ifndef TESINGGAME_EVENTMANAGER_H
#define TESINGGAME_EVENTMANAGER_H
#include <vector>
#include <iostream>

using namespace std;

class EventManager {
public:
    void init ();
    static EventManager &shared_instance() {static EventManager eventManager; return eventManager;}

    vector <int> pressedKeys;
    int mouseY;
    int mouseX;

    void keyDownEngine (int key) {
        for (int _key: pressedKeys) {
            if (key == _key)
                return;
        }

        pressedKeys.push_back(key);
    }

    void handleMousePosition (int x, int y) {
        mouseX = x;
        mouseY = y;
    }

    void keyUpEngine (int key) {
        cout << key << endl;
        for (int kind = 0; kind < pressedKeys.size(); kind++) {
            if (pressedKeys[kind] == key) {
                pressedKeys.erase(pressedKeys.begin() + kind);
            }
        }
    }

    bool keyPress(int key) {
        for (int _key: pressedKeys) {
            if (_key == key)
                return true;
        }

        return false;
    }
};


#endif //TESINGGAME_EVENTMANAGER_H
