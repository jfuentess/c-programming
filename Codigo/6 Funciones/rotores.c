#include "rotores.h"

void rotar(char *rotor, int n) {
    char aux = rotor[n-1];
    for (int i = 0; i < n; i++)
        rotor[n - i] = rotor[n - i -1];
    rotor[0] = aux;
}

char *generar_rotor(int *n) {
  *n = 62;
  char *rotor = malloc(62 * sizeof(char));

  for(int i=0; i < 10; i++) rotor[i]    = 48+i;
  for(int i=0; i < 26; i++) rotor[10+i] = 65+i;
  for(int i=0; i < 26; i++) rotor[36+i] = 97+i;
  
  for(int i=0; i < 100; i++) {
    int a = rand() % 62;
    int b = rand() % 62;
    char tmp = rotor[a];
    rotor[a] = rotor[b];
    rotor[b] = tmp;
  }
  return rotor;
}
