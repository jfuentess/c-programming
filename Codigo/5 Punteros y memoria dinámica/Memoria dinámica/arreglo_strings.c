#include <stdio.h>
#include <stdlib.h> // Contiene la definición de malloc
#include <string.h>

#define N 256

int main(int argc, char **argv) {

  printf("###################################################\n");
  printf("### Almacenar frases de largo variable (malloc) ###\n");
  printf("###################################################\n\n");

  // Número de frases
  int num_f;
  char s[N]; // Stack
  char **frases; // Heap
  
  printf("Ingrese el número total de frases: ");
  scanf("%d", &num_f);

  frases = malloc(num_f*sizeof(char *));

  for(int i=1; i <= num_f; i++) {
    printf("Ingrese frase %d: ", i);
    scanf(" %[^\n]s", s);

    int ls = strlen(s);
    
    frases[i-1] = malloc((ls+1)*sizeof(char));
    strncpy(frases[i-1], s, ls);
    frases[i-1][ls] = '\0';
  }

  printf("\n");
  for(int i=1; i <= num_f; i++)
    printf("Frase %d: %s (%lu)\n", i, frases[i-1], strlen(frases[i-1]));

  for(int i=0; i < num_f; i++)
    free(frases[i]);
  free(frases);

  return 1;
}
