#include "utils.h"
#include "player.h"
#include "map.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL_image.h>

extern SDL_Renderer *renderer;

static SDL_Surface *hard_block_surface;
static SDL_Surface *soft_block_surface;
static SDL_Surface *bomb_surface;
static SDL_Surface *door_surface;
static SDL_Surface *flame_powerup_surface;
static SDL_Surface *bomb_powerup_surface;
static SDL_Surface *explosion_surface;
static SDL_Surface *enemy_surface;

void camera_present(struct player *player, struct map *map) {
    // el jugador se mantiene en el centro de la pantalla a menos que se llegue a un borde del mapa.
    SDL_Rect player_on_screen = {WINDOW_WIDTH/2,WINDOW_HEIGHT/2, 16*3,16*3};
    SDL_Rect camera = {0,0,17*16,13*16};
    SDL_Rect dest_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    // el tamaño de dest_rect es minimo el de la ventana para evitar deformar la imagen.
    if (map->w < 17) {
        dest_rect.x = 17*16*3 - map->w*16*3;
        dest_rect.w = map->w*16*3;
    }
    if (map->h < 13) {
        dest_rect.y = 13*16*3 - map->h*16*3;
        dest_rect.h = map->h*16*3;
    }

    camera.x = player->x*16 - (float)camera.w/2;
    camera.y = player->y*16 - (float)camera.h/2;

    // desplazar al jugador del centro de la pantalla a la posicion correspondiente
    if (camera.x < 0) {
        player_on_screen.x += 3*camera.x;
        camera.x = 0;
    }
    if (camera.y < 0) {
        player_on_screen.y += 3*camera.y;
        camera.y = 0;
    }
    if (camera.x > map->w*16 - camera.w) {
        player_on_screen.x += 3*(camera.x + camera.w - map->w*16);
        camera.x = map->w*16 - camera.w;
    }
    if (camera.y > map->h*16 - camera.h) {
        player_on_screen.y += 3*(camera.y + camera.h - map->h*16);
        camera.y = map->h*16 - camera.h;
    }

    SDL_RenderCopy(renderer, map->texture, &camera, &dest_rect);
    SDL_RenderCopy(renderer, player->texture, NULL, &player_on_screen);
}

// se crea la textura del mapa recorriendo cada bloque y pegando la textura correcpondiente en una surface que luego es convertida a texture.
SDL_Texture *create_map_texture(struct map *map) {
    SDL_Texture *map_texture;
    SDL_Surface *map_surface;
    
    // crear una surface en blanco del tamaño necesario.
    map_surface = SDL_CreateRGBSurfaceWithFormat(0, map->w*hard_block_surface->w, map->h*hard_block_surface->h, 32, hard_block_surface->format->format);
    
    SDL_Rect dst_rect = {0,0,hard_block_surface->w,hard_block_surface->h};
    
    // se copian las imagenes a map_surface.
    for (int i = 0; i < map->h; i++) {
        dst_rect.y = i*hard_block_surface->h;
        for (int j = 0; j < map->w; j++) {
            dst_rect.x = j*hard_block_surface->w;
            if (map->map[i][j] == '#')
                SDL_BlitSurface(hard_block_surface, NULL, map_surface, &dst_rect);
            else if (map->map[i][j] == '%' || map->map[i][j] == 'P')
                SDL_BlitSurface(soft_block_surface, NULL, map_surface, &dst_rect);
            else if (map->map[i][j] == 'Q')
                SDL_BlitSurface(bomb_surface, NULL, map_surface, &dst_rect);
            else if (map->map[i][j] == 'F')
                SDL_BlitSurface(flame_powerup_surface, NULL, map_surface, &dst_rect);
            else if (map->map[i][j] == 'B')
                SDL_BlitSurface(bomb_powerup_surface, NULL, map_surface, &dst_rect);
            else if (map->map[i][j] == 'E')
                SDL_BlitSurface(enemy_surface, NULL, map_surface, &dst_rect);
            else if (map->map[i][j] == 'X')
                SDL_BlitSurface(explosion_surface, NULL, map_surface, &dst_rect);
            else if (map->map[i][j] == '*')
                SDL_BlitSurface(door_surface, NULL, map_surface, &dst_rect);
        }
    }

    // se convierte la surface a texture y se retorna un puntero a esta.
    map_texture = SDL_CreateTextureFromSurface(renderer, map_surface);
    SDL_FreeSurface(map_surface);
    return map_texture;
}

void update_map_texture(struct map *map) {
    SDL_DestroyTexture(map->texture);
    map->texture = create_map_texture(map);
}

void init_graphics() {
    explosion_surface = IMG_Load("assets/explosion.png");
    flame_powerup_surface = IMG_Load("assets/flame_powerup.png");
    bomb_powerup_surface = IMG_Load("assets/bomb_powerup.png");
    hard_block_surface = IMG_Load("assets/hard_block.png");
    soft_block_surface = IMG_Load("assets/soft_block.png");
    bomb_surface = IMG_Load("assets/bomb.png");
    door_surface = IMG_Load("assets/door.png");
    enemy_surface = IMG_Load("assets/enemy.png");
}

void clean_graphics() {
    SDL_FreeSurface(enemy_surface);
    SDL_FreeSurface(explosion_surface);
    SDL_FreeSurface(bomb_powerup_surface);
    SDL_FreeSurface(flame_powerup_surface);
    SDL_FreeSurface(door_surface);
    SDL_FreeSurface(bomb_surface);
    SDL_FreeSurface(hard_block_surface);
    SDL_FreeSurface(soft_block_surface);
}
