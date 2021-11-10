/*
 * Pregunta 15
 *
 * Escriba la función int ortogonal(int n, int m, int M[n][m]) que reciba la
 * matriz M de n filas y m columnas, y retorne 1 si la matriz M es ortogonal y 0
 * en caso contrario. Para responder esta pregunta debe utilizar las funciones
 * resultantes de las preguntas 12, 13 y 14.
 *
 * Nota: Una matriz cuadrada A es ortogonal si se cumple A × A^T = I, donde A^T
 * es la matriz traspuesta de A e I es la matriz identidad.
 *
 *  Criterio evaluación:
 *     - Test 1:
 *        n = 3, m = 3
 *
 *        M = | 0 -1  0 |
 *            | 1  0  0 |
 *            | 0  0 -1 |
 *
 *         Respuesta: 1 
 *
 *     - Test 2:
 *        n = 2, m = 2
 *
 *        M = | 0  1 |
 *            | 1  0 |
 *
 *         Respuesta: 1 
 *
 *     - Test 3:
 *        n = 5, m = 5
 *
 *        M = | 1 0 0 0 1 |
 *            | 0 1 0 1 0 |
 *            | 0 0 1 0 0 |
 *            | 0 1 0 1 0 |
 *            | 1 0 0 0 1 |
 *
 *         Respuesta: 0 
 *
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

void print(int n, int m, int M[n][m]) {
  for(int i=0; i < n; i++) {
    for(int j=0; j < m; j++)
      printf("%3d ", M[i][j]);
    printf("\n");
  }
}

// Respuesta a pregunta 1
void traspuesta(int n, int m, int M[n][m], int T[m][n]) {
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++)
      T[j][i] = M[i][j];
}

// Respuesta a pregunta 2
void mult(int n, int m, int l, int M[n][m], int T[m][l], int R[n][l]) {

  for(int i=0; i < n; i++)
    for(int j=0; j < l; j++)
      R[i][j] = 0;
  
  for(int i=0; i < n; i++)
    for(int j=0; j < l; j++)
      for(int k=0; k < m; k++)
	R[i][j] += M[i][k] * T[k][j];
}

// Respuesta a pregunta 3
int identidad(int n, int m, int M[n][m]) {
  if(n != m) return 0;
  
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++) {
      if(i == j && M[i][j] != 1)
	return 0;
      else if (i != j && M[i][j] != 0)
	return 0;
    }
  return 1;
}

// Respuesta a pregunta 3
int ortogonal(int n, int m, int M[n][m]) {
  // Si la matriz no es cuadrada, entonces no es ortogonal
  if(n != m) return 0;

  // Nota: A partir de este punto estamos seguros que n=m, por lo que declarar
  // int T[n][m] es lo mismo que int T[n][n]
  int T[n][n]; // Matriz transpuesta de M
  int R[n][n]; // Matriz resultante de la multiplicación de M y T

  traspuesta(n, m, M, T);
  mult(n, m, n, M, T, R);

  return identidad(n, n, R);
}

int main(int argc, char **argv) {
  int n, m;
  printf("Ingrese la cantidad de filas y columnas: ");
  scanf("%d %d", &n, &m);
  
  int M[n][m]; 

  // Inicializamos las celdas de la matriz M
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++)
      scanf(" %d", &M[i][j]);

  print(n, m, M);printf("\n");

  // Llamada a la función identidad()
  if(ortogonal(n, m, M))
    printf("La matriz M es ortogonal\n");
  else
    printf("La matriz M no es ortogonal\n");

  return EXIT_SUCCESS;
}
