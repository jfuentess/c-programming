/*
 * Ejercicio 3
 *
 * Observe el siguiente patrón de impresión de 8 niveles. Escriba un programa
 * que pida un número entero n e imprima el mismo patrón on n niveles.  
 *
 *   # ########
 *   ++ +++++++
 *   ### ######
 *   ++++ +++++
 *   ##### ####
 *   ++++++ +++
 *   ####### ##
 *   ++++++++ +
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


  // Este ejercicio es similar al ejercicio 4. La principal diferencia es que
  // cada línea se divide en tres partes. Para la i-ésima línea, las 3 partes
  // están conformadas de la siguiente manera:
  //  - Parte 1: i símbolos + o #, dependiendo si i es par o impar
  //  - Parte 2: Un espacio en blanco
  //  - Parte 3: n-i+1 símbolos + o #, dependiendo si i es par o impar
  for(int i=1; i <= n; i++) {

    // Parte 1
    for(int j=0; j < i; j++) {
      if(i%2 == 0) // i es par
	printf("+");
      else // i es impar
	printf("#");
    }

    // Parte 2
    printf(" ");
    
    // Parte 3
    for(int j=0; j < n-i+1; j++) {
      if(i%2 == 0) // i es par
	printf("+");
      else // i es impar
	printf("#");
    }
    
    printf("\n");
  }
  
  return 0;
}
