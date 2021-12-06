#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union dato {
  int d;
  float f;
  char c;
  char s[8];
};

void print_dato(union dato v) {
  printf("\n> int: %d\n", v.d);
  printf("> float: %f\n", v.f);
  printf("> char: %c\n", v.c);
  printf("> string: %s\n", v.s);
  printf("\n");
}

int main() {
   union dato var;
   printf("sizeof(var): %ld bytes\n", sizeof(var));

   // Impresión de los valores antes de inicializarlos
   print_dato(var);

   var.d = 100;
   // Impresión de los valores luego de asignar el valor 100 al entero de la Union
   print_dato(var);

   strcpy(var.s, "Enigma");
   // Impresión de los valores luego de copiar una palabra al string de la Union
   print_dato(var);
   
   return 0;
}
