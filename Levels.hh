#ifndef LEVELS_HH
#define LEVELS_HH

#include "global.hh"

typedef enum {
    E_NORMAL,
    E_END
} EnemyType;

typedef struct {
    unsigned start;
    EnemyType enemyType;
    int x;
    int y;
    int vx;
    int vy;
} Level;

extern Level* levels;

#endif
