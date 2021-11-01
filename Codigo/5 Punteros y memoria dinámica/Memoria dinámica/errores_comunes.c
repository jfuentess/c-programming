#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("############################################\n");
  printf("### Errores comunes con memoria dinámica ###\n");
  printf("############################################\n\n");

  // Error 1
  int *x = malloc(10*sizeof(int));
  x = NULL;
  free(x);

  // Error 2
  int *y = malloc(10*sizeof(int));
  for(int i=0; i<10; i++)
    y[i] = i+1;
  
  free(y);
  y=NULL;
  
  printf("y[1]: %d\n", y[1]);
  
  
  return 1;
}
