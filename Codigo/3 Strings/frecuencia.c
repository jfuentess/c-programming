#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {

  printf("##########################################\n");
  printf("### Frecuencia de símbolos en un texto ###\n");
  printf("##########################################\n\n");
 
  char texto[242] = "";

  // Creamos el texto por medio de 3 concatenaciones
  // Discusión: strcat vs strncat ¿Qué opción es mejor?
  strcat(texto, "El Premio Turing es un premio de las Ciencias de la Computacion que es otorgado anualmente por la ACM. ");
  strcat(texto, "Rinde homenaje a Alan Turing y desde 2014 es patrocinado por Google. ");
  strcat(texto, "Los ultimos galardonados (2019) fueron Edwin Catmull y Prat Hanrahan.");


  // Arreglo para contar la frecuencia de los símbolos. Inicializamos todas las
  // entrada en cero 
  int frec[256] = {};

  int len = strlen(texto);

  for(int i=0; i < len; i++) {
    int v = texto[i];
    frec[v]++;
  }

  // Imprimimos la frecuencia de los símbolos que aparecen en el texto
  for(int i=0; i < 256; i++)
    if(frec[i])
      printf("símbolo '%c' (ASCII %d): %d\n", (char)i, i, frec[i]);

  // Código de Huffman
  return 0;
}
