#include <stdio.h>

char *concatenarFrases(char *frase1, char *frase2);

char *invertirFrase(char *frase);

void liberarMemoria(char *ptr);

int main() {
  char frase1[200], frase2[200];

  // Solicitar al usuario que ingrese dos frases
  printf("Ingrese la primera frase: ");
  // Leer hasta encontrar un salto de línea
  scanf("%[^\n]", frase1);
  getchar(); // Limpiar el buffer del teclado (tecla Enter)
  printf("Ingrese la segunda frase: ");
  scanf("%[^\n]", frase2);

  // Concatenar las dos frases e imprimir el resultado
  char *concatenada = concatenarFrases(frase1, frase2);
  printf("Frases concatenadas: %s\n", concatenada);

  // Invertir la primera frase e imprimir el resultado
  char *invertida = invertirFrase(frase1);
  printf("Primera frase invertida: %s\n", invertida);

  // Liberar memoria asignada para las frases
  liberarMemoria(concatenada);
  liberarMemoria(invertida);

  return 0;
}
