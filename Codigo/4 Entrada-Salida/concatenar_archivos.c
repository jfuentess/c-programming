#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

  printf("###############################\n");
  printf("### concatenar dos archivos ###\n");
  printf("###############################\n\n");

  if(argc != 4) {
    printf("Uso: %s <archivo 1> <archivo 3> <archivo 3>\n", argv[0]);
    exit(0);
  }

  // Abrimos streams para los dos archivos a concatenar
  // El argumento argv[1] contiene el nombre del primer archivo
  FILE *fp1 = fopen(argv[1], "r"); 
  // El argumento argv[2] contiene el nombre del segundo archivo
  FILE *fp2 = fopen(argv[2], "r");

  // Abrimos el stream para el archivo de salida
  // El argumento argv[3] contiene el nombre del archivo de salida
  FILE *fp3 = fopen(argv[3], "w");
  char c;

  if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
    puts("No se pueden abrir los streams/archivos");
    exit(0);
  }
  
  // Copiamos el contenido del primer archivo
  while ((c = fgetc(fp1)) != EOF)
    fputc(c, fp3);
  
  // Copiamos el contenido del segundo archivo
  while ((c = fgetc(fp2)) != EOF)
	fputc(c, fp3);

  printf("Los archivos %s y %s fueron mezclados en el archivo %s\n", argv[1], argv[2], argv[3]);
  
  // Cerramos los streams
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  
  return 0;

  /*****************************************************************/
  /* ¿Cómo podemos hacerlo funcionar para concatenar más archivos? */ 
  /*****************************************************************/

}
