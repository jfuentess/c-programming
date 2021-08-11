#include "utils.h"
#include "map.h"
#include "player.h"
#include "graphics.h"
#include "bomb.h"
#include "powerups.h"
#include "audio.h"
#include "enemies.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// variables globales para ser usadas en otros archivos.
TTF_Font *font = NULL;
SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL;
struct map map = {19, 19};
struct player player;
int running = 1, game = 0, turns = 500;

static int  options = 0;

void options_menu();
void run_game();

void mainloop() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    play_audio(BGM);

    int selection = 0;
    
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = 0;
            if (event.type == SDL_KEYDOWN)
                switch (event.key.keysym.sym) {
                    case SDLK_DOWN:
                        if (selection < 2)
                            selection++;
                        break;
                    case SDLK_UP:
                        if (selection > 0)
                            selection--;
                        break;
                    case SDLK_RETURN:
                    case SDLK_z:
                        switch (selection) {
                            case 0: game = 1; break;
                            case 1: options = 1; break;
                            case 2: running = 0; break;
                        }
                        break;
                }
        }
        
        SDL_RenderClear(renderer);

        print_text("BOMBERMAN", (SDL_Rect) {100, 100}, 6, (SDL_Color) {32, 255, 255, 255});
        print_text("Start Game", (SDL_Rect) {300, 332}, 2, (SDL_Color) {255, 255*(selection!=0), 255*(selection!=0), 255});
        print_text("Options", (SDL_Rect) {300, 364}, 2, (SDL_Color) {255, 255*(selection!=1), 255*(selection!=1), 255});
        print_text("Exit", (SDL_Rect) {300, 396}, 2, (SDL_Color) {255, 255*(selection!=2), 255*(selection!=2), 255});

        SDL_RenderPresent(renderer);

        if (options)
            options_menu();

        if (game)
            run_game();
    }
}

void options_menu() {
    int selection = 3;

    while (options) {
        int inc = 0;
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT){
                options = 0;
                running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_DOWN:
                        if (selection < 3)
                            selection++;
                        break;
                    case SDLK_UP:
                        if (selection > 0)
                            selection--;
                        break;
                    case SDLK_RIGHT:
                        inc = 1;
                        break;
                    case SDLK_LEFT:
                        inc = -1;
                        break;
                    case SDLK_z:
                    case SDLK_RETURN:
                        if (selection == 3)
                            options = 0;
                        break;
                    case SDLK_x:
                    case SDLK_ESCAPE:
                        options = 0;
                        break;
                }
            }
        }

        if (inc) {
            switch (selection) {
                case 0:
                    if (map.w > 5 || inc > 0)
                        map.w += inc * 2;
                    break;
                case 1:
                    if (map.h > 5 || inc > 0)
                        map.h += inc * 2;
                    break;
                case 2:
                    if (turns > 1 || inc > 0)
                        turns += inc;
                    break;
                
            }
            inc = 0;
        }

        SDL_RenderClear(renderer);

        char *str = (char*) malloc(10*sizeof(char));

        print_text("Map width = ", (SDL_Rect) {200, 100}, 3, (SDL_Color) 
                  {255,255*(selection !=0),255*(selection!=0),255});
        sprintf(str, "%d", map.w);
        print_text(str, (SDL_Rect) {550, 100}, 3, (SDL_Color) 
                  {255,255*(selection !=0),255*(selection!=0),255});

        print_text("Map height = ", (SDL_Rect) {200, 200}, 3, (SDL_Color) 
                  {255,255*(selection !=1),255*(selection!=1),255}); 
        sprintf(str, "%d", map.h);
        print_text(str, (SDL_Rect) {550, 200}, 3, (SDL_Color) 
                  {255,255*(selection !=1),255*(selection!=1),255});
        
        print_text("Player turns = ", (SDL_Rect) {200, 300}, 3, (SDL_Color) 
                  {255,255*(selection !=2),255*(selection!=2),255});
        sprintf(str, "%d", turns);
        print_text(str, (SDL_Rect) {550, 300}, 3, (SDL_Color) 
                  {255,255*(selection !=2),255*(selection!=2),255});
        
        free(str);

        print_text("Back", (SDL_Rect) {200, 450}, 3, (SDL_Color) 
                  {255,255*(selection !=3),255*(selection!=3),255});

        SDL_RenderPresent(renderer);
    }
}

