#include <stdio.h>

int main() {
  int c1 = 4; // cateto 1
  int c2 = 3; // cateto 2
  int hp = 5; // hipotenusa
  
  // Verificamos si cumplen el teorema de Pitágoras
  if((c1*c1 + c2*c2) == hp*hp)
    printf("Se cumple el teorema de Pitágoras\n");
  
  return 0;
}

