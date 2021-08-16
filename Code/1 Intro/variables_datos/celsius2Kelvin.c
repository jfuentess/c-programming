#include <stdio.h>

#define KV 273.15

/* Proceso de compilación:

    Preprocesado: gcc -E celsius2Kelvin.c -o celsius2Kelvin.pp
    Compilación: gcc -S celsius2Kelvin.c -o celsius2Kelvin.s
    Ensamblado: gcc -c celsius2Kelvin.c
    Enlazado (opt 1): gcc -o celsius2Kelvin celsius2Kelvin.o
    Enlazado (opt 2): gcc -static -o celsius2Kelvin celsius2Kelvin.o

    Todo en uno: gcc -o celsius2Kelvin celsius2Kelvin.c
*/

void main() {
  // Temperatura en Celsius
  float c = 10;

  // Temperatura en Kelvin
  float k = c + KV;

  printf("%f °C -> %f °K\n", c, k);
}