void run_game() {
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    
    // se inicializan las variables del jugador
    player.texture = load_image("assets/player.png"); // textura del jugador.
    player.x = 1;
    player.y = 1;
    player.bomb_length = 1;
    player.max_bombs = 1;
    player.bomb_list = malloc(sizeof(struct bomb));
    player.bomb_list[0].time = -1;
    player.bomb_list[0].x = 1;
    player.bomb_list[0].y = 1;

    // se crea el mapa
    map.map = create_map(map.h, map.w);
    while (!map_ok(&map, 1)) { // si no hay espacio para la salida se crea de nuevo
        free_map(&map);
        map.map = create_map(map.h, map.w);
    }
    create_exit(&map);
    create_powerups(&map);
    map.enemies = create_enemies();
    map.texture = create_map_texture(&map);

    int c = turns;
    play_audio(IGM);

    while (game) {
        //posicion anterior del jugador usada para deteccion de colisiones
        SDL_Point prev = {player.x, player.y};
        int moved = 0;
        
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT){
                game = 0;
                running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_DOWN:
                        player.y++;
                        moved = 1;
                        break;
                    case SDLK_UP:
                        player.y--;
                        moved = 1;
                        break;
                    case SDLK_RIGHT:
                        player.x++;
                        moved = 1;
                        break;
                    case SDLK_LEFT:
                        player.x--;
                        moved = 1;
                        break;
                    case SDLK_x:
                        moved = 2;
                        break;
                    case SDLK_z: // poner bombas
                        for (int i = 0; i < player.max_bombs; i++) {
                            if (map.map[player.y][player.x] != 'Q' && player.bomb_list[i].time == -1) {
                                player.bomb_list[i].x = player.x;
                                player.bomb_list[i].y = player.y;
                                player.bomb_list[i].time = 5;
                                map.map[player.bomb_list[i].y][player.bomb_list[i].x] = 'Q';
                                update_map_texture(&map);
                                play_audio(BOMB);
                                //moved = 1;
                                break;
                            }
                        }
                        break;
                    case SDLK_ESCAPE:
                        game = 0;
                        break;
                }          
            }
        }

        if (moved) {
            play_audio(MOVE);
            
            if (map.map[player.y][player.x] == '*') {
                play_audio(WIN);
                game = 0;
            }
            // si el jugador se movio a un espacio no valido se devuelve su posicion a la anterior y no se restan turnos.
            if (map.map[player.y][player.x] == '#' || map.map[player.y][player.x] == '%' || map.map[player.y][player.x] == 'P' || (player.x != prev.x && player.y != prev.y) || (map.map[prev.y][prev.x] != 'Q' && map.map[player.y][player.x] == 'Q') || (map.map[prev.y][prev.x] == 'Q' && map.map[player.y][player.x] == 'Q' && (prev.x != player.x || prev.y != player.y))) {
                player.x = prev.x;
                player.y = prev.y;
                c++;
            } else {
                for (int i = 0; i < player.max_bombs; i++) 
                    if (player.bomb_list[i].time > 0)
                        player.bomb_list[i].time--;
                
                for (int i = 0; i < get_pwup_count(&map); i++)
                    if (map.enemies[i].status)
                        move_enemies(&map.enemies[i]);
                
                if (map.map[player.y][player.x] == 'E') {
                    play_audio(LOSE);
                    game = 0;
                }
            }

            if (map.map[player.y][player.x] == 'F') {
                flame_powerup(&player);
                map.map[player.y][player.x] = ' ';
                update_map_texture(&map);
            
            } else if (map.map[player.y][player.x] == 'B') {
                bomb_powerup(&player);
                map.map[player.y][player.x] = ' ';
                update_map_texture(&map);
            }
            clean_map();
            c--;
        }

        for (int i = 0; i < player.max_bombs; i++) {
            if (player.bomb_list[i].time == 0)
                explode_bomb(&player.bomb_list[i]);
        }

        SDL_RenderClear(renderer); // limpiar pantalla

        camera_present(&player, &map); // se renderiza el mapa y el jugador
        //////////////////////////////
        // imprimir turnos restantes
        SDL_Texture *panel = load_image("assets/panel.png");
        SDL_Rect dst_rect = {WINDOW_WIDTH/2-95,3,190,3*12};
        SDL_RenderCopy(renderer, panel, NULL, &dst_rect);
        char *str = (char*) malloc(12*sizeof(char));
        snprintf(str, 12, "TURNS: %d", c);
        print_text(str, (SDL_Rect) {WINDOW_WIDTH/2-85,4}, 2, (SDL_Color) {255,0,0,255});
        free(str);
        SDL_DestroyTexture(panel);
        //////////////////////////////

        SDL_RenderPresent(renderer);

        if (c <= 0) { // si se acaban los turnos termina el juego
            play_audio(LOSE);
            game = 0;
            printf("Se acabaron los turnos\n");
        }
    }

    //liberar memoria y terminar el juego.
    SDL_DestroyTexture(player.texture);
    free(player.bomb_list);
    free_map(&map);
    SDL_DestroyTexture(map.texture);
    SDL_DestroyTexture(player.texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    play_audio(BGM);
}
