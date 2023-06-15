//
// Created by Maksoni on 27.05.2023.
//

#include "TextureManager.h"

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *pRenderer) {
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if(pTempSurface == 0)
    {
        return false;
    }
    SDL_Texture* pTexture =
            SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
// everything went ok, add the texture to our list
    if(pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }
// reaching here means something went wrong
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int dx, int dy, int dwidth, int dheight, SDL_Renderer *pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    destRect.w = width;
    destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    srcRect.x = dx;
    srcRect.y = dy;
    srcRect.w = dwidth;
    srcRect.h = dheight;


    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);


}

void TextureManager::drawFrameAlpha(std::string id, int x, int y, int width, int height, int dx, int dy, int dwidth,
                                    int dheight, SDL_Renderer *pRenderer, SDL_RendererFlip flip, int alpha) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    destRect.w = width;
    destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    srcRect.x = dx;
    srcRect.y = dy;
    srcRect.w = dwidth;
    srcRect.h = dheight;

    SDL_SetTextureAlphaMod(m_textureMap[id], alpha);

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
    SDL_SetTextureAlphaMod(m_textureMap[id], 255);
}

void TextureManager::drawText(SDL_Renderer* pRenderer, const char* text, int fontSize, int x, int y, SDL_Color color) {
    TTF_Font* font = TTF_OpenFont("../assets/best-font.TTF", fontSize);

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(pRenderer, textSurface);

    SDL_Rect dstRect = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(pRenderer, textTexture, NULL, &dstRect);
}


