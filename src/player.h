#pragma once
#include <boost/scoped_ptr.hpp>
#include "animated_sprite.h"
#include "sprite.h"

class Graphics;
class Player {

    public:

        Player(int x, int y);

        void update(int elasedTimeMS);
        void draw(Graphics& graphics);

        void startMovingLeft();
        void startMovingRight();
        void stopMoving();

    private:

        boost::scoped_ptr<AnimatedSprite> mSprite;
        int mXPosition;
        int mYPosition;
        float mXAcceleration;
        float mXVelocity;

};