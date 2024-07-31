/*
 * Problema: Propagación de valores mayores. En este problema, por cada celda de
 * la matriz, revisaremos los valores almacenados en sus celdas vecinas. Si uno
 * de los vecinos tiene un valor mayor, entonces dicho valor mayor será copiado
 * en la celda actual. Para visualizar mejor los cambios, usaremos valores entre
 * 0 y 255, para luego generar una imagen RGB.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

  printf("######################################\n");
  printf("### Propagación de valores mayores ###\n");
  printf("######################################\n\n");

  unsigned char rand_R[322][256];
  unsigned char rand_G[322][256];
  unsigned char rand_B[322][256];

  // Imagen mayoritariamente verde
  for(int i=0; i < 322; i++) { // Filas
    for(int j=0; j < 256; j++) { // Columnas
      rand_R[i][j] = rand() % 25; // 0-24
      rand_G[i][j] = rand() % 150; // 0-149
      rand_B[i][j] = rand() % 25; // 0-24
    }
  }

  // Rectángulo rojo
  for(int i=100; i < 122; i++) { // Filas
    for(int j=50; j < 90; j++) { // Columnas
      rand_R[i][j] = 255;
      rand_G[i][j] = 0;
      rand_B[i][j] = 0;
    }
  }

  // Rectángulo azul
  for(int i=130; i < 200; i++) { // Filas
    for(int j=100; j < 180; j++) { // Columnas
      rand_R[i][j] = 0;
      rand_G[i][j] = 0;
      rand_B[i][j] = 255;
    }
  }

  // Rectángulo negro
  for(int i=100; i < 122; i++) { // Filas
    for(int j=220; j < 256; j++) { // Columnas
      rand_R[i][j] = 0;
      rand_G[i][j] = 0;
      rand_B[i][j] = 0;
    }
  }

  // Rectángulo blanco
  for(int i=250; i < 310; i++) { // Filas
    for(int j=50; j < 80; j++) { // Columnas
      rand_R[i][j] = 255;
      rand_G[i][j] = 255;
      rand_B[i][j] = 255;
    }
  }


  // Rectángulo rosado
  for(int i=30; i < 50; i++) { // Filas
    for(int j=100; j < 150; j++) { // Columnas
      rand_R[i][j] = 255;
      rand_G[i][j] = 0;
      rand_B[i][j] = 150;
    }
  }

  // Generamos una imagen inicial
  escribir_imagen("nueva_imagen.png", 322, 256, rand_R, rand_G, rand_B);


  // Utilizamos una imagen RGB de copia para guardar valores temporales
  unsigned char copy_R[322][256];
  unsigned char copy_G[322][256];
  unsigned char copy_B[322][256];
  

  while(1) {
    for(int i=0; i<322; i++) { // Filas
      for(int j=0; j<256; j++) { // Columnas
	unsigned char max_R = 0;
	unsigned char max_G = 0;
	unsigned char max_B = 0;
	
	// Vecino de arriba
	if(i-1 >= 0) {
	  if(max_R < rand_R[i-1][j]) max_R = rand_R[i-1][j]; 
	  if(max_G < rand_G[i-1][j]) max_G = rand_G[i-1][j]; 
	  if(max_B < rand_B[i-1][j]) max_B = rand_B[i-1][j]; 
	}
	// Vecino de abajo
	if(i+1 < 322) {
	  if(max_R < rand_R[i+1][j]) max_R = rand_R[i+1][j]; 
	  if(max_G < rand_G[i+1][j]) max_G = rand_G[i+1][j]; 
	  if(max_B < rand_B[i+1][j]) max_B = rand_B[i+1][j]; 
	}
      
	// Vecino de la izquierda
	if(j-1 >= 0) {
	  if(max_R < rand_R[i][j-1]) max_R = rand_R[i][j-1]; 
	  if(max_G < rand_G[i][j-1]) max_G = rand_G[i][j-1]; 
	  if(max_B < rand_B[i][j-1]) max_B = rand_B[i][j-1]; 
	}

	// Vecino de la derecha
	if(j+1 < 256) {
	  if(max_R < rand_R[i][j+1]) max_R = rand_R[i][j+1]; 
	  if(max_G < rand_G[i][j+1]) max_G = rand_G[i][j+1]; 
	  if(max_B < rand_B[i][j+1]) max_B = rand_B[i][j+1]; 
	}

      
	if(rand_R[i][j] < max_R) copy_R[i][j] = max_R;
	else copy_R[i][j] = rand_R[i][j];

	if(rand_G[i][j] < max_G) copy_G[i][j] = max_G;
	else copy_G[i][j] = rand_G[i][j];

	if(rand_B[i][j] < max_B) copy_B[i][j] = max_B;
	else copy_B[i][j] = rand_B[i][j];

      }
    }

    for(int i=0; i<322; i++) { // Filas
      for(int j=0; j<256; j++) { // Columnas
	rand_R[i][j] = copy_R[i][j];
	rand_G[i][j] = copy_G[i][j];
	rand_B[i][j] = copy_B[i][j];
      }
    }

    // Sobre-escribimos la imagen creada inicialmente luego de propagar valores
    escribir_imagen("nueva_imagen.png", 322, 256, rand_R, rand_G, rand_B);

    sleep(1); // Detiene la ejecución 1 segundo
  }
  
 
  
  return 0;
}
