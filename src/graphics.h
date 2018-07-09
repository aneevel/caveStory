#pragma once

struct SDL_Surface;
struct SDL_Rect;

class Graphics {

   public:
      Graphics();
      ~Graphics();

   void blitSurface(SDL_Surface* source,
                  SDL_Rect* source_rect,
                  SDL_Rect* dest_rect);
   void flip();
   void clear();

   private:

      SDL_Surface* screen;
};
