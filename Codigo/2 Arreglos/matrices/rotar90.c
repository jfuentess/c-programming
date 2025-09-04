// Rota una imagen RGB en 90 grados
// Compilación: gcc -o rotar90 rotar90.c

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

  printf("#########################################\n");
  printf("### Rotar una imagen RGB en 90 grados ###\n");
  printf("#########################################\n\n");

  unsigned char rotada_R[256][322] = {};
  unsigned char rotada_G[256][322] = {};
  unsigned char rotada_B[256][322] = {};
  
  // Generamos la imagen PNG dada por las matrices s_R, s_G y s_B
  escribir_imagen("small_mario.png", 322, 256, s_R, s_G, s_B);

  // Trasponemos la matriz
  for(int i=0; i < 322; i++) { // Filas
    for(int j=0; j < 256; j++) { // Columnas
      rotada_R[j][i] = s_R[i][j];
      rotada_G[j][i] = s_G[i][j];
      rotada_B[j][i] = s_B[i][j];
    }
  }      

  // Reflejamos las columnas
  for(int i=0; i < 322/2; i++) { // Columnas
    for(int j=0; j < 256; j++) { // Filas
      // Intercambiamos celdas
      unsigned char tmp = rotada_R[j][i];
      rotada_R[j][i] = rotada_R[j][322-i-1];
      rotada_R[j][322-i-1] = tmp;

      tmp = rotada_G[j][i];
      rotada_G[j][i] = rotada_G[j][322-i-1];
      rotada_G[j][322-i-1] = tmp;

      tmp = rotada_B[j][i];
      rotada_B[j][i] = rotada_B[j][322-i-1];
      rotada_B[j][322-i-1] = tmp;
    }
  }

  // Generamos la imagen PNG dada por las matrices rotadas
  escribir_imagen("small_mario_rotado.png", 256, 322, rotada_R, rotada_G, rotada_B);
  
  return 0;
}
