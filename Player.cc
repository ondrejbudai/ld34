#include "Player.hh"
#include "Bullet.hh"
#include "Game.hh"
#include "global.hh"


Player::Player(Renderer* renderer_){
	renderer = renderer_;
	texture = Texture::createFromFile("./img/player.png", renderer);
	x = texture->getWidth() / 2 + 50;
	y = GAME_H / 2 + texture->getHeight() / 2;
	vx = 0;
	vy = 0;
}

void Player::event(SDL_Event *e){
	if(e->key.repeat) return;
	switch(e->key.keysym.sym){
		case SDLK_UP:
			if(e->key.type == SDL_KEYDOWN)
				up = true;
			else
				up = false;
			break;
	 	case SDLK_DOWN:
			if(e->key.type == SDL_KEYDOWN)
				down = true;
			else
				down = false;
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
	vy = (down ? 8 : 0) + (up ? -8 : 0);
	y += vy;
	if(y < texture->getHeight() / 2)
		y = texture->getHeight() / 2;
	else if(y > GAME_H - texture->getHeight() / 2)
		y = GAME_H - texture->getHeight() / 2;

	if(shooting && cooldown == 0){
		Game *g = Game::getInstance();
		g->addEntity(new Bullet(renderer, x + texture->getWidth() / 2, y - 28, 20, 0, isEnemy()));
		g->addEntity(new Bullet(renderer, x + texture->getWidth() / 2, y + 28, 20, 0, isEnemy()));
		cooldown = 4;
	}

	if(cooldown > 0)
		cooldown--;

	if(shield < maxShield)
		shield++;
}

void Player::render(unsigned l){
	if(l != 1) return;
	texture->render(x, y);

	renderer->renderRect(0, WINDOW_H - 10, WINDOW_W, WINDOW_H, renderer->cLightblue);
	renderer->renderRect(0, WINDOW_H - 10, ((float) shield / maxShield) * WINDOW_W, WINDOW_H, renderer->cBlue);
	renderer->renderRect(0, WINDOW_H - 5, WINDOW_W, WINDOW_H, renderer->cRed);
	renderer->renderRect(0, WINDOW_H - 5, ((float) health / maxHealth) * WINDOW_W, WINDOW_H, renderer->cGreen);
}

void Player::damage(int amount){
	shield -= amount;
	if(shield < 0){
		health += shield;
		shield = 0;
		if(health <= 0){
			health = maxHealth;
		}
	}
}
