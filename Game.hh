#ifndef GAME_HH
#define GAME_HH

#include <vector>
#include "GameState.hh"
#include "Entity.hh"
#include "Renderer.hh"
#include "Player.hh"
#include "Levels.hh"
#include "Listeners.hh"

class Game : public GameState, public Listener {

	private:
		std::vector<Entity *> entityList;
		std::vector<Entity *> toAddList;
		std::vector<Entity *> toDelList;
		Player* player;
		Level* current = levels;
		unsigned ticks = 0;
		bool close = false;
		Texture* deathTex[2];


		void updateLevel(unsigned ticks);
		static Game* instance;
	public:
		Game(Renderer* renderer_);
		~Game(){}
		GameState* update();
		void render();

		void event(SDL_Event* e);

		void addEntity(Entity *e);
		void removeEntity(Entity *e);
		Entity* getColliding(Entity *e, int x, int y);
		Player* getPlayer(){return player;}
		static Game* getInstance(){return Game::instance;}
		
};

#endif
