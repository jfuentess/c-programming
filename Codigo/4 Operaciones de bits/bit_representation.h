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
