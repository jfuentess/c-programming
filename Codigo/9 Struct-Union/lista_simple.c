#include <stdlib.h>
#include <stdio.h>

struct nodo {
   int valor;
   struct nodo *sig;
};

int main() {
   struct nodo nodo1; 
   struct nodo nodo2; 

   nodo1.valor=10;
   nodo1.sig = &nodo2;

   nodo2.valor=15;
   nodo2.sig = NULL;
   
   return 0;
}
