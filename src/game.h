#pragma once
#include <boost/scoped_ptr.hpp>

class Graphics;
class Player;

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

      boost::scoped_ptr<Player> player;
};
