#include <stdlib.h>
#include <stdio.h>

int main() {

  printf("#########################################################\n");
  printf("### Ordenamiento usando detección del mínimo elemento ###\n");
  printf("#########################################################\n\n");

  int n;
  printf("\tIngrese el largo del arreglo: ");
  scanf("%d", &n);

  int arr[n];

  // Inicializaremos el arreglo con valores al azar en el rango [0,99]
  for(int i=0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  printf("Arreglo desordenado: ");
  for(int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  for(int k = 0; k < n; k++) {
    int pmin = k; // Guarda la posición del elemento menor
    for(int i=k+1; i < n; i++) {
      if(arr[i] < arr[pmin])
	pmin = i;
    }

    int t = arr[k];
    arr[k] = arr[pmin];
    arr[pmin] = t;
  }
  
  printf("Arreglo ordenado: ");
  for(int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
