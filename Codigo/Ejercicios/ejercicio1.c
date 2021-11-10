/*
 * Ejercicio 1
 *
 * Escriba un programa que pida un número entero n e imprima 'primo' si el
 * número es primo o 'compuesto' en caso contrario. (Nota: Basta con verificar
 * los números hasta la raíz cuadrada de n.)
 *
 *
 *  Criterio evaluación:
 *     - Test 1: n=10 (Compuesto)
 *     - Test 2: n=89 (Primo)
 *     - Test 3: n=9973 (Primo)
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 */

#include <stdio.h>
#include <math.h>

int main() {
  int n;
  printf("Ingrese un número: ");
  scanf("%d", &n);

  // Calculamos la raíz cuadrada de n. Debido a que la función sqrt() retorna un
  // tipo de dato double, lo convertiremos a un tipo de datos int. Esto causará
  // que sólo consideraremos la parte entera de la variable double.
  int sqrt_n = (int)sqrt(n);

  // Estrategia: Demostraremos que el número es compuesto. Si no podemos
  // demostrarlo, entonces el número será primo.
  // Nota: Podríamos iterar hasta n en lugar de sqrt_n, obteniendo un resultado
  // correcto. No obstante, es suficiente con recorrer hasta sqrt_n
  for(int i=2; i <= sqrt_n; i++) {
    int d = n/i; //parte entera de la división, sin decimales

    if(d*i == n) {
      printf("compuesto\n");
      return 0; // Terminos la ejecución
    }
  }

  printf("primo\n");

  return 0;
}
