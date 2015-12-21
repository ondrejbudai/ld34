#include "Menu.hh"
#include "Game.hh"
#include <iostream>

	Menu::Menu(Renderer* renderer_) : GameState(renderer_){
		inputHandler->registerKey(SDLK_SPACE, this);
		logoTex = new Texture("img/logo.png", renderer);
		playerTex = new Texture("img/player.png", renderer);
		enemyTex = new Texture("img/enemy.png", renderer);
		guideTex[0] = new Texture("img/guide.png", renderer);
		guideTex[1] = new Texture("img/guide2.png", renderer);
	}

	GameState* Menu::update(){
		if(!inputHandler->update())
			return NULL;
		if(!running)
			return new Game(renderer);

		return this;
	}

	void Menu::render(){
		static unsigned ticks = 0;
		logoTex->render(WINDOW_W / 2, 150);
		playerTex->render(100, 150);
		enemyTex->render(WINDOW_W - 100, 80);
		enemyTex->render(WINDOW_W - 100, 150);
		enemyTex->render(WINDOW_W - 100, 220);

		unsigned offset = (ticks / 10) % 2;

		guideTex[offset]->render(WINDOW_W / 2, 420);

		ticks++;
	}

	void Menu::event(SDL_Event *e){
		if(e->key.type == SDL_KEYUP) return;
		running = false;
	}
