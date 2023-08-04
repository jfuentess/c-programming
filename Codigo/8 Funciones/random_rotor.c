#include <stdio.h>
#include <stdlib.h>

int main() {

  // Generaremos un rotor al azar intercambiando 30 veces posiciones de un rotor
  // inicialmente ordenardo
  char rotor[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y',
		    'X', 'Z'};

  // Imprimimos el rotor antes de intercambiar los valores 30 veces
  for(int i=0; i < 26; i++)
    printf("%c ", rotor[i]);
  printf("\n");
  
  int n=30;
  for(int i=0; i < n; i++) {
    int a = rand() % 26;
    int b = rand() % 26;

    char tmp = rotor[a];
    rotor[a] = rotor[b];
    rotor[b] = tmp;
  }

  // Imprimimos el rotor luego de realizar los 30 intercambios
  for(int i=0; i < 26; i++)
    printf("%c ", rotor[i]);
  printf("\n");

  return 1;
}
