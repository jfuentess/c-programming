#include <stdio.h>

// Llamadas recursivas infinitas
void mi_funcion() {
  printf("Hola\n");
  mi_funcion();
}

// Condición de salida
void mi_funcion2(int n) {

  if (n == 0) {
    return;
  }

  printf("Hola\n");
  mi_funcion2(n - 1);
}

// Función que retorna la n-ésima potencia de 2

// implementación recursiva
int potencia2_r(int n) {
  if (n == 0) {
    return 1;
  } else {
    return 2 * potencia2_r(n - 1);
  }
}

// implementación iterativa
int potencia2_i(int n) {
  int potencia = 1;
  for (int i = 0; i < n; i++) {
    potencia *= 2;
  }
  return potencia;
}

// Binary search

// implementación iterativa
// retorna el índice del elemento x en el arreglo arr de tamaño n
int binary_search_i(int arr[], int n, int x) {
  int low = 0;
  int high = n - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (x < arr[mid]) { // si el elemento está en la primera mitad
      high = mid - 1;   // se continua la búsqueda en la primera mitad

    } else if (x > arr[mid]) { // si el elemento está en la segunda mitad
      low = mid + 1;           // se continua la búsqueda en la segunda mitad

    } else {      // si el elemento está en la mitad
      return mid; // se retorna el índice
    }
  }

  return -1;
}