#include <stdio.h> 
#include <stdlib.h> 

void imprimir_matriz(int n, int m, int M[n][m]) {
  for(int i=0; i < n; i++) {
    for(int j=0; j < m; j++)
      printf("%3d ", M[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main(void) {

  int n, m;
  printf("Ingrese las dimensiones de la matriz: ");
  scanf("%d %d", &n, &m);

  int M[n][m];
  
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++)
      // Con una probabilidad del 50% las celdas tendrás valores válidos entre 0
      // y 99. Las otras celdas quedarán sin valor, lo que se representará con
      // un valor -1
      if(rand() % 2 == 1) // Se puede simplificar a if(rand() % 2)
	M[i][j] = rand() % 100;
      else
	M[i][j] = -1;

  imprimir_matriz(n, m, M);
  /*
    Implementar un programa que complete TODAS las celdas con valores -1 utilizando
    las siguientes reglas:
    - Si una celda con valor -1 está rodeada exclusivamente por celdas con
    valores -1, entonces no cambiará de valor
    - Si una celda con valor -1 está rodeada por al menos una celda con valor
    distinto a -1, entonces su nuevo valor será el resultado del promedio de las
    celdas vecinas con valores distintos a -1
   */
	  
  
  return EXIT_SUCCESS;
}
