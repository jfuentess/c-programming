#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <sys/time.h>
#include <time.h>

int main() {
  printf("######################n");
  printf("### Potencias de 2 ###\n");
  printf("######################\n\n");
  
  // Variables especiales para medir tiempo de ejecución
  struct timespec stime, etime;
  double t;

  // Función para medir tiempo de ejecución
  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID , &stime)) {
    fprintf(stderr, "clock_gettime failed");
    exit(-1);
  }

  int x = 1;
  // Número de operaciones a realizar
  int num_ops = 5000000;

  for(int i=1; i<num_ops; i++)
    for(int j=1; j<30; j++) {
      // Potencia de dos usando operadores de bits
      x <<= j;
      // Potencia de dos usando la función pow() de la biblioteca math.h
      //x = pow(2, j);
    }
  
  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID , &etime)) {
    fprintf(stderr, "clock_gettime failed");
    exit(-1);
  }
  
  t = (etime.tv_sec - stime.tv_sec) + (etime.tv_nsec - stime.tv_nsec) / 1000000000.0;
  printf("%f secs\n", t); // tiempo en segundos

  return 0;
}
