#include <stdio.h>

double area_tri(double b, double a) {
   double area  = (b*a)/2;
   return area;
}

int main() {
   double bs, al;
   printf("Ingrese base y altura: ");
   scanf("%lf %lf", &bs, &al);

   double ar = area_tri(bs, al);

   printf("Área resultante: %lf\n", ar);
   return 1;
}
