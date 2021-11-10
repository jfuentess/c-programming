/*
 * Ejercicio 9
 *
 * Escriba un programa que pida un número entero positivo n y que luego pida
 * suficientes números que serán almacenados en una matriz triangular superior
 * de n x n. 
 *
 * 
 *  Criterio evaluación:
 *     - Test 1: 
 *              n=8
 *              Se ingresan 16 valores: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 *                                      1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
 *              Respuesta:
 *               	1 1 1 1 1 1 1 1 
 *               	0 1 1 1 1 1 1 1 
 *               	0 0 1 1 1 1 1 1 
 *               	0 0 0 1 1 1 1 1 
 *               	0 0 0 0 1 1 1 1 
 *               	0 0 0 0 0 1 1 1 
 *               	0 0 0 0 0 0 1 1 
 *               	0 0 0 0 0 0 0 1
 *
 *     - Test 2:
 *              n=1
 *              Se ingresa 1 valor: 2
 *              Respuesta:
 *               	2
 *
 *     - Test 3: 
 *              n=5
 *              Se ingresan 15 valores: 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
 *              Respuesta:
 *               	3 3 3 3 3 
 *               	0 3 3 3 3 
 *               	0 0 3 3 3 
 *               	0 0 0 3 3 
 *               	0 0 0 0 3 
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  int n;
  printf("Ingrese el valor de n: ");
  scanf("%d", &n);

  int M[n][n];
  for(int i=0; i < n; i++)
    for(int j=0; j < n; j++) 
      M[i][j] = 0;
  
  // cantidad de celdas a ingresar en la matriz superior
  int m = (n*n + n)/2;

  printf("Se deben ingresar %d valores a la matriz triangular superior\n", m);
  
  int val = 0;
  for(int i=0; i < n; i++)
    for(int j=i; j < n; j++) {
      printf("Ingrese el valor de la celda (%d,%d): ", i, j);
      scanf(" %d", &val);
      M[i][j] = val;
    }

  printf("Matriz resultante:\n");
  for(int i=0; i < n; i++) {
    printf("\t");
    for(int j=0; j < n; j++)
      printf("%d ", M[i][j]);
    printf("\n");
  }
  
  return EXIT_SUCCESS;
}
