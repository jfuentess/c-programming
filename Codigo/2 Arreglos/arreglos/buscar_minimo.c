// Compilación: gcc -o minimo buscar_minimo.c

#include <stdlib.h>
#include <stdio.h>

int main() {

  int n;
  printf("##########################################\n");
  printf("### Búsqueda de mínimo/máximo elemento ###\n");
  printf("##########################################\n\n");

  printf("\tIngrese el largo del arreglo: ");
  scanf("%d", &n);

  int arr[n];

  // Inicializaremos el arreglo con valores al azar en el rango [0,99]
  for(int i=0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  for(int i=0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");


  // Búsqueda del menor elemento
  int min = arr[0]; // Guarda el elemento menor
  for(int i=1; i < n; i++) {
    if(arr[i] < min)
      min = arr[i];
  }

  printf("min: %d\n", min);
  
  return 0;
}
