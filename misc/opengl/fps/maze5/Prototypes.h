#ifndef PROTOTYPES_H
#define PROTOTYPES_H

void display();
void init();
void keyboard(unsigned char, int, int);
void specialkeyboard(int, int, int);

// Gun
void draw_pieces();
void draw_hands();
void draw_magazine();
void draw_gunbarrel();
void draw_sight();
void draw_gun();

// Robot
void place_robots();
void move_robots();
void draw_robots();

// Bullet
void draw_bullet();
void trig_functions(float);
void bullet_hits_robots();

// Mouse
void mouse(int button, int state, int x, int y);

#endif
