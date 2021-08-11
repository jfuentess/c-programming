#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 816
#define WINDOW_HEIGHT 624

void print_text(const char *text, SDL_Rect rect, float scale, SDL_Color color);

SDL_Texture *load_image(const char *name);

#endif
