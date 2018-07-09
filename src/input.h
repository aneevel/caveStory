#pragma once
#include <unordered_map>
#include <SDL/SDL.h>

class Input
{
    public:

        void beginNewFrame();
        
        // SDL Input wrappers
        void keyDownEvent(const SDL_Event& event);
        void keyUpEvent(const SDL_Event& event);

        // Helpers
        bool wasKeyPressed(SDLKey key);
        bool wasKeyReleased(SDLKey key);
        bool isKeyHeld(SDLKey key);

    private:


        std::unordered_map<SDLKey, bool> mHeldKeys;
        std::unordered_map<SDLKey, bool> mPressedKeys;
        std::unordered_map<SDLKey, bool> mReleasedKeys;

};