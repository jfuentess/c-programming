// Compilación: gcc -o inicializacion inicializacion_arreglo.c 

#include <stdlib.h>
#include <stdio.h>

int main() {

  int n; // Guarda la cantidad de elementos
  /* Comandos para colores
   - \e[0m -> Texto normal
   - \e[96m -> Color Light cyan
   - \e[1m -> negritas

   Más información en: https://misc.flogisoft.com/bash/tip_colors_and_formatting
  */
  printf("\e[96m#########################################\n\e[0m");
  printf("\e[96m### \e[0m\e[1mCreación de un arreglo de enteros\e[0m \e[96m###\e[0m\n");
  printf("\e[96m#########################################\n\n\e[0m");

  printf("\tIngrese el largo del arreglo: ");
  scanf("%d", &n);

  int arr[n];

  for(int i=0; i < n; i=i+1) {
    int val;
    printf("\t Ingrese arr[%d]: ", i);
    scanf(" %d", &val);
    arr[i] = val;
  }

  printf("Arreglo ingresado:\n\t");
  for(int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  printf("Arreglo ingresado (order inverso):\n\t");
  for(int i=n-1; i >= 0; i--)
    printf("%d ", arr[i]);
  printf("\n");

  printf("Arreglo ingresado (recorrido más allá de los límites):\n\t");
  for(int i=0; i < 2*n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
