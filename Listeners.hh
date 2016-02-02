#ifndef KEY_LISTENER_H_
#define KEY_LISTENER_H_

#include <SDL2/SDL.h>

class Listener {
public:
    virtual ~Listener() { }

    virtual void event(SDL_Event* e) = 0;
};

#endif
