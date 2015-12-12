#include "Bullet.hh"
#include "Game.hh"
#include "global.hh"

Bullet::Bullet(Renderer* renderer_, int x_, int y_){
	renderer = renderer_;
	x = x_;
	y = y_;
	texture = Texture::createFromFile("img/bullet.png", renderer);
}

void Bullet::update(){
	x += 20;	
	Game *g = Game::getInstance();
	if(x > HSIZE)
		g->removeEntity(this);

	Entity *e = g->getColliding(x, y);
	if(e == nullptr)
		return;
	g->removeEntity(this);

}

void Bullet::render(){
	texture->render(x, y);
}
