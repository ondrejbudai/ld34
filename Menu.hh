#ifndef MENU_HH
#define MENU_HH

#include "Listeners.hh"
#include "InputHandler.hh"
#include "GameState.hh"
#include "Texture.hh"

class Menu : public Listener, public GameState {
	private:
		bool running = true;
		Texture* logoTex;
		Texture* playerTex;
		Texture* enemyTex;
		Texture* guideTex[2];
	public:
		Menu(Renderer* renderer_);
		~Menu(){}
		GameState* update();
		void render();
		void event(SDL_Event *e);
};

#endif
