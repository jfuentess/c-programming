/* Pares e impares.
 * El programa, al recibir como datos n números enteros, obtiene la suma de los
 * números pares y calcula el promedio de los impares.
 *
 * NOTA: Este código genera un error si sólo se ingresar números pares. Queda
 *como tarea de los alumnos encontrar y solucionar el error
 */

#include <stdio.h>

void main() {
  int i, n, num, spa = 0, sim = 0, cim = 0;
    
  printf("Ingrese el número de datos que se van a procesar: ");
  scanf("%d", &n);
  if (n > 0) {
    for (i=1; i <= n; i++) {
	printf("\nIngrese el número %d: ", i);
	scanf("%d", &num);
	if (num != 0)
	  // Para saber si un número x es par/impar, se pueden usar las
	  // condiciones x%2==0 o pow(-1, num) > 0 
	  if (num % 2 == 0)
	    spa = spa + num;
	  else {
	    sim = sim + num;
	    cim++;
	  }
    }
    printf("\n La suma de los números pares es: %d\n", spa);
    if(cim > 0)
      printf(" El promedio de números impares es: %.2f\n", (float)(sim / cim));
    else
      printf("No ingresaron números impares\n");
  }
  else
    printf("\n El valor de N es incorrecto\n");
}
