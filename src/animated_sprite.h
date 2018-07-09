#pragma once
#include "sprite.h"

class AnimatedSprite : public Sprite {

   public:

      AnimatedSprite(const std::string& filePath, int sourceX, int sourceY,
               int width, int height, int fps, int numFrames);

      void update(int ms);

   private:

      const int frameTime;
      const int numFrames;
      int currentFrame;
      int elapsedTime; // Elapsed time since last frame change
};
