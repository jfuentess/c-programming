#include <stdlib.h>
#include <stdio.h>

int main() {

  printf("###############################################\n");
  printf("### Inserción de un nuevo elemento (resize) ###\n");
  printf("###############################################\n\n");

  int n, p, v;
  printf("\tIngrese el largo del arreglo: ");
  scanf("%d", &n);

  int arr[n];

  // Inicializaremos el arreglo con valores al azar en el rango [0,99]
  for(int i=0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  printf("\nArreglo original:\n\t");
  for(int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n\n");

  // TAREA: ¿Qué ocurre si ingresan una posición negativa o mayor a n?
  printf("\tIngrese la posición donde quiere insertar un nuevo elemento: ");
  scanf(" %d", &p);
  printf("\tIngrese el valor del nuevo elemento a insertar: ");
  scanf(" %d", &v);

  int nuevo[n+1];

  // Copiamos los valores del arreglo 'arr' en el rango [0,p-1]
  for(int i=0; i < p; i++)
    nuevo[i] = arr[i];

  nuevo[p] = v; // Insertamos el nuevo elemento

  // Copiamos los valores del arreglo 'arr' en el rango [p,n]
  for(int i=p+1; i < n+1; i++)
    nuevo[i] = arr[i-1];
  
  printf("\nArreglo luego de la inserción:\n\t");
  for(int i=0; i < n+1; i++)
    printf("%d ", nuevo[i]);
  printf("\n");
	 
  return 0;
}
