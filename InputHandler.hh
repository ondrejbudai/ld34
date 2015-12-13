#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_

#include <map>
#include <SDL2/SDL.h>

#include "Listeners.hh"

using std::map;

class InputHandler {
private:
	
	map<SDL_Keycode,Listener *> keyListeners;
	Listener* resizeListener;

public:
	InputHandler();
	bool update();

	void registerKey(SDL_Keycode keycode, Listener* listener) {keyListeners[keycode] = listener;}
	void registerResize(Listener* listener){resizeListener = listener;}
};

#endif
