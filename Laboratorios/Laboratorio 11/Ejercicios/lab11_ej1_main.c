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
