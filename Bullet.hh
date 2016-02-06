#ifndef BULLET_HH
#define BULLET_HH

#include "Entity.hh"
#include "Renderer.hh"
#include "Texture.hh"

class Bullet : public Entity {
private:
    bool isEnemy;
public:
    Bullet(int id, Renderer& Renderer_, int x_, int y_, float vx_, float vy_, bool isEnemy);

    ~Bullet() { delete texture; }

    void update();

    bool colliding(Entity&) const { return false; }

    bool colliding(int, int) const { return false; }
};

#endif
