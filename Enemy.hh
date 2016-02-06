#ifndef ENEMY_HH
#define ENEMY_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Texture.hh"

class Enemy : public Entity {
private:
    const int maxHealth = 1000;
    int health = maxHealth;
    unsigned cooldown = 0;
public:
    Enemy(int id, Renderer& renderer_, int x, int y, int vx_, int vy_);

    ~Enemy() { }

    void update();

    void render(unsigned l) const;

    void damage(int amount);

    bool isEnemy() const { return true; }
};

#endif
