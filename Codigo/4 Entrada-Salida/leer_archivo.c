#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHAR 1000

int main() {

  printf("################################\n");
  printf("### Leer un archivo de texto ###\n");
  printf("################################\n\n");

  // Abrimos el stream para leer el archivo CSV
  FILE *fp  = fopen("ejemplo.txt","r");

  // Declaramos un buffer para leer las líneas del archivo
  char buffer[MAXCHAR];
  char *token;

  int n_linea = 1;
  // Mientras queden líneas por leer, avanzamos
  while (feof(fp) != true) {
    // Leemos la línea actual y la dejamos copiada en buffer
    if(fgets(buffer, MAXCHAR, fp)) {   
      printf("Línea %d: %s", n_linea, buffer);
      n_linea++;
    }
  }
  
  return 0;

  /*************************************************************/
  /* Pregunta: ¿Podemos leer archivos más grandes que nuestra  */
  /*           memoria RAM?¿Cómo sería posible?                */
  /*************************************************************/
  
}
