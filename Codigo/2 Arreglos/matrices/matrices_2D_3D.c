// Arreglos en 2 y 3 dimensiones
// Enlace con información complementaria:
// https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/

// Compilación: gcc -o matrices_2D_3D matrices_2D_3D.c

#include <stdlib.h>
#include <stdio.h>

int main() {
  
  /*********************************/
  /*** Arreglos en 2 dimensiones ***/
  /*********************************/

  printf("###################\n");
  printf("### Arreglos 2D ###\n");
  printf("###################\n\n");

  // Declaración de matrices en 2 dimensiones
  int arr2D_1[5][4] = {};
  int arr2D_2[5][4] = {4, 6, 8, 12, 30, -4, 11, 78, -42, -100, 0, 1, 96, 76, -8,
  		       55, 72, 3, -5, -6};
  
  int arr2D_3[5][4] = {{4, 6, 8, 12},
  		       {30, -4, 11, 78},
  		       {-42, -100, 0, 1},
  		       {96, 76, -8, 55},
  		       {72, 3, -5, -6}};

  
  // Imprimimos una matriz en 2 dimensiones
  printf("arr2D_3:\n");
  for(int i=0; i < 5; i++) { // Filas
    printf("\t");
    for(int j=0; j < 4; j++) { // Columnas
      printf("(%d,%d):%d  ", i, j, arr2D_3[i][j]);
    }
    printf("\n");
  }

  int A[12] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};

  printf("\nArreglo 1D como matriz:\n");
  printf("\t");
  for(int i=0; i <4; i++)
    for(int j=0; j <3; j++)
      printf("%d ", A[i + j]);
  printf("\n");

  /*********************************/
  /*** Arreglos en 3 dimensiones ***/
  /*********************************/

  printf("\n###################\n");
  printf("### Arreglos 3D ###\n");
  printf("###################\n\n");

  int arr3D_1[3][2][4];
  int arr3D_2[3][2][4] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4,1, 2,
  			  3, 4, 1, 2, 3, 4};
  int arr3D_3[3][2][4] = {
  			  {{1, 2, 3, 4}, {1, 2, 3, 4}},
  			  {{1, 2, 3, 4}, {1, 2, 3, 4}},
  			  {{1, 2, 3, 4}, {1, 2, 3, 4}}
                          };

  // Imprimimos una matriz en 3 dimensiones
  printf("arr3D_3:\n");
  for(int k=0; k < 4; k++) { // Tercera dimesión
    for(int i=0; i < 2; i++) { // Primera dimensión
      printf("\t");
      for(int j=0; j < 3; j++) { // Segunda dimensión
  	printf("%d ", arr3D_3[i][j][k]);
      }
      printf("\n");
    }
    printf("\t-----\n");
  }

  return 0;
}
