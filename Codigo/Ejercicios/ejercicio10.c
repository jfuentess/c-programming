/*
 * Ejercicio 10
 *
 * Escriba un programa que pida una cadena de caracteres y que reporte la
 * cantidad de caracteres en mayúscula, minúscula, dı́gitos y espacios. Note que
 * la cadena a ingresar debe permitir espacios.
 * 
 *  Criterio evaluación:
 *     - Test 1: El origen del Universo
 *       Cantidad de letras mayúsculas: 2
 *       Cantidad de letras minúsculas: 17
 *       Cantidad de espacios: 3
 *       Cantidad de dígitos: 0
 *
 *     - Test 2: 2001 Odisea en el espacio
 *       Cantidad de letras mayúsculas: 1
 *       Cantidad de letras minúsculas: 16
 *       Cantidad de espacios: 4
 *       Cantidad de dígitos: 4
 *
 *     - Test 3: Programacion 2020-1
 *       Cantidad de letras mayúsculas: 1
 *       Cantidad de letras minúsculas: 11
 *       Cantidad de espacios: 1
 *       Cantidad de dígitos: 5
 *
 *  - Código ordenado (indentado y con comentarios explicativos): +0.2 pts
 *  - 3 tests correctos: +0.8 pts
 *  - 2 tests correctos: +0.55 pts
 *  - 1 test correcto: +0.3 pts
 *  - 0 test correctos: +0 pts
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Contiene las funciones isdigit(), islower(), isupper()

int main(int argc, char **argv) {

  // Arreglo de chars de máximo 100 caracteres
  char cadena[100];

  printf("Ingrese una cadena de caracteres: ");
  scanf("%[^\n]s", cadena);

  int n = strlen(cadena);
  int minus = 0, mayus = 0, dig = 0, espacio = 0;

  for(int i=0; i < n; i++) {
    if(isdigit(cadena[i])) dig++;
    else if(islower(cadena[i])) minus++;
    else if(isupper(cadena[i])) mayus++;
    else if(cadena[i] == ' ') espacio++;
  }

  printf("Cantidad de letras mayúsculas: %d\n", mayus);
  printf("Cantidad de letras minúsculas: %d\n", minus);
  printf("Cantidad de espacios: %d\n", espacio);
  printf("Cantidad de dígitos: %d\n", dig);
    
  return EXIT_SUCCESS;
}
