#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Guardamos un arreglo de n enteros en un archivo
void guardar_arreglo(const char *fname, int *arr, int n) {
  FILE *fout = fopen(fname, "wb");

  if (!fout) {
    fprintf(stderr, "Error al abrir el archivo \"%s\".\n", fname);
    exit(EXIT_FAILURE);
  }

  // Escribimos los primeros n enteros de arreglo arr en el archivo abierto en
  // fout
  fwrite(arr, sizeof(int), n, fout);

  // Cerramos el stream sobre el cual estábamos escribiendo
  fclose(fout);
}

// Leemos un arreglo de n enteros desde un archivo
int * cargar_arreglo(const char *fname, int *n) {
  FILE *fin = fopen(fname, "rb");

  if (!fin) {
    fprintf(stderr, "Error al abrir el archivo \"%s\".\n", fname);
    exit(EXIT_FAILURE);
  }

  // Movemos el puntero que apunta al inicio del archivo hasta el final
  fseek(fin, 0L, SEEK_END);
  // Recuperamos la posición (en cantidad de bytes) del puntero
  *n = ftell(fin);
  // Calculamos la cantidad de enteros del arreglo
  *n /= sizeof(int);
  // Restablecemos el puntero al inicio
  fseek(fin, 0L, SEEK_SET);

  // Reservamos espacio para *n enteros
  int *arr = malloc(*n*sizeof(int));

  // Leemos *n enteros desde el stream/archivo abierto en fin
  fread(arr, sizeof(int), *n, fin);

  // Cerramos el stream sobre el cual estábamos leyendo
  fclose(fin);
  return arr;
}

int main(int argc, char **argv) {

  if(argc < 2) {
    fprintf(stderr, "Uso: %s <archivo de salida>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int n=0;
  printf("Ingrese el largo del arreglo: ");
  scanf("%d", &n);

  int *arr = malloc(n*sizeof(int));
  fill_array(arr, n, 10, 30);
  printf("Arreglo 1: ");
  print_array(arr, n);

  // Guardamos el arreglo en un archivo
  guardar_arreglo(argv[1], arr, n);

  int m=0;
  // Leemos un arreglo desde archivo
  int *arr2 = cargar_arreglo(argv[1], &m);
  printf("Arreglo 2: ");
  print_array(arr2, m);
  
  return EXIT_SUCCESS;
}
