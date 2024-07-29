#ifndef DUPGUARD  //antiduplicado

#define DUPGUARD

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#define WIDTH 1280
#define HEIGHT 720
#define down 1
#define up 1<<1
#define left 1<<2
#define right 1<<3
#define randDir rand()%3-1


typedef struct{
  SDL_Rect coords;
  int dx;
  int dy;
  int mass;
  char block;
} prt;

int validador(int argc, char *argv[]); //Devuelve el tipo de archivo

int validarx(int a); //Transforma números del 1 al 9 en direcciones en el eje x

int validary(int a); //Transforma números del 1 al 9 en direcciones en el eje y

int countBIN(FILE *archivo); //Cuenta la candidad de particulas en BIN

int countCSV(FILE *archivo); //Cuenta la candidad de particulas en CSV

int countTXT(FILE *archivo); //Cuenta la candidad de particulas en TXT

int countPRT(FILE *archivo,int tipo); //Funcion que redirecciona a un contador segun el tipo de archivo

void updateScreen(prt *particles, SDL_Rect *gamecoords,int quantity, SDL_Rect *points, int c_points, int gamemode,SDL_Renderer *ren, SDL_Texture *backTexture, SDL_Rect back_pos, SDL_Rect *mouseRect);
//actualiza la pantalla

int render(prt *particles , SDL_Rect *gamecoords, int quantity, SDL_Rect *points); //contiene la todo los datos para renderizar

int rectIntersection(prt* rect1,prt* rect2); //revisa intersecciones de rectangulos

void sidetouch(prt* prt1, prt* prt2); //guarda el lado donde chocan dos particulas en prt1

void blockedpath(prt* prt1, prt* prt2); //guarda las rutas bloqueadas por particulas en prt2

int collisions(prt *particles, int quantity, SDL_Rect mouseRect, SDL_Rect *points, int c_points, int gamemode, Mix_Chunk *hit); //contiene toda la logica de colisiones y actualiza la posicion de las particulas

void SaveState(prt *particles, int quantity, int saves); // guarda las ubicaciones de las particulas y sus direcciones en un archivo binario
#endif
