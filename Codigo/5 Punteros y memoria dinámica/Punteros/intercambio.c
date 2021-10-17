#include <stdio.h>

// Paso de parámetros por valor
void intercambio1(int a, int b){
  int tmp = a;
  a = b;
  b = tmp;

  printf("[En la función] Los valores de a y b son: %d y %d resp.\n", a, b);

}

// Paso de parámetros por referencia
void intercambio2(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
  printf("[En la función] Los valores de a y b son: %d y %d resp.\n", *a, *b);
}

int main() {
  int a, b;

  printf("Inserte el valor de a: ");
  scanf("%d", &a);
  printf("Inserte el valor de b: ");
  scanf(" %d", &b);

  printf("Los valores de a y b son: %d y %d resp.\n", a, b);

  intercambio1(a, b);
  printf("[Intercambio 1] Los valores de a y b son: %d y %d resp.\n", a, b);

  intercambio2(&a, &b);
  printf("[Intercambio 2] Los valores de a y b son: %d y %d resp.\n", a, b);

  return 1;
}
