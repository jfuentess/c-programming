#include <stdlib.h>
#include <stdio.h>

void estadisticas(int n, int x[n], int *m, int *M, float *p) {
  int min = x[0], max = x[0];
  int prom = x[0];
  for(int i=1; i < n; i++) {
    prom += x[i];
    if(x[i] < min)
      min = x[i];
    else if(x[i] > max)
      max = x[i];
  }
  
  *m = min;
  *M = max;
  *p = (float)prom / n;
}

int main() {
  int n;
  printf("Ingrese el largo del arreglo: ");
  scanf("%d", &n);

  int x[n];
  
  for(int i=0; i < n; i++)
    x[i] = rand() % 100;

  for(int i=0; i < n; i++)
    printf("%d ", x[i]);
  printf("\n");

  int mi=0, ma=0;
  float pr = 0;

  estadisticas(n, x, &mi, &ma, &pr);

  printf("Valor mínimo: %d\n", mi);
  printf("Valor máximo: %d\n", ma);
  printf("Valor promedio: %.2f\n", pr);
  
  return EXIT_SUCCESS;  
}
