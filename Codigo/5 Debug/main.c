#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>
#include <time.h>

#include "sum_power2.h"

#define N 1000000

int main() {
  printf("#########################\n");
  printf("### Suma de cuadrados ###\n");
  printf("#########################\n\n");
  
  // Variables especiales para medir tiempo de ejecución
  struct timespec stime, etime;
  double t;

  // Declaramos un arreglo de N enteros
  int numbers[N];

  // Llenamos el arreglo con N valores seleccionados al azar en el rango [0,9]
  for(int i=0; i < N; i++)
    numbers[i] = rand() % 10;

  // Función para medir tiempo de ejecución
  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID , &stime)) {
    fprintf(stderr, "clock_gettime failed");
    exit(-1);
  }

  unsigned long total = sum_power2(numbers, N);

  printf("La suma de cuadrados es %lu\n", total);
  if (clock_gettime(CLOCK_THREAD_CPUTIME_ID , &etime)) {
    fprintf(stderr, "clock_gettime failed");
    exit(-1);
  }
  
  t = (etime.tv_sec - stime.tv_sec) + (etime.tv_nsec - stime.tv_nsec) / 1000000000.0;
  printf("Tiempo de cómputo: %f secs\n", t); // tiempo en segundos

  return 0;
}
