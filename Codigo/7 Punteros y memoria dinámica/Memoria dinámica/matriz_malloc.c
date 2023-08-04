#include <stdio.h>
#include <stdlib.h> // Contiene la definición de malloc

int main() {

  printf("#################################################\n");
  printf("### Reservar espacio para una matriz (malloc) ###\n");
  printf("#################################################\n\n");

  int n, m;
  printf("Ingrese número de filas y columas de la matriz: ");
  scanf("%d %d", &n, &m);


  // Arreglo de punteros a enteros
  int **M = malloc(n*sizeof(int *));

  // Por cada fila
  for(int i=0; i < n; i++)
    M[i] = (int *)malloc(m*sizeof(int));



  printf("Se reservó memoria para una matriz de %d filas y %d columnas (%ld"
  	 " bytes)\n", n, m, n*m*sizeof(int));


  printf("Puntero a M: %p\n", M);
  for(int i=0; i < n; i++)
    printf("\tPuntero a M[%d]: %p\n", i, M[i]);


  free(M);

  int n=10;
  int x[n];
  int *z = &n;
  FILE *f = fopen("salida.bin", "wb");

  fwrite(z, 1, sizeof(int), f);
  
  for(int i=0; i < 10; i++)
    fwrite(&x[i], 1, sizeof(int), f);
  fclose(f);


  ///////////////////////////////////
  
  FILE *f = fopen("salida.bin", "rb");

  int n=0;
  fread(&n, 1, sizeof(int), f);
  int arr[n];
  for(int i=0; i < 10; i++)
    fread(&arr[i], 1, sizeof(int), f);
  fclose(f);

  
  return 1;
}
