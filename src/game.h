#pragma once
#include "animated_sprite.h"
#include <boost/scoped_ptr.hpp>

class Graphics;

class Game
{
	public:

		Game();
		~Game();

      static int kTileSize;

	private:

		void eventLoop();
		void update(int ms);
		void draw(Graphics& graphics);

      boost::scoped_ptr<AnimatedSprite> sprite;
};
