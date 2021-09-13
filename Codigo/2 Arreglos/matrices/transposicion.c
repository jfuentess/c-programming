// Compilación: gcc -o transposicion transposicion.c

#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>
#include <time.h>

int main(int argc, char** argv) {

  printf("#################################\n");
  printf("### Transposición de matrices ###\n");
  printf("#################################\n\n");

  int matriz1[700][700];
  int matriz2[700][700];

  // Llenado matrices
  for(int i = 0; i < 700; ++i) 
    for(int j = 0; j < 700; ++j)
      matriz1[i][j] = i*10 + j;
  
  // Transposición de matrices
  for(int i = 0; i < 700; ++i)
    for(int j = 0; j < 700; ++j)
  	matriz2[j][i] = matriz1[i][j];

  return EXIT_SUCCESS;
}
