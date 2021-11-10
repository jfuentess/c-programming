#include "utils.h"

// Llena un arreglo con valores entre [a,b)
void fill_array(int *arr, int n, int a, int b) {
  // Largo del rango [a,b)
  int l = b - a + 1;
  for(int i=0; i < n; i++)
    arr[i] = a + rand() % l;
}

// Imprime un arreglo de enteros
void print_array(int *arr, int n) {
  // Opción 1
  for(int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  /* // Opción 2
  for(int i=0; i < n; i++)
    printf("%d ", *(arr+i));
  printf("\n");
  */
}

// Retorna la posición del mínimo elemento entre las posiciones a y b-1 del
// arreglo arr
int min_pos_range(int *arr, int a, int b) {
  if(a > b)
    return -1;
  
  int min_pos = a;
  for(int i=a+1; i < b; i++)
    if(arr[i] < arr[min_pos])
      min_pos = i;

  return min_pos;
}

// Retorna la posición del mínimo elemento de un arreglo
int min_pos(int *arr, int n) {
  return min_pos_range(arr, 0, n);
}

// Retorna el mínimo elemento de un arreglo
int min_el(int *arr, int n) {
  int mp = min_pos(arr, n);
  return arr[mp];
}

// Intercambia el contenido de las variables pasadas por parámetro
void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}
