#pragma once
#include <string>
#include <SDL/SDL.h>

class Graphics;

class Sprite {

   public:

      Sprite(const std::string& filePath, int sourceX, int sourceY,
               int width, int height);
      virtual ~Sprite();

      void draw(Graphics& graphics, int x, int y);

      virtual void update(int /*elapsed time in ms*/ ms) = 0;

   protected:

      SDL_Rect sourceRect;

   private:

      SDL_Surface* spriteSheet;

};
