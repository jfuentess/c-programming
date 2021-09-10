// Compilación: gcc -o palindromo palindromo.c

#include <stdlib.h>
#include <stdio.h>

// Código para detectar si una palabra es palíndroma o no

int main() {

  printf("################################\n");
  printf("### Detección de palíndromos ###\n");
  printf("################################\n\n");
  
  char arr[9] = {'r', 'e', 'c', 'o', 'n', 'o', 'c', 'e', 'r'};
  int n = 9; // El largo de la palabra
  
  // Impresión de la palabra
  for(int i=0; i < n; i++)
    printf("%c ", arr[i]);
  printf("\n");

  /* OPCION 1 */
  printf("\n\e[96mOpción 1\n\e[0m");

  int x = 0; // Palindromo
  for(int i = 0, j = n-1; i < n; i++, j--) {
    printf("arr[%d]: %c vs arr[%d]: %c => ", i, arr[i], j, arr[j]);
    if(arr[i] != arr[j]) {
      printf("Distinto (No es palindromo)\n");
      x = 1;
    }
    else
      printf("Las letras son iguales\n");
  }

  if(x == 0)
    printf("Es palindromo\n");
  else
    printf("No es palindromo\n");


  /* OPCION 2 */
  printf("\n\e[96mOpción 2\n\e[0m");

  for(int i = 0, j = n-1; i < n; i++, j--) {
    if(arr[i] != arr[j]) {
      printf("Distinto (No es palindromo)\n");
      return 0;
    }
  }
  printf("Es palindromo\n");

  /* OPCION 3 */
  printf("\n\e[96mOpción 3\n\e[0m");

  for(int i = 0; i < n; i++) {
    if(arr[i] != arr[n-1-i]) {
      printf("Distinto (No es palindromo)\n");
      return 0;
    }
  }
  printf("Es palindromo\n");
  
  return 0;
}
