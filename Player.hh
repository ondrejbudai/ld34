#ifndef PLAYER_HH
#define PLAYER_HH

#include "Renderer.hh"
#include "Listeners.hh"
#include "Texture.hh"
#include "Entity.hh"

class Player : public Listener, public Entity {
	private:
		unsigned cooldown = 0;
		bool up = false, down = false;
		int maxHealth = 1000;
		int health = maxHealth;
		int maxShield = 500;
		int shield = maxShield;
		Texture* healthBar;
		Texture* shieldBar;
	public:
		Player(Renderer* r);
		~Player(){delete texture;}
		void event(SDL_Event *e);
		void update();
		void render(unsigned l);
		void damage(int amount);
		bool isEnemy(){return false;}
		int getHealth(){return health;}
};

#endif
