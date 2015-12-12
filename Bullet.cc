#include "Bullet.hh"
#include "Game.hh"

Bullet::Bullet(Renderer* renderer_, int x_, int y_){
	renderer = renderer_;
	x = x_;
	y = y_;
	texture = Texture::createFromFile("img/bullet.png", renderer);
}

void Bullet::update(){
	y -= 20;	
	if(y < 0)
		Game::getInstance()->removeEntity(this);
}

void Bullet::render(){
	texture->render(x, y);
}
