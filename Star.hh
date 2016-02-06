#ifndef STAR_HH
#define STAR_HH

#include "Entity.hh"
#include <iostream>

class Star : public Entity {
private:
public:
    Star(int id_, Renderer& renderer, int x_, int y_, float scale, int alpha);

    ~Star() { delete texture; }

    bool colliding(int, int) const { return false; }

    bool colliding(Entity&) const { return false; }

    void render(unsigned l) const;
};

#endif
