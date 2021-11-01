#include <stdio.h>
#include <stdlib.h> // Contiene la definición de malloc
// Estatica
int w = 0;

int main() {

  printf("##############################\n");
  printf("### Direcciones de memoria ###\n");
  printf("##############################\n\n");

  int x; // stack
  char y = 'a';  // stack

  // heap
  int *z = (int *)malloc(sizeof(int));
  printf("Dirección de memoria de x: %p\n", &x);
  printf("Dirección de memoria de y: %p\n", &y);
  printf("Dirección de memoria de z: %p\n", z);
  printf("Dirección de memoria de *z: %p\n", &z);
  printf("Dirección de memoria de w: %p\n", &w);

  free(z);
  return 1;
}
