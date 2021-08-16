/*
 * Este código muestra el uso de la estructura condicional switch-case por medio
 * de la implementación de un menú. Además, se muestra el uso de un ciclo
 * infinito implementado con while(1)
 *
 * Partiendo de la coordenada inicial (0,0), esta implementación permite
 * desplazar la coordenada actual en un plano infinito.
 *
 * NOTA: Queda como tarea limitar el plano a un tamaño fijo. En el caso de mover
 * la coordenada actual más allá del limite del plano, implementar un efecto
 * rebote.
 */

#include <stdio.h>

int main() {

  char op;

  // Coordenadas por defecto (0,0)
  int x = 0, y = 0;
  // Desplazamientos de las coordenadas X e Y
  int dx, dy;
  
  while(1) {
    printf("\nOpciones:\n");
    printf("\t a: Agregar desplazamiento de las coordenadas\n");
    printf("\t b: Imprimir coordenadas actuales\n");
    printf("\t c: Salir\n");
    
    printf("Ingrese opción: ");
    // La función scanf() por defecto agrega un símbolo representando el salto
    // de línea. Es por ello que necesitamos el espacio antes de %c
    scanf(" %c", &op);

    switch(op) {
      case 'a':
	printf("\n\tIngrese desplazamiento 'X Y' (x < 100, y < 100): ");
	scanf(" %d %d", &dx, &dy);

	x += dx; // x = x + dx
	y += dy; // y = y + dy	  

	break;
      case 'b':
	printf("\n\tCoordenadas actuales: (%d, %d)\n", x, y);
	break;
      case 'c':
	printf("\nSaliendo ...\n");
	return 0;
      default:
      	printf("Ingrese una opción válida\n");
      	break;
      }
  }
     
  return 0;
}
