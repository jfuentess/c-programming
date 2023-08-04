#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Uso de typedef
typedef unsigned short uint16;
typedef unsigned long long uint64;
typedef struct punto pt;

// Estructura que representa un punto en el espacio
struct punto {
  int x;
  int y;
};

// Estructura que representa un triángulo
struct triangulo {
  struct punto p1;
  struct punto p2;
  struct punto p3;
};

// Estructura que representa un cuadrilátero
struct cuadrilatero {
  struct punto p1;
  struct punto p2;
  struct punto p3;
  struct punto p4;
};

// Estructura que representa un polígono (generalización)
struct poligono {
  int n; // Cantidad de lados
  struct punto *pts;
};

// Creación de un triángulo pasando la estructura por parámetro
void crear_triangulo(struct triangulo * t) {
  int x, y;
  printf("Creación de un triángulo\n");
  
  printf("\t Ingrese las coordenadas del primero punto: ");
  scanf("%d %d", &x, &y);
  t->p1.x = x;
  t->p1.y = y;
  
  printf("\t Ingrese las coordenadas del segundo punto: ");
  scanf("%d %d", &x, &y);
  t->p2.x = x;
  t->p2.y = y;

  printf("\t Ingrese las coordenadas del tercer punto: ");
  scanf("%d %d", &x, &y);
  t->p3.x = x;
  t->p3.y = y;
}

// Creación de un cuadrilátero reservando memoria en el heap (malloc) y
// retornando la estructura
struct cuadrilatero * crear_cuadrilatero() {
  int x, y;
  struct cuadrilatero * c = malloc(sizeof(struct cuadrilatero));
  
  printf("Creación de un cuadrilátero\n");
  
  printf("\t Ingrese las coordenadas del primero punto: ");
  scanf("%d %d", &x, &y);
  c->p1.x = x;
  c->p1.y = y;
  
  printf("\t Ingrese las coordenadas del segundo punto: ");
  scanf("%d %d", &x, &y);
  c->p2.x = x;
  c->p2.y = y;

  printf("\t Ingrese las coordenadas del tercer punto: ");
  scanf("%d %d", &x, &y);
  c->p3.x = x;
  c->p3.y = y;

  printf("\t Ingrese las coordenadas del cuarto punto: ");
  scanf("%d %d", &x, &y);
  c->p4.x = x;
  c->p4.y = y;

  return c;
}

// Creación de un polígono reservando memoria en el heap (malloc) y
// retornando la estructura
struct poligono * crear_poligono() {
  int x, y, n;
  struct poligono *p = malloc(sizeof(struct poligono));

  printf("Ingrese la cantidad de lados del polígono: ");
  scanf("%d", &n);
  
  p->n = n;

  p->pts =  malloc(n * sizeof(struct punto));

  printf("Creación de un polígono de %d lados\n", n);
  for(int i=0; i < n; i++) {  
    printf("\t Ingrese las coordenadas del punto %d: ", i+1);
    scanf("%d %d", &x, &y);
    p->pts[i].x = x;
    p->pts[i].y = y;    
  }

  return p;
}

void imprimir_triangulo(struct triangulo * t) {
  printf("Triángulo: (%d,%d) (%d,%d) (%d,%d)\n", t->p1.x, t->p1.y, t->p2.x,
	 t->p2.y, t->p3.x, t->p3.y);
}

void imprimir_cuadrilatero(struct cuadrilatero * c) {
  printf("Cuadrilátero: (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n", c->p1.x, c->p1.y,
	 c->p2.x, c->p2.y, c->p3.x, c->p3.y, c->p4.x, c->p4.y);
}

void imprimir_poligono(struct poligono *p) {
  printf("Polígono: ");
  for(int i=0; i < p->n; i++)
    printf(" (%d,%d)", p->pts[i].x, p->pts[i].y);
  printf("\n");
}

int main() {
  pt punto1 = {10, 5};

  printf("punto1: (%d, %d)\n", punto1.x, punto1.y);
  
  struct triangulo t;
  crear_triangulo(&t);
  imprimir_triangulo(&t);

  struct cuadrilatero *c = crear_cuadrilatero();
  imprimir_cuadrilatero(c);

  struct poligono *p = crear_poligono();
  imprimir_poligono(p);

  
  return EXIT_SUCCESS;
}
