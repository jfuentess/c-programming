#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ciudad {
   char nombre[50];
   float lat;
   float lon;
};

void print_city(struct ciudad c) {
  printf("%s (%f, %f)\n", c.nombre, c.lat, c.lon);
}

int main() {
   struct ciudad c1; 
   strcpy(c1.nombre, "Concepcion");
   c1.lat = -36.8271;
   c1.lon = -73.0503;

   print_city(c1);
   return 0;
}
