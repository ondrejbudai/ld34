#include <cmath>

#include "Enemy.hh"
#include "Game.hh"
#include "Bullet.hh"

Enemy::Enemy(int id_, Renderer& renderer_, int x_, int y_, int vx_, int vy_) : Entity(id_, renderer_) {
    x = x_;
    y = y_;
    vx = vx_;
    vy = vy_;
    texture = new Texture("img/enemy.png", renderer);
}

void Enemy::update() {
    x += vx;
    y += vy;

    if (y <= 0 || y >= GAME_H) {
        vy = -vy;
    }

    Game* g = Game::getInstance();

    if (x < 0) {
        g->removeEntity(id);
        return;
    }

    Player& p = g->getPlayer();
    if (colliding(p)) {
        int pHealth = p.getHealth();
        int d = pHealth < health ? pHealth : health;
        p.damage(d);
        damage(d);
    }

    if (cooldown == 0) {
        float dx = p.getX() - (x - 50);
        float dy = p.getY() - y;

        if (dx < 0) {
            float magnitude = sqrt(dx * dx + dy * dy);

            dx = dx / magnitude * 10;
            dy = dy / magnitude * 10;

            g->addEntity(new Bullet(g->getNextId(), renderer, x - 50, y, dx, dy, isEnemy()));
            cooldown = 50;
        }
    }
    cooldown--;
}

void Enemy::render(unsigned l) {
    const static SDL_Color cRed = {255, 0, 0, 127};
    const static SDL_Color cGreen = {0, 255, 0, 127};
    if (l != 2) return;
    texture->render(x, y);
    if (health == maxHealth) return;
    renderer.renderRect(x - texture->getWidth() / 2, y + texture->getHeight() / 2, texture->getWidth(), 5, cRed);
    renderer.renderRect(x - texture->getWidth() / 2, y + texture->getHeight() / 2,
                        (float(health) / maxHealth) * texture->getWidth(), 5, cGreen);
}

void Enemy::damage(int amount) {
    health -= amount;
    if (health <= 0)
        Game::getInstance()->removeEntity(id);
}
