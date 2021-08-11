#include "map.h"

char **create_map(int map_h, int map_w) {
    // se reserva la memoria en el heap para un arreglo 2d.
    char **map = (char**) malloc(map_h * sizeof(char*));
    for (int i = 0; i < map_h; i++) {
        *(map + i) = (char*) malloc(map_w * sizeof(char));
    }

    // se inicializa el arreglo con el caracter ' '.
    for (int i = 0; i < map_h; i++)
        for (int j = 0; j < map_w; j++)
            map[i][j] = ' ';
    
    // se llena la primera fila con el caracter '#' (bloque indestructible).
    for (int i = 0; i < map_w; i++)
        map[0][i] = '#';

    // lo mismo para la ultima fila.
    for (int i = 0; i < map_w; i++)
        map[map_h-1][i] = '#';
    
    // se crea el patron de bloques solidos del mapa
    for (int i = 1; i < map_h - 1; i++)
        for (int j = 0; j < map_w; j++) {
            if (i%2 == 1) {
                map[i][0] = '#';
                map[i][map_w-1] = '#';
                break;
            } else
                if (j%2 == 0)
                    map[i][j] = '#';
        }
    
    // se llena al azar con bloques blandos '%'.
    for (int i = 1; i < map_h - 1; i++)
        for (int j = 1; j < map_w - 1; j++)
            // si el espacio esta vacio y rand() es divisible por 3, se cambia por un bloqe blando.
            if (map[i][j] == ' ' && !(rand()%3))
                map[i][j] = '%';
    
    // esto es para asegurarse que la esquina donde aparece el jugador este vacia.
    map[1][1] = ' ';
    map[1][2] = ' ';
    map[2][1] = ' ';

    return map;
}

// retorna 1 si hay al menos "count" bloques destructibles
int map_ok(struct map *map, unsigned int count) {
    int c = 0;
    for (int i = 0; i < map->w; i++)
        for (int j = 0; j < map->h; j++)
            if (map->map[j][i] == '%') {
                c++;
                if (c >= count)
                    return 1;
            }
    
    return 0;
}

void free_map(struct map *map) {
	for (int i = 0; i < map->h; i++)
		free(*(map->map + i));
	free(map->map);
}

void create_exit(struct map *map) {
    do {
        map->exit.x = rand()%map->w;
        map->exit.y = rand()%map->h;
    } while (map->map[map->exit.y][map->exit.x] != '%');
}
