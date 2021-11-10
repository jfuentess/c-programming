/*
 * Pregunta 15
 *
 * Escriba la función int identidad(int n, int m, int M[n][m]) que reciba la
 * matriz  M de n filas y m columnas, y retorne 1 si la matriz M es la matriz
 * identidad y 0 en caso contrario.  
 *
 *
 *  Criterio evaluación:
 *     - Test 1:
 *        n = 10, m = 10
 *
 *        M = | 1  0  0  0  0  0  0  0  0  0 |
 *            | 0  1  0  0  0  0  0  0  0  0 |
 *            | 0  0  1  0  0  0  0  0  0  0 |
 *            | 0  0  0  1  0  0  0  0  0  0 |
 *            | 0  0  0  0  1  0  0  0  0  0 |
 *            | 0  0  0  0  0  1  0  0  0  0 |
 *            | 0  0  0  0  0  0  1  0  0  0 |
 *            | 0  0  0  0  0  0  0  1  0  0 |
 *            | 0  0  0  0  0  0  0  0  1  0 |
 *            | 0  0  0  0  0  0  0  0  0  1 |
 *
 *         Respuesta: 1 
 *
 *     - Test 2:
 *        n = 10, m = 10
 *
 *        M = | 3  0  0  0  0  0  0  0  0  0 |
 *            | 0  3  0  0  0  0  0  0  0  0 |
 *            | 0  0  3  0  0  0  0  0  0  0 |
 *            | 0  0  0  3  0  0  0  0  0  0 |
 *            | 0  0  0  0  3  0  0  0  0  0 |
 *            | 0  0  0  0  0  3  0  0  0  0 |
 *            | 0  0  0  0  0  0  3  0  0  0 |
 *            | 0  0  0  0  0  0  0  3  0  0 |
 *            | 0  0  0  0  0  0  0  0  3  0 |
 *            | 0  0  0  0  0  0  0  0  0  3 |
 *
 *         Respuesta: 0 
 *
 *     - Test 3:
 *        n = 10, m = 8
 *
 *        M = | 1  0  0  0  0  0  0  0 |
 *            | 0  1  0  0  0  0  0  0 |
 *            | 0  0  1  0  0  0  0  0 |
 *            | 0  0  0  1  0  0  0  0 |
 *            | 0  0  0  0  1  0  0  0 |
 *            | 0  0  0  0  0  1  0  0 |
 *            | 0  0  0  0  0  0  1  0 |
 *            | 0  0  0  0  0  0  0  1 |
 *            | 0  0  0  0  0  0  0  0 |
 *            | 0  0  0  0  0  0  0  0 |
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

// En esta implementación, recorreremos todas las celdas de la matriz M
// verificando si cumplen o no con la definición de una matriz identidad. Si una
// celda no cumple las condiciones, entonces retornamos de inmediato 0. Si todas
// las celdas pasan las condiciones, retornamos 1.
int identidad(int n, int m, int M[n][m]) {
  // Verificamos que la matriz sea cuadrada. Si no lo es, entonces M no es la
  // matriz identidad
  if(n != m) return 0;
  
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++) {
      // Si un elemento de la diagonal principal es distinto a 1, entonces M no
      // es una matriz identidad
      if(i == j && M[i][j] != 1)
	return 0;
      // Si un elemento que no pertenece a la diagonal principal es distinto a
      // 0, entonces M no es una matriz identidad
      else if (i != j && M[i][j] != 0)
	return 0;
    }

  return 1;
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
  if(identidad(n, m, M))
    printf("La matriz M es la matriz identidad de %dx%d\n", n, m);
  else
    printf("La matriz M no es la matriz identidad\n");

  return EXIT_SUCCESS;
}
