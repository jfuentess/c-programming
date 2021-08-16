#ifndef ENEMIES_H
#define ENEMIES_H

enum direction {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

struct enemy{
  	int x;
  	int y;
	enum direction dir;
	int status;
};

struct enemy *create_enemies();
void move_enemies(struct enemy *enemy);
struct enemy *get_enemy(int x, int y);

#endif
