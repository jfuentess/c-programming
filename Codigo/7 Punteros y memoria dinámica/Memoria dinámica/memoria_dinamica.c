#include <stdio.h>
#include <stdlib.h> // Contiene la definición de malloc

int main() {

  printf("###################################################\n");
  printf("### Reserva de memoria para un arreglo (malloc) ###\n");
  printf("###################################################\n\n");

  int n = 0;
  printf("Ingrese el largo del arreglo a declarar: ");
  scanf("%d", &n);

  // Reservamos memoria dinámica para un arreglo de n enteros
  int *arr = malloc(n*sizeof(int));
  if(arr == NULL) {    
    exit(1);
  }

  // Por medio de la suma, verificamos los valores que tienen por defecto las
  // distntas entradas del arreglo
  int sum = 0;
  for(int i=0; i < n; i++)
    sum += arr[i];

  printf("Se reservó memoria para un arreglo de %d enteros (%ld bytes)\n", n, n*sizeof(int));
  printf("La suma de sus elementos es %d\n", sum);
  
  // Liberamos la memoria reservada
  free(arr);

  // Una vez que liberamos la memoria, podemos reutilizar el puntero arr para
  // reservar memoria nuevamente
  arr = malloc(10*sizeof(int));
  
  // Nota: ¿Qué es heap overflow?
  return 1;
}
