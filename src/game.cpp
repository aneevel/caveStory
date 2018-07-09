#include "game.h"
#include "graphics.h"
#include "input.h"
#include "player.h"
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

	// Construct input core
	Input input;

	bool running = true;
	int lastUpdateTime = SDL_GetTicks();
	SDL_Event event;

   	// Construct sprite
	player.reset(new Player(320, 240));

	// while (running) ~ 60 Hz
	// Loop lasts 1000/60 ms
	while ( running ) {

		// Start new frame
		const int START_TIME = SDL_GetTicks();
		input.beginNewFrame();

		// Process SDL events
		while (SDL_PollEvent(&event)) {
			switch (event.type) {

				// Check for keypress
				case SDL_KEYDOWN:
					
					// Pass event to input
					input.keyDownEvent(event);
					break;
				
				case SDL_KEYUP:

					// Pass event to input
					input.keyUpEvent(event);
					break;

				default:
					break;
			}
		}

		// Evaluate input for QUIT
		if (input.wasKeyPressed(SDLK_ESCAPE)) {
			running = false;
		}

		// If left and right are being pressed, stop moving
		if (input.isKeyHeld(SDLK_LEFT) && input.isKeyHeld(SDLK_RIGHT)) {

			player->stopMoving();
		}

		// If left is being pressed, start moving left
		else if (input.isKeyHeld(SDLK_LEFT)) {

			player->startMovingLeft();
		}

		// If right is being pressed, start moving right
		else if (input.isKeyHeld(SDLK_RIGHT)) {

			player->startMovingRight();
		}

		// Else, stop moving
		else {

			player->stopMoving();
		}

		// Update time
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

	graphics.clear();
   player->draw(graphics);
   graphics.flip();
}

void Game::update(int ms) {

   player->update(ms);
}
