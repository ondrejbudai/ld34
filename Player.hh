#ifndef PLAYER_HH
#define PLAYER_HH

#include "Renderer.hh"
#include "Listeners.hh"
#include "Texture.hh"
#include "Entity.hh"

class Player : public Listener, public Entity {
	private:
		Renderer* renderer;
		Texture* texture;
		int x, y;
		int xv, yv;
		unsigned cooldown = 0;
		bool shooting = false;
		int maxHealth = 1000;
		int health = maxHealth;
		int maxShield = 1000;
		int shield = maxShield;
	public:
		Player(Renderer* r);
		~Player(){delete texture;}
		void event(SDL_Event *e);
		void update();
		void render();
		void damage(int amount);
		bool isEnemy(){return false;}
		bool colliding(int x_, int y_);

};

#endif
