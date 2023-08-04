#include <stdio.h>
#include <stdlib.h>

void print(int n, int m, int M[n][m]) {
  for(int i=0; i < n; i++) {
    for(int j=0; j < m; j++)
      printf("%3d ", M[i][j]);
    printf("\n");
  }
}

// Respuesta a pregunta 12
void traspuesta(int n, int m, int M[n][m], int T[m][n]) {
  for(int i=0; i < n; i++)
    for(int j=0; j < m; j++)
      T[j][i] = M[i][j];
}

// Respuesta a pregunta 13
void mult(int n, int m, int l, int M[n][m], int T[m][l], int R[n][l]) {

  for(int i=0; i < n; i++)
    for(int j=0; j < l; j++)
      R[i][j] = 0;
  
  for(int i=0; i < n; i++)
    for(int j=0; j < l; j++)
      for(int k=0; k < m; k++)
	R[i][j] += M[i][k] * T[k][j];
}

// Respuesta a pregunta 14
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

// Respuesta a pregunta 15
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
