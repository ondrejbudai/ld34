#ifndef ENEMY_HH
#define ENEMY_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Texture.hh"

class Enemy : public Entity {
	private:
		Renderer* renderer;
		Texture* texture;
		int x, y;
		const int maxHealth = 500;
		int health = maxHealth;
		unsigned cooldown = 0; 
	public:
		Enemy(Renderer* renderer_, int x, int y);
		~Enemy(){}
		void update();
		void render();
		bool colliding(int x, int y);
		void damage(int amount);
		bool isEnemy(){return true;}
};

#endif
