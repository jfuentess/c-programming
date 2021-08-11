#include "utils.h"
#include <time.h>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

extern TTF_Font *font;
extern SDL_Renderer *renderer;
extern SDL_Window *window;

void print_text(const char *text, SDL_Rect rect, float scale, SDL_Color color) {
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect.w = surface->w * scale;
    rect.h = surface->h * scale;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

// retorna putero a textura a partir de una surface
SDL_Texture *load_image(const char *name) {
    SDL_Surface *image_surface = IMG_Load(name);
    SDL_Texture *image_texture = SDL_CreateTextureFromSurface(renderer, image_surface);
    SDL_FreeSurface(image_surface);
    return image_texture;
}

void init_graphics();
void init_audio();
void clean_graphics();
void clean_audio();

// inicializacion de SDL2
int init() {
    srand(time(NULL)); // se cambia la semilla.

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        printf("Error al iniciar SDL\n");
        return EXIT_FAILURE;
    }

    if (TTF_Init() != 0) {
        printf("Error al iniciar SDL_ttf\n");
        return EXIT_FAILURE;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Error al iniciar SDL_image\n");
        return EXIT_FAILURE;
    }
    
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096)==-1){
        fprintf(stderr, "Error al iniciar audio %s",Mix_GetError());
        exit(1);
    }
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
    

    font = TTF_OpenFont("assets/font.ttf", 16);
    if (!font)
        printf("Error al abrir font\n");

    window = SDL_CreateWindow("BOMBERMAN", 
                              SDL_WINDOWPOS_CENTERED, 
                              SDL_WINDOWPOS_CENTERED, 
                              WINDOW_WIDTH, 
                              WINDOW_HEIGHT, 
                              0);
    if (!window) {
        printf("Error al crear la ventana\n");
        SDL_Quit();
        return EXIT_FAILURE;
    }
    SDL_Surface *icon = IMG_Load("assets/bomb.png");
    SDL_SetWindowIcon(window, icon);
    SDL_FreeSurface(icon);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("Error al crear el renderer\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    init_graphics();
    init_audio();

    return 0;
}

void cleanup() {
    clean_audio();
    clean_graphics();
    Mix_Quit();
    IMG_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_CloseAudio();
    SDL_Quit();
}
