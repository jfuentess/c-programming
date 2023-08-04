#include <stdio.h>
#include <string.h>

int main() {
  int arr1[10] = {0, 1024, 20, 30, 40, 50, 60, 70, 80, 530};
  char *sec = "Secuencia de caracteres";

  // Podemos recorrer un arreglo de enteros usando un puntero a char (leyendo
  // byte a byte), así como también podemos leer un arreglo de chars usando un
  // puntero a int (leyendo cada 4 bytes)
  char *pa = (char *)arr1; // Casting de int * -> char *
  int *ps = (int *)sec; // Casting de char * -> int *

  // Calculamos la cantidad de char e int a leer
  int na = 10 * sizeof(int)/sizeof(char);
  int ns = strlen(sec) / sizeof(int);
  
  for(int i=0; i < na; i++) {
    printf("%d ", *pa);
    pa++;
  }
  printf("\n");


  for(int i=0; i < ns; i++) {
    printf("%d ", *ps);
    ps++;
  }
  printf("\n");

  return 1;
}
