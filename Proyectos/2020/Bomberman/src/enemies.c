#include "utils.h"
#include "player.h"
#include "map.h"
#include "enemies.h"
#include "powerups.h"
#include "audio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

extern struct map map;
extern struct player player;
extern int game;

// se crea un array en el heap para la lista de enemigos.
// la cantidad de enemigos es la misma que de powerups y crece con el mapa.
struct enemy *create_enemies() {
	int c_enem = get_pwup_count(&map);
	struct enemy *enemies = (struct enemy *) malloc(c_enem * sizeof(struct enemy));
  
	for (int i = 0; i < c_enem; i++) {
		do {
			enemies[i].x = rand()%map.w;
			enemies[i].y = rand()%map.h;
			enemies[i].dir = rand()%4;
			enemies[i].status = 1;
		} while(map.map[enemies[i].y][enemies[i].x] != ' ' || (enemies[i].y == 1 && enemies[i].x == 1) || (enemies[i].y == 1 && enemies[i].x == 2) || (enemies[i].y == 2 && enemies[i].x == 1));
		map.map[enemies[i].y][enemies[i].x] = 'E';
	}

	return enemies;
}

void move_enemies(struct enemy *enemy) {
	SDL_Point next = {enemy->x, enemy->y};
	
    switch (enemy->dir) {
		case UP:
			next.y = enemy->y-1;
        	break;
	    case DOWN:
			next.y = enemy->y+1;
          	break;
		case LEFT:
			next.x = enemy->x-1;
        	break;
		case RIGHT:
			next.x = enemy->x+1;
        	break;
	}
	
	// se intenta encontrar una direccion al azar valida para el siguiente movimiento.
	// en caso contrario se queda quieto.
	int c = 0;
    while(map.map[next.y][next.x] != ' ' && c < 2) {
		enemy->dir = rand()%4;
		next.x = enemy->x;
		next.y = enemy->y;
      	switch (enemy->dir) {
			case UP:
				next.y = enemy->y-1;
				break;
			case DOWN:
				next.y = enemy->y+1;
				break;
			case LEFT:
				next.x = enemy->x-1;
				break;
			case RIGHT:
				next.x = enemy->x+1;
				break;
		}
		c++;
	}

	if (map.map[next.y][next.x] == ' ') { // si la siguiente posicion es un espacio se mueve
		map.map[next.y][next.x] = 'E'; // los enemigos se representan por 'E' en el mapa
		map.map[enemy->y][enemy->x] = ' ';
		enemy->y = next.y;
		enemy->x = next.x;
	}
}

struct enemy *get_enemy(int x, int y) {
	for (int i = 0; i < get_pwup_count(&map); i++)
		if (map.enemies[i].x == x && map.enemies[i].y == y)
			return &map.enemies[i];
	return NULL;
}
