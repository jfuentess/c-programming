// Compilación: gcc -o escala_grises escala_grises.c

#include <stdlib.h>
#include <stdio.h>

// Archivo con varias declaraciones de matrices
#include "matrices.h"

// Este código fue obtenido desde https://github.com/miloyip/svpng
#include "svpng.inc"

// Función que sirve para escribir una imagen PNG a partir de 3 matrices RGB
void escribir_imagen(const char* nb, int f, int c, unsigned char R[f][c], unsigned char G[f][c],
		     unsigned char B[f][c]) {
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

int main() {

  printf("##########################################################\n");
  printf("### Calcular promedio de 3 matrices (escala de grises) ###\n");
  printf("##########################################################\n\n");

  // Generamos la imagen PNG dada por las matrices s_R, s_G y s_B
  escribir_imagen("small_mario.png", 322, 256, s_R, s_G, s_B);

  // Cálculo del promedio de 3 matrices
  unsigned char prom[322][256];
  for(int i=0; i < 322; i++) { // Filas
    for(int j=0; j < 256; j++) { // Columnas
      prom[i][j] = (s_R[i][j]+s_G[i][j]+s_B[i][j]) / 3;
    }
  }

  // Generamos la imagen PNG dada por las matrices s_R, s_G y s_B
  escribir_imagen("small_mario_gris.png", 322, 256, prom, prom, prom);
  //  escribir_imagen("small_mario_gris.png", 322, 256, s_R, s_R, s_R);
  
  return 0;
}
