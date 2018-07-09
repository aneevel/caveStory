#include "player.h"
#include "graphics.h"
#include "game.h"

#include <cmath>

namespace {

    const float kSlowdownFactor = 0.8f; // (pixels / ms)
    const float kWalkingAcceleration = 0.0012f; // (pixels / ms) / ms
    const float kMaxSpeedX = 0.325f; // (pixels / ms)
}

Player::Player(int x, int y) : mXPosition(x), 
    mYPosition(y),
    mXVelocity(0.f),
    mXAcceleration(0.f)
{
    mSprite.reset(new AnimatedSprite("assets/MyChar.bmp", 0, 0, 
                Game::kTileSize, Game::kTileSize,
                15, 3 ));  

}

void Player::update(int elapsedTimeMS) {

    // Update animation
    mSprite->update(elapsedTimeMS);

    // Update physics
    mXPosition += round(mXVelocity * elapsedTimeMS);
    mXVelocity += mXAcceleration * elapsedTimeMS;

    // Cap speed if acceleration
    if ( mXAcceleration < 0.0f ) {

        mXVelocity = std::max(mXVelocity, -kMaxSpeedX);
    } else if (mXAcceleration > 0.0f) {

        mXVelocity = std::min(mXVelocity, kMaxSpeedX);

    // Apply slowdown factor
    } else {

        mXVelocity *= kSlowdownFactor;
    }
}

void Player::draw(Graphics& graphics) {

    mSprite->draw(graphics, mXPosition, mYPosition);  
}

void Player::startMovingLeft() {

    mXAcceleration = -kWalkingAcceleration;
}

void Player::startMovingRight() {

    mXAcceleration = kWalkingAcceleration;
}

void Player::stopMoving() {

    mXAcceleration = 0;
}