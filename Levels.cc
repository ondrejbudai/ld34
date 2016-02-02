#include "Levels.hh"

const unsigned w0 = 100;
const unsigned w1 = w0 + 1100;
const unsigned w2 = w1 + 1150;
const unsigned w3 = w2 + 850;
const unsigned w4 = w3 + 800;

static Level ilevels[] = {
        {w0 + 0,        E_NORMAL, 20, 0,    -SCROLL_SPEED / 2, 0},
        {w0 + 100,      E_NORMAL, 20, 50,   -SCROLL_SPEED / 2, 0},
        {w0 + 100,      E_NORMAL, 20, -50,  -SCROLL_SPEED / 2, 0},

        {w0 + 200,      E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},

        {w0 + 250,      E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w0 + 250,      E_NORMAL, 20, +50,  -SCROLL_SPEED,     0},

        {w0 + 320,      E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w0 + 320,      E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w0 + 320,      E_NORMAL, 20, +100, -SCROLL_SPEED,     0},

        {w0 + 370 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w0 + 370 + 20, E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w0 + 370 + 20, E_NORMAL, 20, +100, -SCROLL_SPEED,     0},

        {w0 + 420 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w0 + 420 + 20, E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w0 + 420 + 20, E_NORMAL, 20, +100, -SCROLL_SPEED,     0},

        {w0 + 470 + 0,  E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w0 + 470 + 0,  E_NORMAL, 20, +100, -SCROLL_SPEED,     0},

        {w0 + 570 + 0,  E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w0 + 570 + 0,  E_NORMAL, 20, +150, -SCROLL_SPEED,     0},
        {w0 + 570 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},

        {w0 + 620 + 0,  E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w0 + 620 + 0,  E_NORMAL, 20, +150, -SCROLL_SPEED,     0},
        {w0 + 620 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},

        {w0 + 700 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w0 + 700 + 20, E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w0 + 700 + 20, E_NORMAL, 20, +100, -SCROLL_SPEED,     0},

        {w0 + 750 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w0 + 750 + 20, E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w0 + 750 + 20, E_NORMAL, 20, +150, -SCROLL_SPEED,     0},

        {w0 + 850,      E_NORMAL, 20, -200, -SCROLL_SPEED,     0},
        {w0 + 850,      E_NORMAL, 20, +200, -SCROLL_SPEED,     0},

        {w1 + 0,        E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 0,        E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},
        {w1 + 60,       E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 60,       E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},
        {w1 + 120,      E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w1 + 140,      E_NORMAL, 20, -75,  -SCROLL_SPEED,     0},
        {w1 + 140,      E_NORMAL, 20, 75,   -SCROLL_SPEED,     0},
        {w1 + 160,      E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 160,      E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},

        {w1 + 240,      E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 240,      E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},

        {w1 + 300,      E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 300,      E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},
        {w1 + 320,      E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w1 + 320,      E_NORMAL, 20, 100,  -SCROLL_SPEED,     0},
        {w1 + 330,      E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w1 + 340,      E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w1 + 340,      E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},


        {w1 + 420,      E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 420,      E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},

        {w1 + 500,      E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w1 + 510,      E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w1 + 510,      E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w1 + 520,      E_NORMAL, 20, 100,  -SCROLL_SPEED,     0},
        {w1 + 520,      E_NORMAL, 20, -100, -SCROLL_SPEED,     0},

        {w1 + 550,      E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w1 + 560,      E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w1 + 560,      E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w1 + 570,      E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w1 + 570,      E_NORMAL, 20, 100,  -SCROLL_SPEED,     0},

        {w1 + 700 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w1 + 700 + 10, E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w1 + 700 + 10, E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w1 + 700 + 20, E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w1 + 700 + 20, E_NORMAL, 20, 100,  -SCROLL_SPEED,     0},
        {w1 + 700 + 30, E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 700 + 30, E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},

        {w1 + 750 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w1 + 750 + 10, E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w1 + 750 + 10, E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w1 + 750 + 20, E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w1 + 750 + 20, E_NORMAL, 20, 100,  -SCROLL_SPEED,     0},
        {w1 + 750 + 30, E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 750 + 30, E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},

        {w1 + 850 + 0,  E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},
        {w1 + 850 + 10, E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w1 + 850 + 10, E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w1 + 850 + 20, E_NORMAL, 20, -100, -SCROLL_SPEED,     0},
        {w1 + 850 + 20, E_NORMAL, 20, 100,  -SCROLL_SPEED,     0},
        {w1 + 850 + 30, E_NORMAL, 20, -150, -SCROLL_SPEED,     0},
        {w1 + 850 + 30, E_NORMAL, 20, 150,  -SCROLL_SPEED,     0},
        {w1 + 850 + 40, E_NORMAL, 20, -200, -SCROLL_SPEED,     0},
        {w1 + 850 + 40, E_NORMAL, 20, 200,  -SCROLL_SPEED,     0},

        {w2 + 0 + 0,    E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 0 + 0,    E_NORMAL, 20, 50,   -SCROLL_SPEED,     2},

        {w2 + 50 + 0,   E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 50 + 0,   E_NORMAL, 20, 50,   -SCROLL_SPEED,     2},

        {w2 + 100 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 100 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED,     2},
        {w2 + 100 + 20, E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},

        {w2 + 180 + 0,  E_NORMAL, 20, -200, -SCROLL_SPEED,     2},
        {w2 + 180 + 0,  E_NORMAL, 20, 200,  -SCROLL_SPEED,     -2},
        {w2 + 180 + 20, E_NORMAL, 20, 0,    -SCROLL_SPEED,     0},

        {w2 + 250 + 0,  E_NORMAL, 20, -200, -SCROLL_SPEED,     2},
        {w2 + 250 + 0,  E_NORMAL, 20, 200,  -SCROLL_SPEED,     -2},
        {w2 + 250 + 20, E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w2 + 250 + 20, E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},

        {w2 + 320 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 320 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED,     +2},
        {w2 + 320 + 20, E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w2 + 320 + 20, E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},

        {w2 + 400 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 400 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED,     +2},
        {w2 + 400 + 20, E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 400 + 20, E_NORMAL, 20, 50,   -SCROLL_SPEED,     +2},
        {w2 + 400 + 40, E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 400 + 40, E_NORMAL, 20, 50,   -SCROLL_SPEED,     +2},

        {w2 + 500 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 500 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED,     +2},
        {w2 + 500 + 20, E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w2 + 500 + 20, E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w2 + 500 + 40, E_NORMAL, 20, 100,  -SCROLL_SPEED,     0},
        {w2 + 500 + 40, E_NORMAL, 20, -100, -SCROLL_SPEED,     0},

        {w2 + 600 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED,     -2},
        {w2 + 600 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED,     +2},
        {w2 + 600 + 20, E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w2 + 600 + 20, E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w2 + 600 + 40, E_NORMAL, 20, 100,  -SCROLL_SPEED,     0},
        {w2 + 600 + 40, E_NORMAL, 20, -100, -SCROLL_SPEED,     0},


        {w3 + 0 + 0,    E_NORMAL, 20, 0,    -SCROLL_SPEED * 2, 0},

        {w3 + 50 + 0,   E_NORMAL, 20, 0,    -SCROLL_SPEED * 2, 0},

        {w3 + 100 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 0},
        {w3 + 100 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, 0},

        {w3 + 150 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 0},
        {w3 + 150 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, 0},

        {w3 + 220 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 2},
        {w3 + 220 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, -2},

        {w3 + 270 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 2},
        {w3 + 270 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, -2},
        {w3 + 270 + 20, E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 2},
        {w3 + 270 + 20, E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, -2},

        {w3 + 350 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 2},
        {w3 + 350 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, -2},

        {w3 + 400 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 0},
        {w3 + 400 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, 0},
        {w3 + 400 + 20, E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w3 + 400 + 20, E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},

        {w3 + 470 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED,     0},
        {w3 + 470 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED,     0},
        {w3 + 470 + 20, E_NORMAL, 20, 100,  -SCROLL_SPEED * 2, 0},
        {w3 + 470 + 20, E_NORMAL, 20, -100, -SCROLL_SPEED * 2, 0},

        {w3 + 570 + 0,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 2},
        {w3 + 570 + 0,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, -2},
        {w3 + 570 + 20, E_NORMAL, 20, 50,   -SCROLL_SPEED * 2, 2},
        {w3 + 570 + 20, E_NORMAL, 20, -50,  -SCROLL_SPEED * 2, -2},


        {w4 + 0 + 0,    E_NORMAL, 20, -200, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 0,    E_NORMAL, 20, -150, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 0,    E_NORMAL, 20, -100, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 0,    E_NORMAL, 20, -50,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 0,    E_NORMAL, 20, 0,    -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 0,    E_NORMAL, 20, 50,   -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 0,    E_NORMAL, 20, 100,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 0,    E_NORMAL, 20, 150,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 0,    E_NORMAL, 20, 200,  -SCROLL_SPEED * 4, 0},

        {w4 + 0 + 100,  E_NORMAL, 20, -200, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 100,  E_NORMAL, 20, -150, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 100,  E_NORMAL, 20, -100, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 100,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 100,  E_NORMAL, 20, 0,    -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 100,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 100,  E_NORMAL, 20, 100,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 100,  E_NORMAL, 20, 150,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 100,  E_NORMAL, 20, 200,  -SCROLL_SPEED * 4, 0},

        {w4 + 0 + 200,  E_NORMAL, 20, -200, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 200,  E_NORMAL, 20, -150, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 200,  E_NORMAL, 20, -100, -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 200,  E_NORMAL, 20, -50,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 200,  E_NORMAL, 20, 0,    -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 200,  E_NORMAL, 20, 50,   -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 200,  E_NORMAL, 20, 100,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 200,  E_NORMAL, 20, 150,  -SCROLL_SPEED * 4, 0},
        {w4 + 0 + 200,  E_NORMAL, 20, 200,  -SCROLL_SPEED * 4, 0},

// should be last enemy + 400
        {w4 + 500,      E_END,    0,  0,    0,                 0},
};

Level* levels = ilevels;
