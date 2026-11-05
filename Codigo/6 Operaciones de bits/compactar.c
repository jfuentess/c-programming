#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "bit_representation.h"

int main() {

  printf("##################################\n");
  printf("### Compactar números pequeños ###\n");
  printf("##################################\n\n");

  int x;
  int n = 8; // Número de elementos
  int arr[n];
  int max;

  // Generación de elementos pequeños al azar. Los elementos pertenecen al rango
  // [0,15]
  for(int i=0; i < n; i++)
    arr[i] = rand() % 16;

  // Encontrar el elemento mayor
  max = arr[0];
  for(int i=1; i < n; i++)
    if(max < arr[i])
      max = arr[i];

  // Cantidad mínima de bits para representar todos los elementos
  int n_bits = (int)ceil(log2(max+1));
  printf("Se necesitan %d bits para representar todos los elementos\n", n_bits);

  // Usaremos los 32 bits de esta variable para almacenar 8 enteros entre 0 y 15
  unsigned int compacto = 0;

  for(int i=0, d=0; i < n; i++, d+=n_bits) {
    compacto = compacto | (arr[i] << d);
  }

  for(int i=0; i < n; i++)
    int2bits(arr[i]);

  printf("\n*** Compacto ***\n");
  int2bits(compacto);
  
  return 0;
}
