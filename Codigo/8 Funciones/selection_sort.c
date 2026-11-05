#include "utils.h"

int main() {

  int n=0;
  printf("Ingrese el largo del arreglo: ");
  scanf("%d", &n);

  int *arr = malloc(n*sizeof(int));

  fill_array(arr, n, 10, 30);

  print_array(arr, n);

  ssort(arr, 10, 15);
  
  print_array(arr, n);

  return EXIT_SUCCESS;
}
