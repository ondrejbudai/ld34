#include "Player.hh"


Player::Player(Renderer* renderer_){
	renderer = renderer_;
	texture = Texture::createFromFile("./img/player.png", renderer);
	x = 100;
	y = 100;
	xv = 0;
	yv = 0;
}

void Player::event(SDL_Event *e){
	if(e->key.repeat) return;
	switch(e->key.keysym.sym){
		case SDLK_s:
			if(e->key.type == SDL_KEYDOWN)
				xv -= 5;
			else
				xv += 5;
			break;
		case SDLK_l:
			if(e->key.type == SDL_KEYDOWN)
				xv += 5;
			else
				xv -= 5;
	}
}

void Player::update(){
	x += xv; 
}

void Player::render(){
	texture->render(x, y);
}

