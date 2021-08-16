#ifndef BOMB_H
#define BOMB_H

struct bomb {
    int x;
    int y;
    int time;
};

void explode_bomb(struct bomb *bomb);

void clean_map();

struct bomb *get_bomb(int x, int y);

#endif
