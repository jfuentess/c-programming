#include <stdio.h> // Standard Input-Output
#include <stdlib.h> // Standard library

void agregar_conexion(int n, char M[n][n], int a, int b) {
  if(a < n && b < n)
    M[a][b] = 1;
  else
    printf("La celda no existe\n");
}

void eliminar_conexion(int n, char M[n][n]) {
  int a, b;
  printf("Ingrese la fila/columna de la conexión a eliminar: ");
  scanf("%d %d", &a, &b);

  if(a < n && b < n)
    if(M[a][b] == 0) // if(!M[a][b])
      printf("La conexión no existe\n");
    else
      M[a][b] = 0;
  else
    printf("La celda no existe\n");
}

// Retornar la cantidad de followers del usuario v
int contar_followers(int n, char M[n][n], int v) {
  int cnt = 0;

  if(v < n) {
    for(int i=0; i < n; i++)
      if(M[i][v] == 1)
	cnt++;
  }
  else
    printf("El ID %d ingresado no es válido\n", v);

  return cnt;
}

int * lista_followers(int n, char M[n][n], int v, int *nv) {
  int nf = contar_followers(n, M, v);

  //  int x[nf];
  int *x = malloc(nf * sizeof(int));

  // Obtener la lista de followers
  int k=0;
  if(v < n) {
    for(int i=0; i < n; i++)
      if(M[i][v] == 1) {
	x[k] = i;
	k++;
      }
  }
  else
    printf("El ID %d ingresado no es válido\n", v);
  
  return x;
}


// Imprimimos el estado actual de la matriz de adyacencia
void imprimir_matriz(int n, char M[n][n]) {
  printf("\nRed Social\n   ");
  for(int i=0; i < n; i++)
    printf("%2d ", i);
  printf("\n");

  for(int i=0; i < n; i++) {
    printf("%2d ", i);
    for(int j=0; j < n; j++)
      printf("%2d ", M[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main() {
  int n;
  printf("Ingrese el número de usuarios de la red social: ");
  scanf("%d", &n);

  char M[n][n];
  
  for(int i=0; i < n; i++)
    for(int j=0; j < n; j++) {
      // Simboliza que el usuario i y j no tienen una relación de amistad
      M[i][j] = 0; 
    }

  for(int i=0; i < 2*n; i++) {
    int a = rand() % n;
    int b = rand() % n;
    agregar_conexion(n, M, a, b);
  }
  
  imprimir_matriz(n, M);

  for(int i=0; i < n; i++) {
    printf("El usuario %d tiene %d vecinos\n", i, contar_followers(n, M, i));
  }

  return EXIT_SUCCESS;
}
