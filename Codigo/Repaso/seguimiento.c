#include <stdio.h> 
#include <stdlib.h> 


void func(int a, int b, int *c, int *d) {
  int x=0;
  while(a >= b) {
    x++;
    a -= b;
  }

  *c = x;
  *d = a;
}

// ¿Qué hace la siguiente implementación?
int main(void) {

  int a, b, c=0, r=0;
  printf("Ingrese dos valores enteros: ");
  scanf("%d %d", &a, &b);

  func(a, b, &c, &r);
  printf("c: %d, r: %d\n", c, r);
  
  return EXIT_SUCCESS;
}
