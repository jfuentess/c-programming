#include <stdio.h>
#include <stdlib.h>

void main() {

  char a = 2;
  unsigned char b = 2;
  char c = -2;
  unsigned char d = -2;

  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);
  printf("d: %d\n\n", d);

  printf("que imprime?: %d\n\n", 1+3);
  printf("que imprime?: %d\n\n", '1'+3);
  printf("que imprime?: %d\n\n", '1'+'3');
  printf("que imprime?: %c\n\n", 'A'+32);
  printf("que imprime?: %c\n\n", 'h'-32);
  
  // Nota: Averiguar sobre "notación complemento 2" para valores negativos
  
  return;
}


