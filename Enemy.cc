#include "Enemy.hh"
#include "Game.hh"
#include "Bullet.hh"

#include <SDL2/SDL.h>

Enemy::Enemy(Renderer *renderer_, int x_, int y_){
	renderer = renderer_;
	x = x_;
	y = y_;
	texture = Texture::createFromFile("img/enemy.png", renderer);	
}

void Enemy::update(){
	if(cooldown == 0){
		Game::getInstance()->addEntity(new Bullet(renderer, x - 50, y, -10, 0, isEnemy()));
		cooldown = 30;
	}
	cooldown--;
}

void Enemy::render(){
	texture->render(x, y);
	renderer->renderRect(x - texture->getWidth() / 2, y + texture->getHeight() / 2, texture->getWidth(), 5, renderer->cRed);
	renderer->renderRect(x - texture->getWidth() / 2, y + texture->getHeight() / 2, ((float)health / maxHealth)* texture->getWidth(), 5, renderer->cGreen);
}

bool Enemy::colliding(int x_, int y_){
	return x_ > x - texture->getWidth() / 2 && x_ < x + texture->getWidth() / 2 && y_ > y - texture->getHeight() / 2  && y_ < y + texture->getHeight() / 2 ;
}

void Enemy::damage(int amount){
	health -= amount;
	if(health <= 0)
		Game::getInstance()->removeEntity(this);
}
