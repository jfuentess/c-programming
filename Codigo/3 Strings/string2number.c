#include <stdio.h>
#include <stdlib.h> // atoi, atof, atol, atoll
 
int main(int argc, char *argv[]) {

  printf("#######################\n");
  printf("### String a número ###\n");
  printf("#######################\n\n");

  int n = atoi(argv[1]);
  printf("n: %d\n", n);
  
  char t1[] = "102 veces";
  char t2[] = "10.2";

  int n1 = atoi(t1); // Caracteres a enteros
  long n2 = atol(t1); // Caracteres a long
  long long n3 = atoll(t1);  // Caracteres a long long
  float n4 = atof(t2);  // Caracteres a número punto flotante

  printf("\nt1: \"%s\"\n", t1);
  printf("\t n1: %d, n2: %ld, n3: %lld\n", n1, n2, n3);

  printf("\nt2: \"%s\" -> %f\n", t2, n4);

  return 0;
}
