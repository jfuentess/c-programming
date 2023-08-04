#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Para más información sobre números mágicos, revisar
//
// https://gist.github.com/leommoore/f9e57ba2aa4bf197ebc5
// https://en.wikipedia.org/wiki/File_format#Magic_number

int main(int argc, char** argv) {

  printf("################################################\n");
  printf("### Leer números mágicos de algunos archivos ###\n");
  printf("################################################\n\n");

  // Abrimos el stream para leer el archivo CSV
  FILE *fp  = fopen(argv[1],"r");

  // Declaramos un buffer para leer los primeros 8 bytes del archivo de entrada
  // (añadimos un byte adicional para el final de string '\0')
  unsigned char magic_number[9];

  // Leemos los primeros 8 bytes
  if(fgets(magic_number, 9, fp)) {   

    printf("Los primeros 8 bytes son (formato string): %s\n", magic_number);
    
    printf("Los primeros 8 bytes son (formato hexadecimal): ");
    for(int i=0; i < 8; i++)
      printf("%X ", (int)magic_number[i]);
    printf("\n");

  }
  
  return 0;

  /*********************************************************************/
  /* Pregunta: ¿QUé se imprime al ingresar un archivo PDF, PNG o JPEG? */
  /*********************************************************************/

}
