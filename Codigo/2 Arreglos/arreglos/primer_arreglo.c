// Un arreglo es una colección finita, homogénea y ordenada de elementos
// En los arreglos unidimensionales se distinguen dos partes fundamentales: los componentes y el índice


// Compilación: gcc -o primer_arreglo primer_arreglo.c

#include <stdlib.h>
#include <stdio.h>

int main() {
  // No podemos asumir ningún valor por defecto para los elementos de un arreglo
  // en C. Si queremos un valor por defecto, debemos asignárselo a través de un
  // recorrido del arreglo.

  // Arreglos de 10 variables enteras
  int arr1[10]; // No hay garantía del valor de cada variable del arreglo
  int arr2[10] = {0}; // Todos los elementos son inicializados en 0
  int arr3[10] = {5};
  int arr4[10] = {5, 7, 10, 56, 0, 45, 7, 12, -1, -10};

  /* printf("1. %d\n", arr4[0]); */
  /* printf("2. %d\n", arr4[1]); */
  /* printf("3. %d\n", arr4[2]); */
  /* printf("4. %d\n", arr4[3]); */
  /* printf("5. %d\n", arr4[4]); */
  /* printf("6. %d\n", arr4[5]); */
  /* printf("7. %d\n", arr4[6]); */
  /* printf("8. %d\n", arr4[7]); */
  /* printf("9. %d\n", arr4[8]); */
  /* printf("10. %d\n", arr4[9]); */
  /* printf("11. %d [[ Error! ]]\n", arr4[10]); */
  
  printf("arr1: ");
  for(int i=0; i < 10; i++)
    printf("%d ", arr1[i]);
  printf("\n");

  return 0;
}
