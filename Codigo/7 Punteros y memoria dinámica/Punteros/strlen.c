#include <stdio.h>
#include <stdio.h>

// Implementación propia de la función strlen
int strlen_local(char *t) {
  int largo = 0;

  while(*t != '\0') {
    largo++;
    t++;
  }
  return largo;
}

int main() {
  char texto[128];
  
  printf("Ingrese un texto: ");
  // Recordatorio: %[^\n]s permite leer símbolos y espacios
  scanf("%[^\n]s", texto);

  int l = strlen_local(texto);

  printf("El largo del texto ingresado es %d\n", l);
  
  return 1;
}
