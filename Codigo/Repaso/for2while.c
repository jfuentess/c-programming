#include <stdio.h> 
#include <stdlib.h> 
  

// Esta función busca si el elemento v está presente en el arreglo ordenado arr
// de largo n
// ¿Cómo cambiamos el ciclo for de esta función por un ciclo while?
int busquedaBinaria(int n, int arr[], int v) {
  for(int l=0, r=n-1; l<=r;) {
    
    int m = (l + r)/2; 
    
    if (arr[m] == v)  
      return m;   
    
    if (arr[m] < v)  
      l = m + 1;  
    
    else 
      r = m - 1;  
  }
  
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
  
  int pos = busquedaBinaria(n, arr, x);

  if(pos == -1)
    printf("El elemento %d no se encuentra en el arreglo\n", x);
  else
    printf("El elemento %d está ubicado en la posición %d\n", x, pos);

  
  return EXIT_SUCCESS;
}
