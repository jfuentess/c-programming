/*
 * Ejercicio 7
 *
 * Escriba un programa que pida dos números enteros n e y, e imprima el
 * resultado de las funciones f(1), f(2), f(3), ..., f(n), donde f(x) se define
 * de la siguiente forma: 
 *
 *     f(x) =     y^2 + 15,        si 0 < x <= 15 
 *                y^3 - y^2 + 12,  si 15 < x <= 30 
 *                4*y^3/y^2 + 8,   si 30 < x <= 60 
 *                0            ,   en otro caso 
 *
 *
 *  Criterio evaluación:
 *     - Test 1: n=10 e y=2
 *        salida: 19 19 19 19 19 19 19 19 19 19 
 *
 *     - Test 2: n=55 e y=5
 *        salida: 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 112 112 112 112
 *        112 112 112 112 112 112 112 112 112 112 112 28 28 28 28 28 28 28 28 28
 *        28 28 28 28 28 28 28 28 28 28 28 28 28 28 28 28
 *
 *     - Test 3: n=70 e y=1
 *        salida: 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 12 12 12 12 12 12
 *        12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12
 *        12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 0 0 0 0 0 0 0 0 0 0 
 *
 * 
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts

 */  

#include <stdio.h>

int main() {

  int n, y;

  printf("Ingrese n e y: ");
  scanf("%d%d", &n, &y);

  int val = 0;
  for(int x=1; x <= n; x++) {
    if(x <= 15)
      val = y*y + 15;
    else if(x <= 30)
      val = y*y*y - y*y + 12;
    else if(x <= 60)
      val = 4*y + 8;
    else
      val = 0;
    
    //    printf("f(%d) = %d\n", x, val);
    printf("%d ",val);
  }
  
  return 0;
}
