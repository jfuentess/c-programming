#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union u_dato udato;
typedef struct s_dato sdato;

union u_dato {
  int d;
  float f;
  char c;
  char s[8];
};

struct s_dato {
  int d;
  float f;
  char c;
  char s[8];
};

void print_udato(udato v) {
  printf("\n[u] int: %d\n", v.d);
  printf("[u] float: %f\n", v.f);
  printf("[u] char: %c\n", v.c);
  printf("[u] string: %s\n", v.s);
  printf("\n");
}

void print_sdato(sdato v) {
  printf("\n[s] int: %d\n", v.d);
  printf("[s] float: %f\n", v.f);
  printf("[s] char: %c\n", v.c);
  printf("[s] string: %s\n", v.s);
  printf("\n");
}

int main() {
   udato var1;
   sdato var2;

   printf("sizeof(udato): %ld bytes\n", sizeof(udato));
   printf("sizeof(sdato): %ld bytes\n", sizeof(sdato));

   var1.f = 100.5;
   var2.f = 100.5;

   // Impresión de los valores luego de asignar el valor 100 al entero de la
   // union y struct
   print_udato(var1);
   print_sdato(var2);
   
   return 0;
}
