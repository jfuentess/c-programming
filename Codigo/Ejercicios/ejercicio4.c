/*
 * Ejercicio 4
 *
 * Escriba un programa que pida dos números enteros m y n, e imprima el
 * resultado de la combinatoria  de m y n
 *
 *
 *  Criterio evaluación:
 *     - Test 1: m=7 y n=5 (resultado: 21)
 *     - Test 2: m=10 y n=10 (resultado: 1)
 *     - Test 3: m=20 y n=2 (resultado: 190)
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 */

#include <stdio.h>

int main() {

  int n, m;
  int a = 1, b = 1;
    
  printf("Ingrese m y n: ");
  scanf("%d%d", &m, &n);

  // Comprobamos que los valores de entrada son válidos
  if(m < n) {
    printf("Error: m debe ser mayor o igual que n\n");
    return 0; // Terminamos la ejecución
  }

  // Posible solución
  for(int i=1; i <=n; i++) {
    a = a *  i;
    b = b * (m-i+1);
  }

  printf("Resultado: %d\n", b/a);
    
  return 0;
}
