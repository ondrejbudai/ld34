#include "Player.hh"
#include "Bullet.hh"
#include "Game.hh"
#include "global.hh"


Player::Player(Renderer* renderer_){
	renderer = renderer_;
	texture = new Texture("./img/player.png", renderer);
	x = texture->getWidth() / 2 + 50;
	y = GAME_H / 2;
	vx = 0;
	vy = 0;

	healthBar = new Texture("img/bar-health.png", renderer);
	healthBar->setAlpha(63);

	shieldBar = new Texture("img/bar-shield.png", renderer);
	shieldBar->setAlpha(63);
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

	if(cooldown == 0){
		Game *g = Game::getInstance();
		g->addEntity(new Bullet(renderer, x + texture->getWidth() / 2, y - 28, 20, 0, isEnemy()));
		g->addEntity(new Bullet(renderer, x + texture->getWidth() / 2, y + 28, 20, 0, isEnemy()));
		cooldown = 4;
	}

	if(cooldown > 0)
		cooldown--;

	if(shield < maxShield)
		shield += 2;
}

void Player::render(unsigned l){
	if(l == 1){
		SDL_Rect src;
		src.x = 0;
		src.y = 0;
		src.w = (float(health) / maxHealth) * healthBar->getWidth();
		src.h = healthBar->getHeight();
		healthBar->renderPart(200, WINDOW_H - renderer->getYOffset() - healthBar->getHeight() / 2 - 10, &src);

		src.x = 0;
		src.y = 0;
		src.w = (float(shield) / maxShield) * shieldBar->getWidth();
		src.h = shieldBar->getHeight();
		shieldBar->renderPart(200, -renderer->getYOffset() + shieldBar->getHeight() / 2 + 10, &src);
	} else if(l == 2) {
		texture->render(x, y);
	}
}

void Player::damage(int amount){
	shield -= amount;
	if(shield < 0){
		health += shield;
		shield = 0;
		if(health <= 0){
			health = 0;
		}
	}
}
