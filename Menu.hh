#ifndef MENU_HH
#define MENU_HH

#include "Listeners.hh"
#include "InputHandler.hh"
#include "GameState.hh"

class Menu : public Listener, public GameState {
	private:
		Renderer* renderer;
		InputHandler* inputHandler;
		bool running = true;
	public:
		Menu(Renderer* renderer_);
		~Menu(){}
		GameState* run();
		void event(SDL_Event *e);
};

#endif
