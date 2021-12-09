#include <stdlib.h>
#include <stdio.h>

typedef struct _tuberia tuberia;

struct _tuberia {
  int f; // Flujo actual
  int c; // Capacidad máxima
};

// Actualiza el flujo actual y máximo de la tubería entre los puntos i, j,
// f: flujo actual de la tubería
// c: capacidad máxima de la tubería
void actualizar_tuberia(int n, tuberia R[n][n], int i, int j, int f, int c) {

  // Tarea pendiente: Validar los parámetros de entrada. Por ejemplo, ¿qué pasa
  // si f > c?

  // El flujo se mueve tanto desde i a j como de j a i
  R[i][j].f = f; 
  R[i][j].c = c; 

  R[j][i].f = f; 
  R[j][i].c = c; 
}

// Imprimimos el estado actual de la matriz de adyacencia
void imprimir_matriz(int n, tuberia R[n][n]) {
  printf("\n\t");
  for(int i=0; i < n; i++)
    printf("%d\t", i);
  printf("\n");

  for(int i=0; i < n; i++) {
    printf("%d\t", i);
    for(int j=0; j < n; j++) {
      if(R[i][j].c > 0)
	printf("%d/%d\t", R[i][j].f, R[i][j].c);
      else
	printf("-/-\t");
    }
    printf("\n");
  }

}

int main() {
  int n = 9;
  tuberia R[n][n]; // Se guarda en el stack

  // Inicializamos la matriz de tuberías
  for(int i=0; i < n; i++)
    for(int j=0; j < n; j++) {
      R[i][j].f = 0; 
      R[i][j].c = 0; 
    }
  
  imprimir_matriz(n, R);

  actualizar_tuberia(n, R, 0, 1, 1, 3);
  actualizar_tuberia(n, R, 0, 5, 5, 5);
  actualizar_tuberia(n, R, 1, 2, 4, 4);
  actualizar_tuberia(n, R, 1, 4, 5, 9);
  actualizar_tuberia(n, R, 2, 3, 0, 2);
  actualizar_tuberia(n, R, 2, 4, 3, 4);
  actualizar_tuberia(n, R, 3, 4, 1, 3);
  actualizar_tuberia(n, R, 3, 7, 2, 9);
  actualizar_tuberia(n, R, 4, 5, 3, 5);
  actualizar_tuberia(n, R, 4, 6, 2, 4);
  actualizar_tuberia(n, R, 4, 7, 4, 5);
  actualizar_tuberia(n, R, 5, 6, 2, 7);
  actualizar_tuberia(n, R, 6, 7, 3, 3);
  actualizar_tuberia(n, R, 7, 8, 0, 3);

  imprimir_matriz(n, R);

  return EXIT_SUCCESS;  
}
