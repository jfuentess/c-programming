#include <stdio.h>
#include <stdlib.h> // Contiene la definición de malloc

int main() {

  printf("####################################################\n");
  printf("### Escritura de un arreglo a un archivo binario ###\n");
  printf("####################################################\n\n");

  int n=10;
  int x[n];

  // Escribimos el contenido del arreglo x en el archivo binario salida.bin
  FILE *fin = fopen("salida.bin", "wb");

  fwrite(&n, 1, sizeof(int), fin);
  
  for(int i=0; i < 10; i++)
    fwrite(&x[i], 1, sizeof(int), fin);
  fclose(fin);

  
  // Escribimos el contenido del archivo salida.bin y lo guardamos en el arreglo arr
  FILE *fout = fopen("salida.bin", "rb");

  n=0;
  fread(&n, 1, sizeof(int), fout);
  int arr[n];
  for(int i=0; i < 10; i++)
    fread(&arr[i], 1, sizeof(int), fout);
  fclose(fout);

  
  return 1;
}
