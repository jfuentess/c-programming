#include <stdio.h>
#include <stdlib.h>
// Nombre de un arreglo se puede interpretar como un puntero
int strlen_local(char *t) {
  // Variable local a la función strlen_local
  int largo = 0;
  int pos = 0;
  while(*t != '\0') {
    largo ++;
    t++;// me muevo al siguiente elemento
  }

  return largo;
}

int main() {
  char texto[128];
  int i=0;

  printf("Ingrese un texto: ");
  scanf("%[^\n]s", texto);

  // Llamamos a la función strlen_local con el parámetro 'texto'
  int l = strlen_local(texto);

  printf("El largo del texto ingresado es %d\n", l);
  
  return EXIT_SUCCESS;
}
