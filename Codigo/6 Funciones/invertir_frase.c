#include <stdio.h>
#include <stdlib.h>

void invertir(char frase[]) {
  if(frase[0] == '\0')
    return;

  // ¿Qué pasa si imprimimos antes de la llamada recursiva?
  invertir(&frase[1]);
  printf("%c", frase[0]);
}

int main(void) {
  char frase[100] = {};

  printf("Ingrese una frase de hasta 100 símbolos (incluídos espacios): ");
  scanf("%[^\n]s", frase);

  invertir(frase);
  
  return EXIT_SUCCESS;
}
