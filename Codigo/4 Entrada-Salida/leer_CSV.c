#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHAR 1000

int main() {

  printf("###########################");
  printf("### Leer un archivo CSV ###\n");
  printf("###########################\n\n");

  // Abrimos el stream para leer el archivo CSV
  FILE *fp  = fopen("twitter_users_30.csv","r");

  // Declaramos un buffer para leer las líneas del archivo
  char buffer[MAXCHAR];
  char *token;
  char sep[] = ";"; // Asumiremos que el separador es ";"

  // Mientras queden líneas por leer, avanzamos
  while (feof(fp) != true) {
    // Leemos la línea actual y la dejamos copiada en buffer
    if(fgets(buffer, MAXCHAR, fp)) {
      
      // Leemos el primer valor de la línea
      token = strtok(buffer, sep);
      
      // Leemos los valores restantes de la línea, separados por ";"
      while(token != NULL) {
	printf("%s | ", token);
	token = strtok(NULL, sep);
      }
      printf("\n");
    }
  }
  
  return 0;

  /***************************************************************/
  /* Pregunta 1: ¿Cómo podemos omitir la cabecera del archivo?   */
  /* Pregunta 2: ¿Cómo podemos filtar a usuarios con menos de 10 */
  /*             tweets publicados?                              */
  /***************************************************************/
}
