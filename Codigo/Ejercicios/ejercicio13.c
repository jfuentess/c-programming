/*
 * Pregunta 13
 *
 * Escriba la función void mult(int n, int m, int l, int M[n][m], int T[m][l],
 * int R[n][l]), la cual computará la multiplicación de las matrices M y T . La
 * matriz resultante quedará almacenada en la matriz R.  
 *
 *
 *  Criterio evaluación:
 *     - Test 1:
 *        n = 1, m =1, l=1
 *
 *        M = |1|
 *        T = |1|
 *        R = |1|
 *
 *     - Test 2:
 *        n = 10, m = 5, l=3
 *
 *        M = |  1    2    3    4    5 |
 *            | 11   12   13   14   15 |
 *            | 21   22   23   24   25 |
 *            | 31   32   33   34   35 |
 *            | 41   42   43   44   45 |
 *            | 51   52   53   54   55 |
 *            | 61   62   63   64   65 |
 *            | 71   72   73   74   75 |
 *            | 81   82   83   84   85 |
 *            | 91   92   93   94   95 |
 *
 *        T = |    1    2    3 |
 *            |    6    7    8 |
 *            |   11   12   13 |
 *            |   16   17   18 |
 *            |   21   22   23 |
 *
 *        R = |  215  230  245 |
 *            |  765  830  895 |
 *            | 1315 1430 1545 |
 *            | 1865 2030 2195 |
 *            | 2415 2630 2845 |
 *            | 2965 3230 3495 |
 *            | 3515 3830 4145 |
 *            | 4065 4430 4795 |
 *            | 4615 5030 5445 |
 *            | 5165 5630 6095 |
 *
 *     - Test 3:
 *        n = 1, m = 8, l = 1
 *
 *        M = |   1    2    3    4    5    6    7    8 |
 *
 *        T = |  1 |
 *            |  9 |
 *            | 17 |
 *            | 25 |
 *            | 33 |
 *            | 41 |
 *            | 49 |
 *            | 57 |
 *
 *        R = | 1380 |
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

void mult(int n, int m, int l, int M[n][m], int T[m][l], int R[n][l]) {  
  for(int i=0; i < n; i++)
    for(int j=0; j < l; j++)
      for(int k=0; k < m; k++)
	R[i][j] += M[i][k] * T[k][j];
}

void print(int n, int m, int M[n][m]) {
  for(int i=0; i < n; i++) {
    for(int j=0; j < m; j++)
      printf("%4d ", M[i][j]);
    printf("\n");
  }
}

int main(int argc, char **argv) {
  int n, m, l;
  printf("Ingrese la cantidad de filas y columnas de la primera matriz: ");
  scanf("%d %d", &n, &m);

  printf("Ingrese la cantidad columnas de la segunda matriz: ");
  scanf(" %d", &l);

  int M[n][m]; // Primera matriz a multiplicar
  int T[m][l]; // Segunda matriz a multiplicar
  int R[n][l]; // Matriz resultante 

  // Inicializamos las celdas de las matrices M y T
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++)
      M[i][j] = i*n + j + 1;
  
  for(int i=0; i < m; i++)
    for(int j=0; j < l; j++)
      T[i][j] = i*m + j + 1;

  for(int i=0; i < n; i++)
    for(int j=0; j < l; j++)
      R[i][j] = 0;

  print(n, m, M);printf("\n");
  print(m, l, T);printf("\n");

  // Llamada a la función mult()
  mult(n, m, l, M, T, R);

  print(n, l, R);printf("\n");
  
  return EXIT_SUCCESS;
}
