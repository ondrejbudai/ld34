#include <cmath>

#include "Enemy.hh"
#include "Game.hh"
#include "Bullet.hh"

Enemy::Enemy(Renderer *renderer_, int x_, int y_, int vx_, int vy_){
	renderer = renderer_;
	x = x_;
	y = y_;
	vx = vx_;
	vy = vy_;
	texture = Texture::createFromFile("img/enemy.png", renderer);	
}

void Enemy::update(){
	x += vx;
	y += vy;

	Game* g = Game::getInstance();

	if(x < 0){
		g->removeEntity(this);
		return;
	}

	Player* p = g->getPlayer();
	if(colliding(p)){
		int pHealth = p->getHealth();
		int d = pHealth < health ? pHealth : health;
		p->damage(d);
		damage(d);
	}

	if(cooldown == 0){
		Player *p = g->getPlayer();
		int dx = p->getX() - x;
		int dy = p->getY() - y;

		float magnitude = dx * dx + dy * dy;

		dx = dx / sqrt(magnitude) * 10;
		dy = dy / sqrt(magnitude) * 10;

		//g->addEntity(new Bullet(renderer, x - 50, y, dx, dy, isEnemy()));
		cooldown = 30;
	}
	cooldown--;
}

void Enemy::render(){
	texture->render(x, y);
	renderer->renderRect(x - texture->getWidth() / 2, y + texture->getHeight() / 2, texture->getWidth(), 5, renderer->cRed);
	renderer->renderRect(x - texture->getWidth() / 2, y + texture->getHeight() / 2, ((float)health / maxHealth)* texture->getWidth(), 5, renderer->cGreen);
}

void Enemy::damage(int amount){
	health -= amount;
	if(health <= 0)
		Game::getInstance()->removeEntity(this);
}
