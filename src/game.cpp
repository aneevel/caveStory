#include "game.h"
#include <SDL/SDL.h>

namespace {
	const int kScreenWidth = 640;
	const int kScreenHeight = 480;
	const int kBitsPerPixel = 32;
	const int kFPS = 60;
}

Game::Game() {

	// Init SDL subsystems
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create screen
	screen = SDL_SetVideoMode(kScreenWidth, kScreenHeight, kBitsPerPixel,
			SDL_FULLSCREEN);

	// Remove cursor
	SDL_ShowCursor( SDL_DISABLE );

	// Enter main loop
	eventLoop();
}

Game::~Game() {
	SDL_FreeSurface(screen);
	SDL_Quit();
}

void Game::eventLoop() {

	bool running = true;
	SDL_Event event;

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
		update();

		// Draw phase
		draw();

		// Output FPS diagnostic
		const int ELAPSED_TIME = SDL_GetTicks() - START_TIME;
		SDL_Delay( 1000 /*ms*/ / kFPS /* fps */ - ELAPSED_TIME );

		const float SECONDS_PER_FRAME = (SDL_GetTicks() - START_TIME) / 1000.0;
		const float FPS = 1 / (SECONDS_PER_FRAME);
		printf("FPS=%f\n", FPS);
	}
}

void Game::draw() {}

void Game::update() {}
