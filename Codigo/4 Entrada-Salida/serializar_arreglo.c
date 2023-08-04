#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

  printf("########################################\n");
  printf("### Serializar un arreglo de enteros ###\n");
  printf("########################################\n\n");

  // Ejemplo de un arreglo de 15 valores
  int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

  // Abrimos un stream para guardar el arreglo serializado
  FILE *fp = fopen("serializacion.bin", "wb");

  // Escribimos el arreglo al archivo
  fwrite(arr, sizeof(int), 15, fp);

  // Cerramos el stream
  fclose(fp);

  puts("El archivo serializacion.bin contiene el arreglo serializado");

  puts("Ahora, probaremos abrir el archivo recién creado");

  // Ahora abrimos el archivo en modo sólo lectura
  fp = fopen("serializacion.bin", "r");

  // Movemos la posición de stream al final del archivo
  fseek(fp, 0L, SEEK_END);
  
  // Obtenemos la posición, en bytes del stream
  long int num_bytes = ftell(fp);
  long int num_ints = num_bytes / sizeof(int);
  
  // Volvemos a cerrar el stream
  fclose(fp);

  printf("El archivo tiene %ld bytes, correspondientes a %ld valores enteros\n", num_bytes, num_ints);
  
  return 0;

}
