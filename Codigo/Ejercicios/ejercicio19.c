/*
 * Pregunta 19
 *
 * La búsqueda binaria es una algoritmo que permite realizar búsquedas rápidas
 * en un arreglo ordenado. Investigue su funcionamiento e implemente una versión
 * recursiva del algoritmo.  
 *
 *  Criterio evaluación:
 *     - Test 1: Búsqueda de un elemento en un arreglo de largo 1
 *
 *     - Test 2: Búsqueda de un elemento en un arreglo de largo par (mayor a 1)
 *
 *     - Test 3: Búsqueda de un elemento en un arreglo de largo impar (mayor a 1)
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 *
 */

#include <stdio.h> 
#include <stdlib.h> 
  
// Esta función busca si el elemento v está presente en el arreglo ordenado arr
int busquedaBinaria(int arr[], int l, int r, int v) {
    if (r >= l) { 
        int m = l + (r - l) / 2; 
	// Preguntamos si el elemento a buscar v se encuentra en la mitad del
// rango arr[l..r]. Si ese es el caso, terminamos
        if (arr[m] == v) 
            return m; 
  
        // Si el elemento a buscar v es menor que el elemento que se encuentra a
        // la mitad, entonces debemos seguir buscando en el subarreglo de la
        // izquierda arr[l, m-1] (De existir, la respuesta estará en ese mitad)
        if (arr[m] > v) 
	  return busquedaBinaria(arr, l, m - 1, v); 
	// En caso contrario, debemos seguir buscando en el subarreglo de la
        // derecha arr[m+1, r]
	else
	  return busquedaBinaria(arr, m + 1, r, v); 
    } 

    // Si no encontramos el elemento v, retornamos -1
    return -1; 
} 
  
int main(void) {

  int n;
  printf("Ingrese el largo del arreglo a generar: ");
  scanf("%d", &n);
  
  // Generamos un arreglo aleatorio ordenado, arr
  int arr[n], val = 0;
  for(int i=0; i < n; i++) {
    val += rand()%10;
    arr[i] = val;
  }

  for(int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  
  int x;
  printf("Ingrese el valor a buscar: ");
  scanf(" %d", &x);
  
  int pos = busquedaBinaria(arr, 0, n - 1, x);

  if(pos == -1)
    printf("El elemento %d no se encuentra en el arreglo\n", x);
  else
    printf("El elemento %d está ubicado en la posición %d\n", x, pos);

  
  return EXIT_SUCCESS;
}
