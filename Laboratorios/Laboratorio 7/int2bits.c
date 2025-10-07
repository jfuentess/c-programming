#include <stdio.h>
#include "bit_representation.h"

int main() {
  int numero;
  printf("Introduce un número entero: ");
  scanf("%d", &numero);
  int2bits(numero);
  return 0;
}