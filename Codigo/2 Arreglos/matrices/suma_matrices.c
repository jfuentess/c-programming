// Compilación: gcc -o suma_matrices suma_matrices.c

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

  printf("########################\n");
  printf("### Suma de matrices ###\n");
  printf("########################\n\n");

  int matriz1[10][10];
  int matriz2[10][10];
  int matriz3[10][10];

  // Llenado matrices
  for(int i = 0; i < 10; ++i)  // Filas
    for(int j = 0; j < 10; ++j) { // Columnas
      matriz1[i][j] = i*10 + j;
      matriz2[i][j] = i + j;
    }

  // Imprimimos el contenido de la matriz 1
  printf("Matriz 1:\n");
  for(int i = 0; i < 10; ++i) { // Filas
    printf("\t"); // Recordar que '\t' insertar una tabulación en el texto
                  //  impreso por pantalla
    for(int j = 0; j < 10; ++j) { // Columnas
      printf("%d ", matriz1[i][j]);
    }
    printf("\n");
  }

  // Imprimimos el contenido de la matriz 2
  printf("\nMatriz 2:\n");
  for(int i = 0; i < 10; ++i) { // Filas
    printf("\t");
    for(int j = 0; j < 10; ++j) { // Columnas
      printf("%d ", matriz2[i][j]);
    }
    printf("\n");
  }

  // Realizamos la suma de las matrices 1 y 2. El resultado será almacenado en
  // la matriz 3
  for(int i = 0; i < 10; ++i) 
    for(int j = 0; j < 10; ++j)
  	matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
	
  // Imprimimos el contenido de la matriz 3 (matriz resultante)
  printf("\nMatriz 3:\n");
  for(int i = 0; i < 10; ++i) { // Filas
    printf("\t");
    for(int j = 0; j < 10; ++j) { // Columnas
      printf("%d ", matriz3[i][j]);
    }
    printf("\n");
  }
  

  return EXIT_SUCCESS;
}
