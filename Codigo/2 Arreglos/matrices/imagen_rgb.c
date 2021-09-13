// Compilación: gcc -o imagen_rgb imagen_rgb.c

#include <stdlib.h>
#include <stdio.h>

// Archivo con varias declaraciones de matrices
#include "matrices.h"

// Este código fue obtenido desde https://github.com/miloyip/svpng
#include "svpng.inc"

// Función que sirve para escribir una imagen PNG a partir de 3 matrices RGB
void escribir_imagen(const char* nb, int f, int c, int R[f][c], int G[f][c],
		     int B[f][c]) {
    unsigned char rgb[f * c * 3], *p = rgb;
    unsigned x, y;

    // La imagen resultante tendrá el nombre dado por la variable 'nb'
    FILE *fp = fopen(nb, "wb");

    // Transformamos las 3 matrices en una arreglo unidimensional
    for (y = 0; y < f; y++)
        for (x = 0; x < c; x++) {
            *p++ = (unsigned char)R[y][x];    /* R */
            *p++ = (unsigned char)G[y][x];    /* G */
            *p++ = (unsigned char)B[y][x];    /* B */
        }
    // La función svpng() transforma las 3 matrices RGB en una imagen PNG 
    svpng(fp, c, f, rgb, 0);
    fclose(fp);
}

int main() {

  printf("#######################################\n");
  printf("### Matrices RGB (red, green, blue) ###\n");
  printf("#######################################\n\n");

  
  // Recorrido de una matriz de 40 filas y 32 columnas
  // La declaración de la matrix vs_R está en el archivo matrices.h
  for(int i=0; i < 40; i++) {
    for(int j=0; j < 32; j++)
      printf("%d ", vs_R[i][j]);
    printf("\n");
  }

  // Generamos la imagen PNG dada por las matrices s_R, s_G y s_B
  escribir_imagen("small_mario.png", 322, 256, s_R, s_G, s_B);


  int n = 600;

  int rand_R[n][n];
  int rand_G[n][n];
  int rand_B[n][n];
  
  for(int i=0; i < n; i++) { // Filas
    for(int j=0; j < n; j++) { // Columnas
      rand_R[i][j] = rand() % 256;
      rand_G[i][j] = rand() % 256;
      rand_B[i][j] = rand() % 256;
    }
  }

  // Generamos la imagen PNG dada por las matrices random rand_R, rand_G y
  // rand_B
  escribir_imagen("imagen_random.png", n, n, rand_R, rand_G, rand_B);
  
  return 0;
}
