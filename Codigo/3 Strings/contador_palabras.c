#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {

  printf("############################\n");
  printf("### Contador de palabras ###\n");
  printf("############################\n\n");
  
  char texto[104] = "El Premio Turing es un premio de las Ciencias de la Computacion que es otorgado anualmente por la ACM. ";

  char *palabra;
  char *delimitador = " ";
  int cnt = 0;
  
  palabra = strtok(texto, delimitador); // Primera palabra

  // Mientras queden palabras por imprimir, continuamos
  while( palabra != NULL ) {
    printf("%s\n", palabra);
    cnt++;
    palabra = strtok(NULL, delimitador);
  }

  printf("\nHay %d palabras.\n", cnt);
  
  return 0;
}
