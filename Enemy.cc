#include "Enemy.hh"

Enemy::Enemy(Renderer *renderer_, int x_, int y_){
	renderer = renderer_;
	x = x_;
	y = y_;
	texture = Texture::createFromFile("img/enemy.png", renderer);	
}

void Enemy::render(){
	texture->render(x, y);
}

bool Enemy::colliding(int x_, int y_){
	return x_ > x - texture->getWidth() / 2 && x_ < x + texture->getWidth() / 2 && y_ > y - texture->getHeight() / 2  && y_ < y + texture->getHeight() / 2 ;
}
