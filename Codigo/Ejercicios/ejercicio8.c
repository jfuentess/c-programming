/*
 * Ejercicio 8
 *
 * Escriba un programa que pida un número entero n, que luego genere dos
 * arreglos ordenados de largo n, A y B, con valores al azar, y finalmente
 * genere un arreglo ordenado C que sea el resultante de la unión de A y B. 
 *
 * Por ejemplo, si los arreglos generados son A = [1, 5, 9, 15] y B = [0, 6, 7,
 *  8], el programa debe generar el arreglo C = [0, 1, 5, 6, 7, 8, 9, 15].
 * 
 *  Criterio evaluación:
 *     - Test 1: n=1
 *       Ejemplo respuesta:
 *          A: 3 
 *          B: 6 
 *          C: 3 6 
 * 
 *     - Test 2: n=10
 *       Ejemplo respuesta:
 *          A: 3 10 13 19 28 30 30 33 33 35 
 *          B: 6 11 16 18 19 26 35 41 47 53 
 *          C: 3 6 10 11 13 16 18 19 19 26 28 30 30 33 33 35 35 41 47 53
 * 
 *     - Test 3: n=25
 *       Ejemplo respuesta:
 *          A: 3 10 13 19 28 30 30 33 33 35 36 43 45 47 54 63 65 74 77 78 87 88
 *             92 100 105  
 *          B: 6 11 16 18 19 26 35 41 47 53 61 70 70 73 78 80 88 95 101 103 106
 *             115 122 126 126  
 *          C: 3 6 10 11 13 16 18 19 19 26 28 30 30 33 33 35 35 36 41 43 45 47
 *             47 53 54 61 63 65 70 70 73 74 77 78 78 80 87 88 88 92 95 100 101
 *             103 105 106 115 122 126 126  
 * 
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Ingrese el valor de n: ");
  scanf("%d", &n);

  int A[n];
  int B[n];
  int C[2*n];

  int valA = 0;
  int valB = 0;
  
  for(int i=0; i < n; i++) {
    valA += rand()%10;
    valB += rand()%10;

    A[i] = valA;
    B[i] = valB;
  }

  int idA=0, idB=0, idC=0;
  for(; idA < n && idB < n; idC++) {
    if(A[idA] <= B[idB]) {
      C[idC] = A[idA];
      idA++;
    }
    else {
      C[idC] = B[idB];
      idB++;
    }
  }

  if(idA < n)
    for(int i=idA; i < n; i++, idC++)
      C[idC] = A[i];
  else if(idB < n)
    for(int i=idB; i < n; i++, idC++)
      C[idC] = B[i];

  printf("A: ");
  for(int i=0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");

  printf("B: ");
  for(int i=0; i < n; i++)
    printf("%d ", B[i]);
  printf("\n");

  printf("C: ");
  for(int i=0; i < 2*n; i++)
    printf("%d ", C[i]);
  printf("\n");
  
  return 0;
}
