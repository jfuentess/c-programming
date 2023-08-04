#include <stdio.h>
#include <stdlib.h> // Declaración de EXIT_FAILURE y EXIT_SUCCESS 

int main(int argc, char **argv) {

  if(argc != 3) {
    printf("Uso: %s <archivo salida texto> <archivo salida binario>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  

  printf("#####################################\n");
  printf("### Lectura/escritura en archivos ###\n");
  printf("#####################################\n\n");

  int arr[10] = {4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295};
  
  // Abrimos los archivos para escritura
  FILE *pin_txt = fopen(argv[1], "w");
  FILE *pin_bin = fopen(argv[2], "wb");


  for(int i=0; i < 10; i++) {
    // Escribe en la consola de salida (salida estándar)
    printf("%d ", arr[i]);
  }

  for(int i=0; i < 10; i++) {
    // Escribe en el archivo apuntado por 'pin_txt'
    fprintf(pin_txt, "%u ", arr[i]);
  }

  fwrite(arr, sizeof(int), 10, pin_bin);

  for(int i=0; i < 10; i++) {
    // Escribe en el archivo apuntado por 'pin_bin'
    fwrite(&arr[i], sizeof(int), 1, pin_bin);
  }

  // Cerramos los archivos
  fclose(pin_txt);
  fclose(pin_bin);
  
  return EXIT_SUCCESS;
}

