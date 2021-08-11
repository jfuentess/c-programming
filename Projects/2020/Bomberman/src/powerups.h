#ifndef POWERUPS_H
#define POWERUPS_H

#include "player.h"
#include "map.h"

void create_powerups(struct map *map);
int get_pwup_count(struct map *map);
void flame_powerup(struct player *player);
void bomb_powerup(struct player *player);

#endif
