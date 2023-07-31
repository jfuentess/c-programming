#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <time.h>


////////////variables menu///////////////////////////

    SDL_Window *window_menu = NULL;
    SDL_Surface *screen_surface_menu=NULL;
    int running_menu = 1;
    SDL_Event event;
    SDL_Surface* fondo = NULL;
    TTF_Font *font ;
    int m_X,m_Y;//mouse
    SDL_Surface *texto1=NULL;
    SDL_Surface *texto2=NULL;
    SDL_Rect destino1 = {170,430}; //posicion de la palabra INICIAR
    SDL_Rect destino2 = {120,470}; //posicion de las INSTRCCUIONES

//////////////////variables juego/////////////////////
    SDL_Window *window = NULL;
    SDL_Surface *screen_surface = NULL; 
    int running = 1;
    SDL_Event evento;
    int mouseX, mouseY;
    enum estado_celula {INACTIVA,ACTIVA};// INACTIVA=0,ACTIVA=1
    int pausa=0;
    int bandera=1;
    int color_celula;
    int ag_P;
    int velocidad = 200;
    int contvacio=0;
    int contaleatorio=0;
    int contnave=0;
    int sumacelvecinos = 0;


/////////////// configuracion renderer/////////

   SDL_Renderer *renderer = NULL;
    
///////////////////musica/////////
   Mix_Music *musica= NULL;
   int flags;
   int initted;
















#endif