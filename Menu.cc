#include "Menu.hh"
#include "Game.hh"

Menu::Menu(Renderer& renderer_)
		: GameState(renderer_),
		  logoTex{"img/logo.png", renderer},
		  playerTex{"img/player.png", renderer},
		  enemyTex{"img/enemy.png", renderer},
		  guideTex{{"img/guide.png",  renderer},
				   {"img/guide2.png", renderer}} {
	inputHandler.registerKey(SDLK_SPACE, this);
	}

	GameState* Menu::update(){
		if (!inputHandler.update())
			return nullptr;
		if(!running)
			return new Game(renderer);

		return this;
	}

	void Menu::render(){
		static unsigned ticks = 0;
		logoTex.render(WINDOW_W / 2, 150);
		playerTex.render(100, 150);
		enemyTex.render(WINDOW_W - 100, 80);
		enemyTex.render(WINDOW_W - 100, 150);
		enemyTex.render(WINDOW_W - 100, 220);

		unsigned offset = (ticks / 10) % 2;

		guideTex[offset].render(WINDOW_W / 2, 420);

		ticks++;
	}

	void Menu::event(SDL_Event *e){
		if(e->key.type == SDL_KEYUP) return;
		running = false;
	}
