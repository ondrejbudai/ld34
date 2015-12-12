#include "Bullet.hh"
#include "Game.hh"
#include "global.hh"

Bullet::Bullet(Renderer* renderer_, int x_, int y_, int vx_, int vy_, bool isEnemy_){
	renderer = renderer_;
	x = x_;
	y = y_;
	vx = vx_;
	vy = vy_;
	isEnemy = isEnemy_;
	texture = Texture::createFromFile("img/bullet.png", renderer);
}

void Bullet::update(){
	x += vx;
	y += vy;
	Game *g = Game::getInstance();
	if(x > GAME_W || x < 0 || y > GAME_H || y < 0)
		g->removeEntity(this);

	Entity *e = g->getColliding(this, x, y);
	if(e == nullptr)
		return;
	g->removeEntity(this);
	if(e->isEnemy() == isEnemy)
		return;
	e->damage(100);
}
