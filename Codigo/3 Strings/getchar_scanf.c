#include <stdio.h>
#include <stdlib.h> // atoi, atof, atol, ...
 
int main(int argc, char ** argv) {

  printf("#######################\n");
  printf("### Caracteres en C ###\n");
  printf("#######################\n\n");

  char c1, c2, c3 = '$';
  printf("Ingrese un caracter: ");
  c1 = getchar(); // Captura un caracter desde la entrada estándar
  getchar(); // Consume el salto de línea que se genera al presionar enter
  putchar(c1); // Imprime un caracter por la salida estándar
  
  printf("\nIngrese otro caracter: ");
  c1 = getchar();
  getchar();
  putchar(c1);

  printf("\nIngrese dos caracteres: ");
  scanf("%c %c", &c2, &c3);
  printf("Caracteres ingresados: '%c' '%c'\n", c2, c3);

  // ¿Qué pasa si quitamos este getchar()?
  getchar();

  printf("\nIngrese dos caracteres: ");
  scanf("%c %c", &c2, &c3);
  printf("Caracteres ingresados: '%c' '%c'\n", c2, c3);

  return 0;
}
