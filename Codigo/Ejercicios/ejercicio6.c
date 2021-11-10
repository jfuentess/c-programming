/*
 * Ejercicio 6
 *
 * En algunas oficinas del gobierno pagan horas extra a los burócratas, además
 * del salario correspondiente. Escriba un programa en C que permita calcular la
 * cantidad a pagar a un trabajador por concepto de horas extra trabajadas. Las
 * horas extra se pagan según la categorı́a a la que pertenece cada trabajador y
 * se calculan en función de la siguiente tabla. Cada trabajador puede tener
 * como máximo 30 horas extra, si tienen más, sólo se les pagarán las primeras
 * 30. Los trabajadores con categorı́a 4 o mayor a 4 no pueden recibir este
 * beneficio.
 *
 *     | Categorı́a trabajador | Valor hora extra |
 *     |----------------------|------------------|
 *     |          1           |    $20.000       |
 *     |          2           |    $23.000       |
 *     |          3           |    $25.000       |
 *
 *
 *  Criterio evaluación:
 *     - Test 1: 
 *          categoría 3 y 15 horas extras 
 *           salida: $375000
 *
 *     - Test 2: 
 *          categoría 1 y 40 horas extras 
 *           salida: $600000
 *
 *     - Test 3: 
 *          categoría 4 
 *           salida: Sólo los trabajadores de categorías 1, 2 y 3 reciben pago
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 */

#include <stdio.h>

int main() {

  // cat: Categoría del trabajador
  // nh: Número de horas extras
  int cat, nh;
    
  printf("Ingrese la categoría del trabajador (1, 2 o 3): ");
  scanf("%d", &cat);

  if(cat < 1) {
    printf("Categoría errónea\n");
    return 0; // Terminamos la ejecución
  }
  else if(cat > 3) {
    printf("Trabajadores con categoría superior a 3 no reciben este beneficio\n");
    return 0; // Terminamos la ejecución
  }
    
  printf("Ingrese la cantidad de horas extras: ");
  scanf("%d", &nh);

  // Máximo 30 horas extras por trabajador
  if(nh > 30)
    nh = 30;

  // Precio por hora extra
  int phe = 0;

  if(cat == 1) phe=20000;
  else if(cat == 2) phe=23000;
  else phe=25000; // Categoría 3

  printf("Total a pagar por %d horas extras de categoría %d: $%d\n", nh, cat, nh*phe);
  
  return 0;
}
