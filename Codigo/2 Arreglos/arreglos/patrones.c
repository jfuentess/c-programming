#include <stdio.h>
#include <stdlib.h>

/*
 * Problema: Búsqueda de patrones. Decidir si el string que aparece en la
 * variable 'patron' aparece en el string de la variable 'texto'
 */

int main(int argc, char **argv) {

  printf("############################\n");
  printf("### Búsqueda de patrones ###\n");
  printf("############################\n\n");

  
  char texto[170] = "En un lugar de la Mancha, de cuyo nombre no quiero acordarme, no ha mucho que vivia un hidalgo de los de lanza en astillero, adarga antigua, rocin flaco y galgo corredor.";

  char patron[8] = "de lanza";

  int cont = 0;
  for(int i=0; i < 163; i++) { // Texto
    cont = 0;
    // Comparamos las 8 letras del patrón
    for(int j = 0; j < 8; j++) {
      if(texto[i+j] == patron[j]) {
	cont++;
      }
    }
    // Si encontramos 8 coincidencias, entonces concluimos que el patrón fue
    // encontrado
    if(cont == 8)
      printf("Encontrado!!! (posición: %d)\n", i);
  }

  // Nota: en lugar de escribir explícitamente los valores 163 y 8 para el largo
  // del texto (menos el largo del patrón) y el largo del patrón, se usa la
  // función strlen(), la cual revisaremos más adelante.
  
  return 0;
}
