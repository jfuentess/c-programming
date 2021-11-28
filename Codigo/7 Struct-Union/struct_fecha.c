#include <stdio.h>
#include <stdlib.h>

struct fecha {
   int d; // Día
   int m; // Mes
   int a; // Año
};

void print_fecha(struct fecha f) {
   printf("%d/%d/%d\n", f.d, f.m, f.a);
}

struct fecha siguiente_dia1(struct fecha f) {
   f.d = 1 + (f.d % 30); // Asumiendo meses de 30 días
   if(f.d == 1) {
	f.m = 1 + (f.m % 12);
      if(f.m == 1)
         f.a++;
   }
   return f;
}

void siguiente_dia2(struct fecha *f) {
   // Nota: f->d es equivalente a (*f).d
   f->d = 1 + (f->d % 30);
   if(f->d == 1) {
	f->m = 1 + (f->m % 12);
      if(f->m == 1)
         f->a++;
   }
}

int main() {
  struct fecha hoy = {29, 11, 2021}; 
   print_fecha(hoy);
   struct fecha sig = siguiente_dia1(hoy);
   print_fecha(sig);
   siguiente_dia2(&sig);
   print_fecha(sig);

   return 0;
}
