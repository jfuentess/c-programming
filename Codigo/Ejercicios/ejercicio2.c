/*
 * Ejercicio 2
 *
 * Observe el siguiente patrón de impresión de 8 niveles. Escriba un programa
 * que pida un número entero n e imprima el mismo patrón on n niveles.  
 *
 *   #
 *   ++
 *   ###
 *   ++++
 *   #####
 *   ++++++
 *   #######
 *   ++++++++
 *
 *  Criterio evaluación:
 *     - Test 1: n=0
 *     - Test 2: n=8
 *     - Test 3: n=15
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
  */  

#include <stdio.h>

int main() {

  int n;
  printf("Ingrese n: ");
  scanf("%d", &n);

  for(int i=1; i <= n; i++) {
    for(int j=0; j < i; j++) {
      if(i%2 == 0) // i es par
	printf("+");
      else // i es impar
	printf("#");
    }
    printf("\n");
  }
  
  return 0;
}
