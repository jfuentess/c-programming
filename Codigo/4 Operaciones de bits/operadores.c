#include <stdlib.h>
#include <stdio.h>

#define BOLD "\e[1m"
#define WHITE "\e[7m"
#define BLUE "\e[44m"
#define NORMAL "\e[0m"

void int2bits(int x) {
  // Número de bits de un entero
  int num_bits = sizeof(int)*8;
  char rep[num_bits];
  int mask = 1;

  printf("%sRepresentación binaria de %s%d%s\n", BOLD, WHITE, x, NORMAL);

  // Cómputo de la representación binaria de x por medio de bit-shifting 
  for(int i=0; i < num_bits; i++, x >>=1)
    rep[i] = (char)(x & mask);

  // Impresión de índices
  for(int i=num_bits-1; i >= 0; i--)
    printf("%2d ", i);
  printf("\n");

  // Impresión de los bits
  for(int i=num_bits-1; i >= 0; i--)
    printf("%s%s%2d %s", BOLD, BLUE, rep[i], NORMAL);
  printf("\n\n");
}

int main() {

  printf("############################################################\n");
  printf("### Representación binaria utilizando operadores << y >> ###\n");
  printf("############################################################\n\n");

  int x;

  printf("Ingrese número: ");
  scanf("%d", &x);

  for(int i=0; i < 5; i++) {
    int2bits(x);
    x <<= 1;
    printf("\n");
  }


  printf("#####################################################\n");
  printf("### Otros operadores a nivel de bits: &, |, ^ y ~ ###\n");
  printf("#####################################################\n\n");
  int y = 15;
  int z = 203;

  int2bits(y);
  int2bits(z);

  printf("Operador NOT - complemento (~)\n");
  int2bits(~y);

  printf("Operador AND (&)\n");
  int2bits(y & z);

  printf("Operador OR (|)\n");
  int2bits(y | z);
  
  printf("Operador XOR (^)\n");
  int2bits(y ^ z);

  return 0;
}
