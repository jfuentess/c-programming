#include <stdio.h>

int main() {
  int x = 10; 
  int y = 5; 
  int z = x + y;

  printf("%d + %d = %d\n", x, y, z);
  printf("%d + %d = %d\n", z, y, x);
  
  int w = 7;
  int a;
  int b;

  a = w++; // 1) Asigna el valor de 'w' a la variable 'a'
           // 2) Incrementa el contenido de 'w' (w = w + 1)
  
  b = ++w; // 1) Incrementa el contenido de 'w' (w = w + 1)
           // 2) Asigna el valor de 'w' a la variable 'b'
           
  
  printf("w: %d\n", w);
  printf("a: %d\n", a);
  printf("b: %d\n", b);


  printf("Efecto de los paréntesis: 10 + 8 * (20 - 3) = %d\n", 10 + 8 * (20 - 3));
  printf("Efecto de los paréntesis: 10 + 8 * 20 - 3 = %d\n", 10 + 8 * 20 - 3);

  return 0;
}
