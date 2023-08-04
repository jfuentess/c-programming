#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha {
   int d; // Día
   int m; // Mes
   int a; // Año
};

struct ciudad {
   char nombre[50];
   float lat;
   float lon;
   // Fundación
   struct fecha f;
};

void print_city(struct ciudad c) {
   printf("%s (%f, %f). Fundada el %d/%d/%d.\n", 
                        c.nombre, c.lat,
                        c.lon, c.f.d,
                        c.f.m, c.f.a);
}

int main() {
   struct ciudad c1; 
   strcpy(c1.nombre, "Concepcion");
   c1.lat = -36.8271;
   c1.lon = -73.0503;
   c1.f.d = 27;
   c1.f.m = 9;
   c1.f.a = 1544;

   print_city(c1);
   return 0;
}
