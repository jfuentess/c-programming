#include <stdlib.h>
#include "utils_array.h"

void imprimir_arreglo(char *A, int n) {
  for(int i=0; i < n; i++)
    printf("%2d ", i);
  printf("\n");

  for(int i=0; i < n; i++)
    printf("%s%s%2c %s", BOLD, BLUE, A[i], NORMAL);
  printf("\n\n");
}

void guardar_arreglo(char *A, int n, const char *fname) {
  FILE *fout = fopen(fname, "w");

  if (!fout) {
    fprintf(stderr, "Error al abrir el archivo \"%s\".\n", fname);
    exit(EXIT_FAILURE);
  }

  fwrite(A, sizeof(char), n, fout);
  fclose(fout);
}

char* cargar_arreglo(const char *fname, int *n) {
  FILE *fin = fopen(fname, "r");

  if (!fin) {
    fprintf(stderr, "Error al abrir el archivo \"%s\".\n", fname);
    exit(EXIT_FAILURE);
  }

  fseek(fin, 0L, SEEK_END);
  *n = ftell(fin);
  fseek(fin, 0L, SEEK_SET);

  char *A = malloc(*n * sizeof(char));
  fread(A, sizeof(char), *n, fin);
  fclose(fin);
  return A;
}
