#include <stdio.h>

int main() {
  int num1 = 9; // Representación binaria: 1001
  int num2 = 5; // Representación binaria: 0101

  int res_and = num1 & num2; // Realiza AND bitwise
  int res_or = num1 | num2;  // Realiza OR bitwise
  int res_xor = num1 ^ num2; // Realiza XOR bitwise
  int res_not = ~num1;       // Realiza NOT bitwise

  printf("Resultado de AND bitwise: %d\n", res_and);
  printf("Resultado de OR bitwise: %d\n", res_or);
  printf("Resultado de XOR bitwise: %d\n", res_xor);
  printf("Resultado de NOT bitwise: %d\n", res_not);

  return 0;
}