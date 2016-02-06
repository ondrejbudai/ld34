#ifndef ENTITY_hh
#define ENTITY_hh

#include "Texture.hh"

class Entity {
protected:
    float x = 0, y = 0;
    float vx = 0, vy = 0;
    Texture* texture = nullptr;
    Renderer& renderer;
    unsigned level = 0;

    Entity(int id_, Renderer& renderer_) : renderer(renderer_), id(id_) { }

public:
    const int id;

    Entity(const Entity&) = delete;

    Entity& operator=(const Entity&) = delete;

    virtual void update();

    virtual void render(unsigned l) const { if (texture && level == l) texture->render(x, y); }

    virtual ~Entity() { }

    virtual bool colliding(int x_, int y_) const;

    virtual bool colliding(Entity& e) const;

    virtual void damage(int amount) { (void) amount; }

    virtual bool isEnemy() const { return false; }

    int getX() const { return x; }

    int getY() const { return y; }

    int getW() const { return texture->getWidth(); }

    int getH() const { return texture->getHeight(); }
};

#endif
