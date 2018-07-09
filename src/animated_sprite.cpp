#include "animated_sprite.h"
#include "game.h"

AnimatedSprite::AnimatedSprite(const std::string& filePath,
         int sourceX, int sourceY,
         int width, int height,
         int fps, int numFrames) : Sprite(filePath, sourceX, sourceY, width, height),
         frameTime( 1000 / fps),
         numFrames(numFrames),
         currentFrame(0),
         elapsedTime(0) {

}

void AnimatedSprite::update(int ms) {

   elapsedTime += ms;

   // Time to update frame
   if ( elapsedTime > frameTime) {
      currentFrame++;
      elapsedTime = 0;

      // Normal case
      if (currentFrame < numFrames ) {

         sourceRect.x += Game::kTileSize;

      // End of animation strip case
      } else {
         sourceRect.x -= Game::kTileSize * (numFrames - 1 );
         currentFrame = 0;
      }
   }
}

