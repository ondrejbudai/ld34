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
{0, E_NORMAL, 50, -150, -5, 0},
{0, E_NORMAL, 50, 150, -5, 0},
{60, E_NORMAL, 50, -150, -5, 0},
{60, E_NORMAL, 50, 150, -5, 0},
{120, E_NORMAL, 50, 0, -5, 0},
{140, E_NORMAL, 50, -75, -5, 0},
{140, E_NORMAL, 50, 75, -5, 0},
{160, E_NORMAL, 50, -150, -5, 0},
{160, E_NORMAL, 50, 150, -5, 0},
{0, E_NORMAL, 0, 0, 0, 0}
};

#endif
