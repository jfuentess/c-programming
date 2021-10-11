void int2bits(int x) {
  // Número de bits de un entero
  int num_bits = sizeof(int)*8;
  char rep[num_bits];
  int mask = 1;

  printf("\e[1mRepresentación binaria de \e[7m%d\e[0m\n", x);

  // Cómputo de la representación binaria de x por medio de bit-shifting 
  for(int i=0; i < num_bits; i++, x >>=1)
    rep[i] = (char)(x & mask);

  // Impresión de índices
  printf("\e[37m");
  for(int i=num_bits-1; i >= 0; i--)
    printf("%2d ", i);
  printf("\n\e[0m");

  // Impresión de los bits
  printf("\e[1m\e[44m");
  for(int i=num_bits-1; i >= 0; i--)
    printf("%2d ", rep[i]);
  printf("\e[0m\n");
}
