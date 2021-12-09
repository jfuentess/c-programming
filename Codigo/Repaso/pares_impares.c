#include <stdio.h> 
#include <stdlib.h> 

int main(void) {

  int n;
  printf("Ingrese el largo del arreglo: ");
  scanf("%d", &n);

  int x[n];
  for(int i=0; i < n; i++)
    x[i] = rand() % 100;

  for(int i=0; i < n; i++)
    printf("%d ", x[i]);
  printf("\n");

  /*
    Escriba un programa que, dado un arreglo de enteros x de largo n, genere dos
    arreglos x1 y x2, donde x1 contiene todos los valores pares del arreglo x y
    x2 contiene todos los valores impares.
   */
    
  return EXIT_SUCCESS;
}
