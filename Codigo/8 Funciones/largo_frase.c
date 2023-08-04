#include <stdio.h>
#include <stdlib.h>

// Función recursiva que calcula el largo de una frase
int largo_frase(char frase[]) {
  printf("Calculando el largo de %s\n", frase);
  
  if(frase[0] == '\0') return 0; // Caso base
  return 1 + largo_frase(&frase[1]);
}

// (Alternativa) Función recursiva que calcula el largo de una frase
int largo_frase2(char *frase) {
  printf("Calculando el largo de %s\n", frase);
  if(frase[0] == '\0') return 0; // Caso base
  return 1 + largo_frase2(frase + 1);
}

int main (){
  char frase[100] = {};

  printf("Ingrese una frase de hasta 100 símbolos (incluídos espacios): ");
  scanf("%[^\n]s", frase);

  int largo = largo_frase(frase);

  printf("El largo de la frase es %d\n", largo);
  
  return 0;
}





