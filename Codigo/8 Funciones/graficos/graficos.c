#include "graficos.h"
#include <math.h>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define NORMAL "\e[0m"

char *colores[2] = {RED, GREEN};
char *simbolos[3] = {"░", "▒", "▓"};
int num_simbolos = 3;
int num_colores = 2;

int ancho_defecto = 2;

int max(int *A, int n) {
  if(n > 0) {
    
    int max_val = A[0];
    
    for(int i=1; i< n; i++)
      if(max_val < A[i])
	max_val = A[i];
    
    return max_val;
  }
  else {
    fprintf(stderr, "Error: Arreglo sin elementos\n");
    return -1;
  }
}

// Imprime el símbolo que representa al vacío
void print_vacio(int x) {
  for(int i=0; i < x; i++) {
    printf(".");
  }
}

// Imprime el símbolo 'c' x veces
void print_rep(int pos, int x) {
  int k = pos % num_simbolos;
  int v = pos % num_colores;

  for(int i=0; i < x; i++)
    printf("%s%s%s", colores[v], simbolos[k], NORMAL);
  
}

int num_digitos(int x) {
  if(x == 0)
    return 1;
  else
    return (int)floor(log10(x))+1;
}

void grafico_barra(int *A, int n, int ancho) {

  if(ancho <= 0) ancho = ancho_defecto;
  
  int limite = max(A, n);

  for(int linea=limite; linea >= 0; linea--){
    // Recorremos todos los elementos verificando que cumple la condición para
    // ser impreso
    for(int j =0; j<n; j++) {
      if(A[j] == linea) {
	
	int digitos = num_digitos(A[j]); // Calculamos el número de dígitos de un entero
	printf("%d", A[j]);
	print_vacio(ancho-digitos);
      }
      else if(A[j] > linea) {
	print_rep(j, ancho);
      }
      else {
	print_vacio(ancho);
      }
      printf(" ");
    }
    printf("\n");
  }
}
