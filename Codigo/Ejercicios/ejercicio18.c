/*
 * Pregunta 18
 *
 * Escriba una función recursiva que implemente la función itoa: Convertir un
 * entero en una cadena de caracteres la cual estará conformada por los dı́gitos
 * que conforman dicho número. 
 *
 * Por ejemplo, dado el entero 4570, la implementación de la función recursiva
 * debe generar la cadena "4570" 
 *
 *  Criterio evaluación:
 *     - Test 1: n=0
 *       Resultado: "0" 
 *
 *     - Test 2: n=123456
 *       Resultado: "123456" 
 *
 *     - Test 3: n=00123
 *       Resultado: "123" 
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Invertimos la cadena de caracteres s
void invertir(char s[]) {
  // Cantidad de símbolos de la cadena
  int l = strlen(s);

  for(int i=0; i < l/2; i++) {
    char aux = s[i];
    s[i] = s[l-i-1];
    s[l-i-1] = aux;
  }
}

void itoa(int n, char s[], int i) {
  // Caso base 1: el número ingresado originalmente es 0
  if(n == 0 && i==0) {
    s[i] = '0';
    s[i+1] = '\0';
    return;
  }
  // Caso base 2: El número ingresado originalmente es mayor a 0, pero luego de
  // varias llamadas recursivas, dicho número llega a cero
  else if(n==0) {
    s[i] = '\0';
    return;
  }
  
  itoa(n/10, s, i+1);
  s[i] = (n%10) + '0';
}

int main(int argc, char **argv) {
  int n;
  char s[100];
  
  printf("Ingrese el número a convertir: ");
  scanf("%d", &n);

  // La función itoa retorna la cadena de caracteres que representa al número
  // n. Visualmente, dicha cadena aparece ordenada de derecha a izquierda. Para
  // corregirlo, agregarmos la función invertir, la cual invierte el orden de la cadena.
  itoa(n, s, 0);
  invertir(s);
  
  printf("String resultante: \"%s\"\n", s);
  
  return EXIT_SUCCESS;
}
