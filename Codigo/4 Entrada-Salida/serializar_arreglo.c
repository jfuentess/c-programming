#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

  printf("########################################\n");
  printf("### Serializar un arreglo de enteros ###\n");
  printf("########################################\n\n");

  // Ejemplo de un arreglo de 15 valores
  int arr[] = {2, 3, 5, 7, 11, 13, 1000007, 19, 23, 29, 3100000, 37, 41, 43, 470000};
  int arr2[15];
  char arr3[60];
  
  // Abrimos un stream para guardar el arreglo serializado
  FILE *fp = fopen("serializacion.bin", "wb");

  // Escribimos el arreglo al archivo
  fwrite(arr, sizeof(int), 15, fp);

  // Cerramos el stream
  fclose(fp);

  puts("El archivo serializacion.bin contiene el arreglo serializado");

  puts("Ahora, probaremos abrir el archivo recién creado");

  // Ahora abrimos el archivo en modo sólo lectura
  fp = fopen("serializacion.bin", "rb");

  fread(arr2, sizeof(int), 15, fp);

  // Cerramos el stream
  fclose(fp);

  for(int i=0; i < 15; i++) 
    printf("%d ", arr2[i]);
  printf("\n");
  

  // Ahora abrimos el archivo en modo sólo lectura
  fp = fopen("serializacion.bin", "rb");

  fread(arr3, sizeof(char), 60, fp);

  // Cerramos el stream
  fclose(fp);

  for(int i=0; i < 60; i++) 
    printf("%d ", arr3[i]);
  printf("\n");
  for(int i=0; i < 60; i++) 
    printf("%c ", arr3[i]);
  printf("\n");
  

  /* // Movemos la posición de stream al final del archivo */
  /* fseek(fp, 0L, SEEK_END); */
  
  /* // Obtenemos la posición, en bytes del stream */
  /* long int num_bytes = ftell(fp); */
  /* long int num_ints = num_bytes / sizeof(int); */
  
  /* // Volvemos a cerrar el stream */
  /* fclose(fp); */

  /* printf("El archivo tiene %ld bytes, correspondientes a %ld valores enteros\n", num_bytes, num_ints); */
  
  return 0;

}
