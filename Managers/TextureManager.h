//
// Created by Maksoni on 27.05.2023.
//

#ifndef TESINGGAME_TEXTUREMANAGER_H
#define TESINGGAME_TEXTUREMANAGER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include <map>

using namespace std;

class TextureManager {
public:
    map<std::string, SDL_Texture*> m_textureMap;

    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip);
    void drawFrame(std::string, int x, int y, int width, int height, int dx, int dy, int dwidth, int dheight, SDL_Renderer *pRenderer, SDL_RendererFlip flip);
    void drawFrameAlpha(std::string, int x, int y, int width, int height, int dx, int dy, int dwidth, int dheight, SDL_Renderer *pRenderer, SDL_RendererFlip flip, int alpha);
    void drawText(SDL_Renderer* pRenderer, const char* text, int fontSize, int x, int y, SDL_Color color);
};



#endif //TESINGGAME_TEXTUREMANAGER_H
