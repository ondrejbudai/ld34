#include "Menu.hh"
#include "Game.hh"

	Menu::Menu(Renderer* renderer_){
		inputHandler = new InputHandler();
		renderer = renderer_;

		inputHandler->registerKey(SDLK_w, this);
	}

	GameState* Menu::run(){
		while(inputHandler->update()){
			if(!running)
				return new Game(renderer);
			
		}


		return NULL;
	}

	void Menu::event(SDL_Event *e){
		running = false;
	}
