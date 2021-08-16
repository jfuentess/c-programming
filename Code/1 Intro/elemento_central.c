#include <stdio.h>

int main() {

  int a;
  int b;

  // Imprimir en la consola/pantalla
  printf("Ingresa el valor de a: ");
  // Leer desde la consola/pantalla
  scanf("%d", &a); 
  
  printf("Ingresa el valor de b: ");
  scanf("%d", &b);

  int c = (a+b)/2;

  // paso 1: int tmp = a+b
  // paso 2: tmp = tmp / 2
  // paso 3: asignar el valor a c=tmp
  
  printf("Valor central: %d\n", c);

  /*
    Preguntas para reflexionar
    - ¿Qué ocurre si ingresamos a=2147483648 y b=100?
    - ¿Conviene usar int o unsigned int como tipo de datos para a, b y c?
    - ¿La operación (a+b)/2 es la mejor manera de obtener el elemento central?
   */
  
  return 0;
}
