#include <stdio.h>

int main() {
  int x = 10;
  int y = 10;
  char c = 'a';

  // Puntero tipo int a la variable x
  int *px = &x;
  // Puntero tipo char a la variable c
  char *pc = &c;
  
  printf("Variable c=%c  tiene la dirección %p en memoria\n", c, pc);
  printf("Variable x=%d tiene la dirección %p en memoria\n", x, px);
  printf("Variable y=%d tiene la dirección %p en memoria\n\n", y, &y);

  printf("El puntero a entero tiene %lu bytes\n", sizeof(int *));
  printf("El puntero a x tiene %lu bytes\n", sizeof(px));
  printf("El puntero a y tiene %lu bytes\n", sizeof(&y));
  printf("El puntero a c tiene %lu bytes\n\n", sizeof(pc));

  printf("El contenido de x puede ser impreso de dos maneras: %d o %d (desreferenciar)\n", x, *px);

  // NOTA: ¿Cómo funciona scanf(&x)?
  
  return 1;
}
