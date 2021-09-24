#include <stdio.h>
#include <stdlib.h>

/*
 * Problema: Detectar ciclos de una permutación. Cada permutación puede ser
 * vista como una colección de ciclos. En este problema se pide detectar los
 * ciclos de la permutación 0, 6, 3, 10, 5, 11, 2, 9, 7, 4, 1, 8.
 */
int main(int argc, char **argv) {

  printf("##########################################\n");
  printf("### Detectar ciclos en una permutación ###\n");
  printf("##########################################\n\n");
  
  int permutacion[12] = {0, 6, 3, 10, 5, 11, 2, 9, 7, 4, 1, 8};

  char marcas[12] = {}; // Inicializado todo a 0

  for(int i=0; i < 12; i++) {
    // Posición a partir de la cual comenzamos a recorrer el ciclo
    int ind = i;

    // Recorremos el ciclo sólo si no ha sido recorrido previamente
    while(marcas[ind] == 0) {
      printf("%d ", ind);
      marcas[ind] = 1; // Marcamos como visitada
      ind = permutacion[ind];
    }
    printf("\n");
  }

  return 0;
}
