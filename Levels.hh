#ifndef LEVELS_HH
#define LEVELS_HH

#include "global.hh"

typedef enum {
	E_NORMAL,
} EnemyType;

typedef struct {
	unsigned start;
	EnemyType enemyType;
	int x;
	int y;
	int vx;
	int vy;
} Level;

Level levels[] = {
{0, E_NORMAL, 50, -200, -5, 0},
{0, E_NORMAL, 50, 200, -5, 0},
{1, E_NORMAL, 50, -200, -5, 0},
{1, E_NORMAL, 50, 200, -5, 0},
{0, E_NORMAL, 0, 0, 0, 0}
};

#endif
