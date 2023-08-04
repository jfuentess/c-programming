#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fecha fecha_t;
typedef struct ciudad ciudad_t;
typedef unsigned char byte;

struct fecha {
   int d; // Día
   int m; // Mes
   int a; // Año
};

struct ciudad {
   byte nombre[50];
   float lat;
   float lon;
   // Fundación
   fecha_t f;
};

void print_city(ciudad_t c) {
   printf("%s (%f, %f). Fundada el %d/%d/%d.\n", 
                        c.nombre, c.lat,
                        c.lon, c.f.d,
                        c.f.m, c.f.a);
}

int main() {
   ciudad_t c1; 
   strcpy(c1.nombre, "Concepcion");
   c1.lat = -36.8271;
   c1.lon = -73.0503;
   c1.f.d = 27;
   c1.f.m = 9;
   c1.f.a = 1544;

   print_city(c1);
   return 0;
}
