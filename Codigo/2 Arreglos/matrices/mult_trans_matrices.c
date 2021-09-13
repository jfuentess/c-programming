// Compilación: gcc -o mult_trans_matrices mult_trans_matrices.c

#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>
#include <time.h>

int main(int argc, char** argv) {

  printf("##################################\n");
  printf("### Multiplicación de matrices ###\n");
  printf("##################################\n\n");

  int matriz1[700][700];
  int matriz2[700][700];
  int matriz3[700][700];
  int trans[700][700];

  // Llenado matrices
  for(int i = 0; i < 700; ++i) 
    for(int j = 0; j < 700; ++j) {
      matriz1[i][j] = i*10 + j;
      matriz2[i][j] = i + j;
    }
  
  struct timespec stime, etime;
  double t;

  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID , &stime)) {
    fprintf(stderr, "clock_gettime failed");
    exit(-1);
  }

  // Transposición de matrices
  for(int i = 0; i < 700; ++i)
    for(int j = 0; j < 700; ++j)
  	trans[i][j] = matriz2[j][i];
  
  
  // Multiplicación de matrices
  // Ahora multiplicamos fila de la matriz 1 por fila de la matriz 2
  for(int i = 0; i < 700; ++i)
    for(int j = 0; j < 700; ++j)
      for(int k = 0; k < 700; ++k)
  	matriz3[i][j] += matriz1[i][k] * trans[j][k];

  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID , &etime)) {
    fprintf(stderr, "clock_gettime failed");
    exit(-1);
  }
  
  t = (etime.tv_sec - stime.tv_sec) + (etime.tv_nsec - stime.tv_nsec) / 1000000000.0;
  printf("%f secs\n", t); // tiempo en segundos

  return EXIT_SUCCESS;
}
