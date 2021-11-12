#include <stdio.h>
#include <stdlib.h>

/* Función recursiva que implementa el cálculo del factorial de n */
int factorial(int n) {
   if(n == 1) return 1;
   return n * factorial(n-1);
}

int main() {
   int n;
   printf("Ingrese n: ");
   scanf("%d", &n);

   printf("El factorial de %d "
          "es %d\n", n, factorial(n));
   
   return EXIT_SUCCESS;
}
