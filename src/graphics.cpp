#include "graphics.h"
#include <SDL/SDL.h>

namespace {
	const int kScreenWidth = 640;
	const int kScreenHeight = 480;
	const int kBitsPerPixel = 32;
}

Graphics::Graphics() {

  	// Create screen
	screen = SDL_SetVideoMode(kScreenWidth, kScreenHeight, kBitsPerPixel,
			SDL_HWSURFACE);

}

Graphics::~Graphics() {

   SDL_FreeSurface(screen);
}

void Graphics::blitSurface( SDL_Surface *source,
         SDL_Rect *source_rect,
         SDL_Rect *dest_rect) {

   SDL_BlitSurface(source, source_rect, screen, dest_rect);
}

void Graphics::flip() {
   SDL_Flip(screen);
}

void Graphics::clear() {
	SDL_FillRect(screen, NULL, 0);
}