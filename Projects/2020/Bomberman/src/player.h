#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

struct player {
    int x;
    int y;
    SDL_Texture *texture;
    struct bomb *bomb_list;
    int bomb_length;
    int max_bombs;
};

#endif
