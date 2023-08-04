#include <stdio.h>
#include <string.h>

int main() {
  int arr1[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
  char *sec = "Secuencia de caracteres";

  // Puntero al elemento con índice 0
  int *p0 = &arr1[0]; 
  // Puntero al elemento con índice 5
  int *p5 = &arr1[5];

  printf("puntero a arr1: %p\n", arr1);
  printf("puntero a p0: %p\n", p0);
  printf("puntero a p5: %p\n", p5);

  // ¿Cuál es la diferencia entre las siguientes tres líneas?
  p5++; //arr1[5] -> arr1[6]
  (*p5) = 10;
  *p5++;
    
  for(int i=0; i < 10; i++)
    printf("(índice de un arreglo) %d vs %d (uso de punteros)\n", arr1[i], *(arr1+i));

  int ns = strlen(sec);

  printf("\n");
  for(int i=0; i < ns; i+=2)
    printf("(índice de un arreglo) %c vs %c (uso de punteros)\n", sec[i], *(sec+i));
  
  return 1;
}
