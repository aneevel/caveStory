#include "input.h"

void Input::beginNewFrame() {

    // Clear out key info
    mPressedKeys.clear();
    mReleasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Event& event) {

    mPressedKeys[event.key.keysym.sym] = true;
    mHeldKeys[event.key.keysym.sym] = true;
}

void Input::keyUpEvent(const SDL_Event& event) {

    mReleasedKeys[event.key.keysym.sym] = true;
    mHeldKeys[event.key.keysym.sym] = false;
}

bool Input::wasKeyPressed(SDLKey key) {

    return mPressedKeys[key];
}

bool Input::wasKeyReleased(SDLKey key) {

    return mReleasedKeys[key];
}

bool Input::isKeyHeld(SDLKey key) {

    return mHeldKeys[key];
}
