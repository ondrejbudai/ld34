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
{0, E_NORMAL, 50, -150, -SCROLL_SPEED, 0},
{0, E_NORMAL, 50, 150, -SCROLL_SPEED, 0},
{60, E_NORMAL, 50, -150, -SCROLL_SPEED, 0},
{60, E_NORMAL, 50, 150, -SCROLL_SPEED, 0},
{120, E_NORMAL, 50, 0, -SCROLL_SPEED, 0},
{140, E_NORMAL, 50, -75, -SCROLL_SPEED, 0},
{140, E_NORMAL, 50, 75, -SCROLL_SPEED, 0},
{160, E_NORMAL, 50, -150, -SCROLL_SPEED, 0},
{160, E_NORMAL, 50, 150, -SCROLL_SPEED, 0},

{240, E_NORMAL, 50, -150, -SCROLL_SPEED, 0},
{240, E_NORMAL, 50, 150, -SCROLL_SPEED, 0},
{300, E_NORMAL, 50, -150, -SCROLL_SPEED, 0},
{300, E_NORMAL, 50, 150, -SCROLL_SPEED, 0},

{320, E_NORMAL, 50, -150, -SCROLL_SPEED, 0},
{320, E_NORMAL, 50, 150, -SCROLL_SPEED, 0},
{330, E_NORMAL, 50, 0, -SCROLL_SPEED, 0},
{340, E_NORMAL, 50, -150, -SCROLL_SPEED, 0},
{340, E_NORMAL, 50, 150, -SCROLL_SPEED, 0},

{0, E_NORMAL, 0, 0, 0, 0}
};

#endif
