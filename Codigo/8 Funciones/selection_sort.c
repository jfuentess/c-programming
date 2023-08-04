#include "utils.h"

int main() {

  int n=0;
  printf("Ingrese el largo del arreglo: ");
  scanf("%d", &n);

  int *arr = malloc(n*sizeof(int));

  fill_array(arr, n, 10, 30);

  print_array(arr, n);
  for(int i=0; i < n; i++) {
    int min_id = min_pos_range(arr, i, n);
    // Opción 1 para swap
    swap(&arr[i], &arr[min_id]);

    /* // Opción 2 para swap
       swap(arr + i, arr + min_id); */
  }
  print_array(arr, n);

  return EXIT_SUCCESS;
}
