#include "powerups.h"
#include "graphics.h"
#include "bomb.h"
#include "audio.h"
#include <stdlib.h> 
#include <SDL2/SDL.h>

void create_powerups(struct map *map) {
    // se verifica que haya espacio para los powerups y la salida.
    int pwup_count = get_pwup_count(map);
    while (!map_ok(map, pwup_count+1)) {
		free_map(map);
	    map->map = create_map(map->h, map->w);
        create_exit(map);
	}

    // se crean los powerups en posiciones al azar del mapa.
    SDL_Point pos;
    for (int i = 0; i < pwup_count; i++) {
        do {
            pos.x = rand() % map->w;
            pos.y = rand() % map->h;
        } while(map->map[pos.y][pos.x] != '%' || (pos.x == map->exit.x && pos.y == map->exit.y));
        // el caracter 'P' en el mapa indica que hay un powerup pero se ve igual que un bloque destructible.
        map->map[pos.y][pos.x] = 'P';
    }
}

void flame_powerup(struct player *player) {
	player->bomb_length++;
    play_audio(PW_FLAME);
}

void bomb_powerup(struct player *player) {
	player->max_bombs++;
	do {
		player->bomb_list = (struct bomb *) realloc(player->bomb_list, player->max_bombs * sizeof(struct bomb));
	} while (player->bomb_list == NULL);
    player->bomb_list[player->max_bombs-1].time = -1;
    player->bomb_list[player->max_bombs-1].x = 1;
    player->bomb_list[player->max_bombs-1].y = 1;
    play_audio(PW_BOMB);
}

int get_pwup_count(struct map *map) {
    return (int) ((map->w*map->h)*0.01); // area del mapa / 100
}
