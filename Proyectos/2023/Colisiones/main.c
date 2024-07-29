#include "funciones.h"
#include "funciones_de_archivos.c"
#include "funciones_de_renderizado.c"
#include "funciones_de_colisiones.c"

int main(int argc, char *argv[]) {

  int tipo=0;
  int quantity = 0;
  prt *particles;
  if(argc>=2){
    FILE *archivo = fopen(argv[1], "r");
    if (archivo == NULL) {
      return 1;
    }
    
    tipo = validador(argc, argv);
    quantity = countPRT(archivo, tipo);
    fclose(archivo);
    
    archivo = fopen(argv[1], "r");
    if (archivo == NULL) {
      return 1;
    }
    
  particles = (prt *)malloc(quantity*sizeof(prt));
  
  //TXT
  if (tipo == 3) {
    char buffer[1024];
    int array[2 * quantity];
    int aux = 0;
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
      char *inicio = strchr(buffer, '(');
      char *fin = strchr(buffer, ')');
      while (inicio != NULL && fin != NULL) {
	inicio++;
	char subcadena[256];
	strncpy(subcadena, inicio, fin - inicio);
	subcadena[fin - inicio] = '\0';
	char *token = strtok(subcadena, ",");
	while (token != NULL) {
	  array[aux++] = atoi(token);
	  token = strtok(NULL, ",");
	}
	inicio = strchr(fin + 1, '(');
	fin = strchr(fin + 1, ')');
      }
    }
    
    for (int i = 0; i < quantity; i++) {
      particles[i].coords.x=array[i * 2];
      particles[i].coords.y=array[i * 2 + 1];
      particles[i].coords.w = 10;
      particles[i].coords.h = 10;
      particles[i].dx=(rand()%3-1);
      particles[i].dy=(rand()%3-1);
      particles[i].mass=rand()%100+1;
      particles[i].block=0;
    }
  }
  
  //CSV
  if (tipo == 2) {
    char buffer[1000];
    int array[3 * quantity];
    int aux = 0;
    
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
      char *token = strtok(buffer, ",");
      while (token != NULL) {
	array[aux++] = atoi(token);
	token = strtok(NULL, ",");
      }
    }
    for (int i = 0; i < quantity; i++) {
      particles[i].coords.x=array[i * 3];
      particles[i].coords.y=array[i * 3 + 1];
      particles[i].coords.w = 10;
      particles[i].coords.h = 10;
      particles[i].dx=validarx(array[i * 3 + 2]);
      particles[i].dy=validary(array[i * 3 + 2]);
      particles[i].mass=rand()%100+1;
      particles[i].block=0;
    }
  }
  
  //BIN
  if (tipo == 1) {
    int array[3 * quantity];
    size_t lector = fread(array, sizeof(int), 3 * quantity, archivo);
    if (lector == 0) {
      fclose(archivo);
      free(particles);
      return 1;
    }
    for (int i = 0; i < quantity; i++) {
      particles[i].coords.x=array[i * 3];
      particles[i].coords.y=array[i * 3 + 1];
      particles[i].coords.w = 10;
      particles[i].coords.h = 10;
      particles[i].dx=validarx(array[i * 3 + 2]);
      particles[i].dy=validary(array[i * 3 + 2]);
      particles[i].mass=rand()%100+1;
      particles[i].block=0;
    }
  }
  
  fclose(archivo);
  }else{
    quantity=100;
    particles = (prt *)malloc(quantity*sizeof(prt));
    for(int i=0;i<quantity;i++){
      particles[i].coords.x=rand()%WIDTH;
      particles[i].coords.y=rand()%HEIGHT;
      particles[i].coords.w = 10;
      particles[i].coords.h = 10;
      particles[i].dx=(rand()%3-1);
      particles[i].dy=(rand()%3-1);
      particles[i].mass=rand()%100+1;
      particles[i].block=0;
    }
  }

  SDL_Rect* gamecoords = (SDL_Rect *)malloc(quantity*sizeof(SDL_Rect));
  SDL_Rect* points = (SDL_Rect *)malloc(sizeof(SDL_Rect));
  for(int i=0;i<quantity;i++){
    gamecoords[i].x=rand()%WIDTH;
    gamecoords[i].y=rand()%HEIGHT;
    gamecoords[i].w = 5;
    gamecoords[i].h = 5;
  }
  render(particles , gamecoords, quantity, points);
  
}
