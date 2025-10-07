#include <stdio.h>
#include <stdlib.h>

// Uso: ./programa <numero> <desplazamiento>
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Uso: %s <numero> <desplazamiento>\n", argv[0]);
    return 1;
  }

  int num = atoi(argv[1]);
  int desplazamiento = atoi(argv[2]);

  int des_izq = num << desplazamiento;
  int des_der = num >> desplazamiento;

  printf("Resultado de desplazamiento a la izquierda: %d\n", des_izq);
  printf("Resultado de desplazamiento a la derecha: %d\n", des_der);

  return 0;
}