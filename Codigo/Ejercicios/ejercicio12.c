/*
 * Pregunta 12
 *
 * Escriba la función void traspuesta(int n, int m, int M[n][m], int T[m][n])
 * que reciba la matriz M de n filas y m columnas, y compute su traspuesta, la
 * cual será almacenada en la matriz T . 
 *
 *
 *  Criterio evaluación:
 *     - Test 1:
 *        n = 1, m =1
 *
 *        M = |1|
 *        T = |1|
 *
 *     - Test 2:
 *        n = 10, m = 10
 *
 *        M = |  1   2   3   4   5   6   7   8   9  10 |
 *            | 11  12  13  14  15  16  17  18  19  20 |
 *            | 21  22  23  24  25  26  27  28  29  30 |
 *            | 31  32  33  34  35  36  37  38  39  40 |
 *            | 41  42  43  44  45  46  47  48  49  50 |
 *            | 51  52  53  54  55  56  57  58  59  60 |
 *            | 61  62  63  64  65  66  67  68  69  70 |
 *            | 71  72  73  74  75  76  77  78  79  80 |
 *            | 81  82  83  84  85  86  87  88  89  90 |
 *            | 91  92  93  94  95  96  97  98  99 100 |
 *
 *        T = | 1  11  21  31  41  51  61  71  81  91  |
 *            | 2  12  22  32  42  52  62  72  82  92  |
 *            | 3  13  23  33  43  53  63  73  83  93  |
 *            | 4  14  24  34  44  54  64  74  84  94  |
 *            | 5  15  25  35  45  55  65  75  85  95  |
 *            | 6  16  26  36  46  56  66  76  86  96  |
 *            | 7  17  27  37  47  57  67  77  87  97  |
 *            | 8  18  28  38  48  58  68  78  88  98  |
 *            | 9  19  29  39  49  59  69  79  89  99  |
 *            |10  20  30  40  50  60  70  80  90 100  |
 *
 *     - Test 3:
 *        n = 2, m = 8
 *
 *        M = |1   2   3   4   5   6   7   8 |
 *            |3   4   5   6   7   8   9  10 |
 *
 *        T = |1   3 |
 *            |2   4 |
 *            |3   5 |
 *            |4   6 |
 *            |5   7 |
 *            |6   8 |
 *            |7   9 |
 *            |8  10 |
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

void traspuesta(int n, int m, int M[n][m], int T[m][n]) {
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++)
      T[j][i] = M[i][j];
}

void print(int n, int m, int M[n][m]) {
  for(int i=0; i < n; i++) {
    for(int j=0; j < m; j++)
      printf("%3d ", M[i][j]);
    printf("\n");
  }
}

int main(int argc, char **argv) {
  int n, m;
  printf("Ingrese la cantidad de filas y columnas: ");
  scanf("%d %d", &n, &m);
  
  int M[n][m]; // Matriz inicial
  int T[m][n]; // Matriz traspuesta

  // Inicializamos las celdas de la matriz M
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++)
      M[i][j] = i*n + j + 1;

  print(n, m, M);printf("\n");

  // Llamada a la función transpuesta()
  traspuesta(n, m, M, T);

  print(m, n, T);printf("\n");

  return EXIT_SUCCESS;
}
