/*
 * Ejercicio 5
 *
 * Escriba un programa que pida 3 coordenadas (x, y) e imprima "contenido" si la
 * tercera coordenada está contenida en el rectángulo delimitado por las
 * primeras dos coordenadas. En caso contrario, imprima "no contenido" 
 *
 *  Criterio evaluación:
 *     - Test 1: 
 *         2 10
 *         6 1
 *         5 7
 *         resultado: contenido
 *
 *     - Test 2: 
 *         1 1
 *         50 50
 *         0 0
 *         resultado: no contenido
 *
 *     - Test 3: 
 *         1 1
 *         50 50
 *         25 55
 *         resultado: no contenido
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 */

#include <stdio.h>

int main() {

  int x1, y1; // Coordenada 1
  int x2, y2; // Coordenada 2
  int x3, y3; // Coordenada 3
    
  printf("Ingrese la primera coordenada: ");
  scanf("%d%d", &x1, &y1);
  printf("Ingrese la segunda coordenada: ");
  scanf("%d%d", &x2, &y2);
  printf("Ingrese la tercera coordenada: ");
  scanf("%d%d", &x3, &y3);

  // Para esta solución propuesta usaremos dos variables de estado. La variable
  // estadoX indica que la tercera coordenada está contenida entre las otras dos
  // en el eje X. De manera similar, estadoY indica que la tercera coordenada
  // está contenida entre las otras dos en el eje Y. De esta manera, para que
  // la tercera coordenada esté completamente contenida, debe estar contenida
  // tanto en el eje X como en el eje Y 
  char estadoX = 0; // Por defecto, asumimos que no está contenida en el eje X
  char estadoY = 0; // Por defecto, asumimos que no está contenida en el eje Y

  if((x1 <= x3 && x3 <= x2) || (x2 <= x3 && x3 <= x1))
    estadoX = 1;
  
  if((y1 <= y3 && y3 <= y2) || (y2 <= y3 && y3 <= y1))
    estadoY = 1;


  if(estadoX == 1 && estadoY == 1)
    printf("contenido\n");
  else
    printf("no contenido\n");
  
  return 0;
}
