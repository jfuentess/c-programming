#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   int *x;

  printf("######################\n");
  printf("### calloc/realloc ###\n");
  printf("######################\n\n");
  
   /* Reserva inicial de memoria */
   x = (int *) calloc(15, sizeof(int));

   printf("x(%p): ", x);
   for(int i=0; i < 15; i++)
     printf("%d ", x[i]);
   printf("\n");

   /* Use de realloc */
   x = realloc(x, 20*sizeof(int));
   for(int i=15; i < 20; i++)
     x[i] = i;

   printf("x(%p): ", x);
   for(int i=0; i < 20; i++)
     printf("%d ", x[i]);
   printf("\n");

   free(x);
   
   return 0;
}
