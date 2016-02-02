#include "Entity.hh"
#include "global.hh"
#include "Game.hh"

void Entity::update() {
    x += vx;
    y += vy;

    if (x < 0 || x > GAME_W || y < 0 || y > GAME_H)
        Game::getInstance()->removeEntity(id);
}

bool Entity::colliding(int x_, int y_) {
    return x_ > x - texture->getWidth() / 2
           && x_ < x + texture->getWidth() / 2
           && y_ > y - texture->getHeight() / 2
           && y_ < y + texture->getHeight() / 2;
}

bool Entity::colliding(Entity& e) {
    return !(
            x + texture->getWidth() < e.getX() ||
            e.getX() + e.getW() < x ||
            y + texture->getHeight() < e.getY() ||
            e.getY() + e.getH() < y
    );
}

