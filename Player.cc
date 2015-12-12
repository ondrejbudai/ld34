#include "Player.hh"
#include "Bullet.hh"
#include "Game.hh"
#include "global.hh"


Player::Player(Renderer* renderer_){
	renderer = renderer_;
	texture = Texture::createFromFile("./img/player.png", renderer);
	x = texture->getWidth() / 2;
	y = VSIZE / 2 + texture->getHeight() / 2;
	xv = 0;
	yv = 0;
}

void Player::event(SDL_Event *e){
	if(e->key.repeat) return;
	switch(e->key.keysym.sym){
		case SDLK_UP:
			if(e->key.type == SDL_KEYDOWN)
				yv -= 5;
			else
				yv += 5;
			break;
	 	case SDLK_DOWN:
			if(e->key.type == SDL_KEYDOWN)
				yv += 5;
			else
				yv -= 5;
			break;
		case SDLK_w:
			if(e->key.type == SDL_KEYDOWN){
				shooting = true;
			} else
				shooting = false;
			break;
		default:
			break;
	}
}

void Player::update(){
	y += yv;
	if(y < 0)
		y = 0;
	else if(y > HSIZE)
		y = HSIZE;
	if(shooting){
		Game * g = Game::getInstance();
		g->addEntity(new Bullet(renderer, x + texture->getWidth() / 2, y - texture->getHeight() / 2));
		g->addEntity(new Bullet(renderer, x + texture->getWidth() / 2, y + texture->getHeight() / 2));
	}
}

void Player::render(){
	texture->render(x, y);
}

