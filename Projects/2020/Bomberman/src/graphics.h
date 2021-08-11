#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "map.h"
#include "player.h"
#include <SDL2/SDL.h>

void camera_present(struct player *player, struct map *map);

SDL_Texture *create_map_texture(struct map *map);

void update_map_texture(struct map *map);

#endif
