// Compilación: gcc -o mult_matrices mult_matrices.c

#include <stdlib.h>
#include <stdio.h>

// Bibliotecas que contienen funciones y variables dedicadas
// a medir tiempo
#include <sys/time.h>
#include <time.h>

int main(int argc, char** argv) {

  printf("##################################\n");
  printf("### Multiplicación de matrices ###\n");
  printf("##################################\n\n");

  int matriz1[700][700];
  int matriz2[700][700];
  int matriz3[700][700];

  // Llenado matrices
  for(int i = 0; i < 700; ++i)  // Filas
    for(int j = 0; j < 700; ++j) { // Columnas
      matriz1[i][j] = i*10 + j;
      matriz2[i][j] = i + j;
    }
  
  
  // Variables especiales para medir tiempo de ejecución
  struct timespec stime, etime;
  double t;

  // Función para medir tiempo de ejecución
  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID , &stime)) {
    fprintf(stderr, "clock_gettime failed");
    exit(-1);
  }

  // Multiplicación clásica: Filas de la matriz 1 por columnas de la matriz 2
  for(int i = 0; i < 700; ++i)
    for(int j = 0; j < 700; ++j)
      for(int k = 0; k < 700; ++k) // Elementos dentro de las filas/columnas
  	matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
	
  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID , &etime)) {
    fprintf(stderr, "clock_gettime failed");
    exit(-1);
  }
  
  t = (etime.tv_sec - stime.tv_sec) + (etime.tv_nsec - stime.tv_nsec) / 1000000000.0;
  printf("%f secs\n", t); // tiempo en segundos

  return EXIT_SUCCESS;
}
