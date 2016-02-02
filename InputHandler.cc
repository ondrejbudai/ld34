#include <SDL2/SDL.h>

#include "InputHandler.hh"

bool InputHandler::update() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                return false;
            case SDL_WINDOWEVENT:
                if (e.window.event != SDL_WINDOWEVENT_SIZE_CHANGED || resizeListener == nullptr) continue;
                resizeListener->event(&e);
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP: {
                Listener* l = keyListeners[e.key.keysym.sym];
                if (l == nullptr) continue;
                l->event(&e);
            }
                break;
            default:
                break;
        }
    }

    return true;
}
