#include "bomb.h"
#include "utils.h"
#include "map.h"
#include "player.h"
#include "graphics.h"
#include "powerups.h"
#include "audio.h"
#include <SDL2/SDL.h>
#include <stdlib.h>

extern struct map map;
extern struct player player;
extern int game;

// retorna 1 si la explosion deberia continuar, 0 en caso contario
int continue_explosion(struct bomb *bomb, int x, int y) {
    // se muestra la salida
    if (x == map.exit.x && y == map.exit.y) {
        map.map[y][x] = '*';
        return 0;
    }
    // se eliminan los enemigos alcanzados por la bomba
    if (map.map[y][x]=='E') {
        struct enemy *enemy = get_enemy(x,y);
        enemy->status = 0;
        map.map[y][x] = 'X';
        return 0;
    }
    // si la bomba alcanza un bloque blando, se destruye.
    if (map.map[y][x] == '%' || map.map[y][x] == 'F' || map.map[y][x] == 'B') {
        map.map[y][x] = 'X';
        return 0;
    }
    if (map.map[y][x] == '#')
        return 0;
    
    // una bomba alcanzada por otra es detonada
    if (map.map[y][x] == 'Q') {
        struct bomb *another_bomb = get_bomb(x,y);
        another_bomb->time = 0;
        return 0;
    }
    
    if (x == player.x && y == player.y) {
        play_audio(LOSE);
        game = 0;
        return 0;
    }

    if(map.map[y][x] == 'P') {
        if (rand()%2) 
            map.map[y][x] = 'F';
        else
            map.map[y][x] = 'B';
        return 0;
    }
    // solo retorna 1 si la posicion esta vacia
    if (map.map[y][x] == ' ') {
        map.map[y][x] = 'X';
        return 1;
    }
    
    return 0;
}

void explode_bomb(struct bomb *bomb) {
    // se revisa la explosion en cada direccion
    for (int i = 1; i <= player.bomb_length; i++) {
        if (!continue_explosion(bomb, bomb->x-i, bomb->y))
            break;
    }

    for (int i = 1; i <= player.bomb_length; i++) {
        if (!continue_explosion(bomb, bomb->x+i, bomb->y))
            break;
    }

    for (int i = 1; i <= player.bomb_length; i++) {
        if (!continue_explosion(bomb, bomb->x, bomb->y-i))
            break;
    }

    for (int i = 1; i <= player.bomb_length; i++) {;
        if (!continue_explosion(bomb, bomb->x, bomb->y+i))
            break;
    }

    if (bomb->x == player.x && bomb->y == player.y) {
        play_audio(LOSE);
        game = 0;
    }   
    
    // se elimina el caracter 'Q' del mapa y se deja el tiempo de la bomba en -1.
    map.map[bomb->y][bomb->x] = 'X';
    play_audio(EXPLOSION);
    bomb->time--;
    update_map_texture(&map);
}

// eliminar todas las explosiones del mapa.
void clean_map() {
    for (int i = 0; i < map.h; i++) {
        for (int j = 0; j < map.w; j++) {
            if (map.map[i][j] == 'X')
                map.map[i][j] = ' ';
        }
    }
    update_map_texture(&map);
}

// retorna un puntero a la bomba en la posicion del mapa especificada.
struct bomb *get_bomb(int x, int y) {
    for (int i = 0; i < player.max_bombs; i++) {
        if (player.bomb_list[i].x == x && player.bomb_list[i].y == y) {
            return player.bomb_list + i;
        }
    }
    return NULL;
}
