#include "utils_array.h"
#include "rotores.h"

int main() {
  int n = 0;
  char *rotor = generar_rotor(&n);
  imprimir_arreglo(rotor, n);

  for(int i=0; i < 3; i++) {
    rotar(rotor, n);
    imprimir_arreglo(rotor, n);
  }

  guardar_arreglo(rotor, n, "rotor1.txt");
  int nn=0;
  char *rotor2 = cargar_arreglo("rotor1.txt", &nn);
  rotar(rotor2, nn);
  imprimir_arreglo(rotor2, nn);
  
  return EXIT_SUCCESS;
}
