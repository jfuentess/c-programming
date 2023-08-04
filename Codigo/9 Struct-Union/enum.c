#include <stdio.h>
#include <stdlib.h>

enum estado {ACTIVO, INACTIVO};
enum rating {EXCELENTE=5, BUENA=4, NORMAL=3, BAJA=2, MALA=1};
enum semana {LU, MA, MI, JU=10, VI, SA, DO};

int main() {
   enum estado e_actual;
   enum rating calidad;
   enum semana dia;

   e_actual = INACTIVO;
   calidad = NORMAL;
   dia = LU;

   printf("Valores para estado: %d %d\n", ACTIVO, INACTIVO);
   printf("Valores para rating: %d %d %d %d %d\n", EXCELENTE, BUENA, NORMAL, BAJA, MALA);
   printf("Valores para semana: %d %d %d %d %d %d %d\n", LU, MA, MI, JU, VI, SA, DO);

   return 0;
}
