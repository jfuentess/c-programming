#include <stdio.h>
#include <stdlib.h>

int *crearArreglo(int *n);
void llenarArreglo(int *array, int n);
void imprimirArreglo(int *array, int n);

int main() {
  int *miArreglo;
  int n;

  // Crear un arreglo dinámico
  miArreglo = crearArreglo(&n);

  // Llenar el arreglo con valores ingresados por el usuario
  llenarArreglo(miArreglo, n);

  // Imprimir el arreglo
  imprimirArreglo(miArreglo, n);

  // Liberar la memoria al final del programa
  free(miArreglo);

  return 0;
}

int *crearArreglo(int *n) {
  printf("Ingrese la cantidad de elementos: ");
  scanf("%d", n);

  if (*n <= 0) {
    printf("Error: El tamaño debe ser mayor a 0\n");
    return NULL;
  }

  int *arreglo = (int *)malloc(*n * sizeof(int));

  return arreglo;
}

void llenarArreglo(int *array, int n) {
  printf("Ingrese %d números:\n", n);

  for (int i = 0; i < n; i++) {
    printf("Elemento %d: ", i + 1);
    scanf("%d", &array[i]);
  }
}

void imprimirArreglo(int *array, int n) {
  printf("\nElementos del arreglo:\n");

  for (int i = 0; i < n; i++) {
    printf("array[%d] = %d\n", i, array[i]);
  }
}
