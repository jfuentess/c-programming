#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include "enemies.h"

struct map {
    int w;
    int h;
    char **map;
    SDL_Texture *texture;
    struct enemy *enemies;
    SDL_Point exit;
};

char **create_map(int map_h, int map_w);
int map_ok(struct map *map, unsigned int count);
void create_exit(struct map *map);
void free_map(struct map *map);

#endif
