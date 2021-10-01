#include <stdio.h>
#include <ctype.h>
 
int main(void) {
  
  printf("##########################\n");
  printf("### Biblioteca ctype.h ###\n");
  printf("##########################\n\n");

  char c;

  while(1) {
    printf("Ingrese un caracter ('e' para terminar): ");
    c = getchar(); // Captura un caracter desde la entrada estándar
    getchar(); // Consume el salto de línea que se genera al presionar enter

    if(isdigit(c)) printf("\t + '%c' es un dígito\n", c);
    if(isalpha(c)) printf("\t + '%c' es una letra\n", c);
    if(islower(c)) {
      printf("\t + '%c' es una letra minúscula.", c);
      printf(" Su versión mayúscula es '%c'\n", toupper(c));
    }
    if(isupper(c)) {
      printf("\t + '%c' es una letra mayúscula.", c);
      printf(" Su versión mayúscula es '%c'\n", tolower(c));
    }

    if(c=='e')
      break;

    printf("\n");
  }

  return 0;
}
