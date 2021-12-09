// Ejercicio 5, clase 9

#include <stdio.h>
#include <stdio.h>

// ¿Cómo reemplazamos el ciclo while de la función strlen_local por un ciclo
// for?
int strlen_local(char *t) {
  int largo = 0;

  while(*t != '\0') {
    largo ++;
    t++;
  }
  return largo;
}

int main() {
  char texto[128];
  
  printf("Ingrese un texto: ");
  scanf("%[^\n]s", texto);

  int l = strlen_local(texto);

  printf("El largo del texto ingresado es %d\n", l);

  
  return 1;
}
