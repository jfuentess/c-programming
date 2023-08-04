#include <stdio.h>
#include <stdlib.h>

unsigned int num_bytes = 0;

/* Función recursiva sin caso base (!!!)
   Esto causará un stackoverflow debido a una cantidad no controlada de
   llamadas recursivas.
 */
void funcionX(const int n, int i) {
  char arreglo[n];
  num_bytes += n;
  i++;
  printf("LLamada %d: %d bytes\n", i, num_bytes);
  funcionX(n, i);
}

int main() {
   int n;
   printf("Ingrese la cantidad de bytes a pedir por llamada: ");
   scanf("%d", &n);

   funcionX(n, 0);
   
   return EXIT_SUCCESS;
}
