#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "bit_representation.h"

int main() { 
  printf("###################################\n");
  printf("### Diccionario de 96 elementos ###\n");
  printf("###################################\n\n");

  // Nuestro diccionario estará conformado por 3 enteros. Cada entero utiliza 32
  // bits en su representación, lo que nos da un total de 96 bits para
  // representar los elementos del diccionario
  unsigned int dict[3] = {};

  for(int i=0; i < 3; i++)
    int2bits(dict[i]);

   // Cantidad de elementos a ser ingresados en el diccionario
  int n = 10, v;
 
  for(int i=1; i <= n; i++) {
    printf("\nIngrese la entrada %d: ", i);
    scanf("%d", &v);
    getchar(); // Consumimos el salto de línea (enter)

    // Insertamos v en el diccionario (lo marcamos como presente)

    // Calculamos el elemento del arreglo dict que contendrá la v-ésima entrada 
    int el = v / 32;
    // Dentro de dict[el], nos movemos 'desp' posiciones para ubicar la v-ésima entrada
    int desp = v - el*32;

    // Utilizamos una máscara de bits con un bit igual a 1 en la posición 'desp'
    int mask = 1 << desp;

    // Por medio de una operación OR (|), insertamos el elemento
    dict[el] |= mask;
  }

  // Verificamos el resultado final
  for(int i=0; i < 3; i++)
    int2bits(dict[i]);
  
  return 0;
}
