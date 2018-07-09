#include "sprite.h"
#include "graphics.h"

Sprite::Sprite(const std::string& filePath, int sourceX, int sourceY,
               int width, int height) {

   spriteSheet = SDL_LoadBMP(filePath.c_str());
   if ( !spriteSheet) {
      printf("Unable to load sprite! SDL_Error: %s\n", SDL_GetError());
   }

   sourceRect.x = sourceX;
   sourceRect.y = sourceY;
   sourceRect.w = width;
   sourceRect.h = height;
}

Sprite::~Sprite() {

   SDL_FreeSurface(spriteSheet);
}

void Sprite::draw(Graphics& graphics, int x, int y) {

   SDL_Rect destRect;
   destRect.x = x;
   destRect.y = y;
   graphics.blitSurface(spriteSheet, &sourceRect, &destRect);
}

