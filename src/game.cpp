#include "game.h"
#include "graphics.h"
#include <SDL/SDL.h>

namespace  {
	const int kFPS = 60;
}

int Game::kTileSize = 32;

Game::Game() {

	// Init SDL subsystems
	SDL_Init(SDL_INIT_EVERYTHING);

	// Remove cursor
	SDL_ShowCursor( SDL_DISABLE );

	// Enter main loop
	eventLoop();
}

Game::~Game() {
	SDL_Quit();
}

void Game::eventLoop() {

   // Construct graphics core
   Graphics graphics;

	bool running = true;
   int lastUpdateTime = SDL_GetTicks();
	SDL_Event event;

   // Construct sprite
   sprite.reset(new AnimatedSprite("assets/MyChar.bmp", 0, 0, kTileSize, kTileSize,
               15, 3 ));

	// while (running) ~ 60 Hz
	// Loop lasts 1000/60 ms
	while ( running ) {

		const int START_TIME = SDL_GetTicks();

		// Process SDL events
		while (SDL_PollEvent(&event)) {
			switch (event.type) {

				// Check for keypress
				case SDL_KEYDOWN:
					// Check for escape event
					if (event.key.keysym.sym == SDLK_ESCAPE) {
						running = false;
					}
				default:
					break;
			}
		}

		// Update phase
      int currentTime = SDL_GetTicks();
		update(currentTime - lastUpdateTime);
      lastUpdateTime = currentTime;

		// Draw phase
		draw(graphics);

		// Output FPS diagnostic
		const int ELAPSED_TIME = SDL_GetTicks() - START_TIME;
		SDL_Delay( 1000 /*ms*/ / kFPS /* fps */ - ELAPSED_TIME );

		const float SECONDS_PER_FRAME = (SDL_GetTicks() - START_TIME) / 1000.0;
		const float FPS = 1 / (SECONDS_PER_FRAME);
	}
}

void Game::draw(Graphics& graphics) {

   sprite->draw(graphics, 320, 240);
   graphics.flip();
}

void Game::update(int ms) {

   sprite->update(ms);
}
