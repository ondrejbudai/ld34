#ifndef ENEMY_HH
#define ENEMY_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Texture.hh"

class Enemy : public Entity {
	private:
		const int maxHealth = 750;
		int health = maxHealth;
		unsigned cooldown = 0; 
	public:
		Enemy(Renderer* renderer_, int x, int y, int vx_, int vy_);
		~Enemy(){}
		void update();
		void render(unsigned l);
		void damage(int amount);
		bool isEnemy(){return true;}
};

#endif
