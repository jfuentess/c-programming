#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Este código fue obtenido desde https://github.com/miloyip/svpng
#include "svpng.inc"

// Función que sirve para escribir una imagen PNG a partir de 3 matrices RGB
void escribir_imagen(const char* nb, int f, int c, unsigned char** R, unsigned char** G,
		     unsigned char** B) {
    unsigned char rgb[f * c * 3], *p = rgb;
    unsigned x, y;

    // La imagen resultante tendrá el nombre dado por la variable 'nb'
    FILE *fp = fopen(nb, "wb");

    // Transformamos las 3 matrices en una arreglo unidimensional
    for (y = 0; y < f; y++)
        for (x = 0; x < c; x++) {
            *p++ = R[y][x];    /* R */
            *p++ = G[y][x];    /* G */
            *p++ = B[y][x];    /* B */
        }
    // La función svpng() transforma las 3 matrices RGB en una imagen PNG 
    svpng(fp, c, f, rgb, 0);
    fclose(fp);
}


int main(int argc, char** argv) {

  printf("########################################################\n");
  printf("###    Lee una imagen RGB y genera una imagen PNG    ###\n");
  printf("### (Usar en conjunto al script get_RGB_matrices.py) ###\n");
  printf("########################################################\n\n");

  if(argc != 2) {
    fprintf(stderr, "Uso: %s <archivo .rgb>\n", argv[0]);
    exit(1);
  }
  
  char *archivo_rgb = argv[1];
  
  // Abrimos un stream para guardar el arreglo serializado
  FILE *fp = fopen(archivo_rgb, "r");

  // Escribimos el arreglo al archivo
  int filas, cols;
  fread(&filas, sizeof(int), 1, fp);
  fread(&cols, sizeof(int), 1, fp);

  unsigned char **img_R = malloc(filas*sizeof(unsigned char *));
  unsigned char **img_G = malloc(filas*sizeof(unsigned char *));
  unsigned char **img_B = malloc(filas*sizeof(unsigned char *));
  
  for(int i=0; i < filas; i++) {
    img_R[i] = malloc(cols*sizeof(unsigned char));
    img_G[i] = malloc(cols*sizeof(unsigned char));
    img_B[i] = malloc(cols*sizeof(unsigned char));
  }

  for(int i=0; i < filas; i++)
    for(int j=0; j < cols; j++)
      fread(&img_R[i][j], sizeof(unsigned char), 1, fp);

  for(int i=0; i < filas; i++)
    for(int j=0; j < cols; j++)
      fread(&img_G[i][j], sizeof(unsigned char), 1, fp);

  for(int i=0; i < filas; i++)
    for(int j=0; j < cols; j++)
      fread(&img_B[i][j], sizeof(unsigned char), 1, fp);
  
  // Cerramos el stream
  fclose(fp);

  escribir_imagen("nueva_salida.png", filas, cols, img_R, img_G, img_B);
  
  return 0;

}
