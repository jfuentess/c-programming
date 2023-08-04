#include <stdio.h>

// Linux: ulimit -a
int main() {

  printf("######################\n");
  printf("### Stack overflow ###\n");
  printf("######################\n\n");

  int n = 0;
  printf("Ingrese el largo del arreglo a declarar: ");
  scanf("%d", &n);

  int arr[n];
  
  printf("Se declaró un arreglo de %d enteros (%ld bytes)\n", n, sizeof(arr));

  return 1;
}
