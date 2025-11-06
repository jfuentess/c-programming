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

// implementación recursiva
// retorna el índice del elemento x en el arreglo arr
// busca entre los índices low y high
int binary_search_r(int arr[], int low, int high, int x) {
  // Caso base: el elemento no se encuentra en el arreglo
  if (low > high) {
    return -1;
  }

  // Calcular el índice del elemento medio
  int mid = (low + high) / 2;

  // Si el elemento está en la primera mitad
  if (x < arr[mid]) {
    return binary_search_r(arr, low, mid - 1, x);
  }
  // Si el elemento está en la segunda mitad
  else if (x > arr[mid]) {
    return binary_search_r(arr, mid + 1, high, x);
  }
  // Si el elemento está en la mitad
  else {
    return mid;
  }
}

int main() {
  // Arreglo ordenado para binary search
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67};
  int n = 10;

  printf("Arreglo: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");

  // Probar binary search iterativo
  printf("=== Binary Search Iterativo ===\n");
  int x1 = 23;
  int resultado1 = binary_search_i(arr, n, x1);
  if (resultado1 != -1) {
    printf("Elemento %d encontrado en índice %d\n", x1, resultado1);
  } else {
    printf("Elemento %d no encontrado\n", x1);
  }

  int x2 = 50;
  int resultado2 = binary_search_i(arr, n, x2);
  if (resultado2 != -1) {
    printf("Elemento %d encontrado en índice %d\n", x2, resultado2);
  } else {
    printf("Elemento %d no encontrado\n", x2);
  }

  // Probar binary search recursivo
  printf("\n=== Binary Search Recursivo ===\n");
  int x3 = 23;
  int resultado3 = binary_search_r(arr, 0, n - 1, x3);
  if (resultado3 != -1) {
    printf("Elemento %d encontrado en índice %d\n", x3, resultado3);
  } else {
    printf("Elemento %d no encontrado\n", x3);
  }

  int x4 = 50;
  int resultado4 = binary_search_r(arr, 0, n - 1, x4);
  if (resultado4 != -1) {
    printf("Elemento %d encontrado en índice %d\n", x4, resultado4);
  } else {
    printf("Elemento %d no encontrado\n", x4);
  }

  // Probar potencia de 2
  printf("\n=== Potencia de 2 ===\n");
  int n_potencia = 5;
  printf("2^%d (iterativo) = %d\n", n_potencia, potencia2_i(n_potencia));
  printf("2^%d (recursivo) = %d\n", n_potencia, potencia2_r(n_potencia));

  return 0;
}
