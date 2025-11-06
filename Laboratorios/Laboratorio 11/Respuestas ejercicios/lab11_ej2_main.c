#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Función que concatena dos frases en memoria dinámica
char *concatenarFrases(char *frase1, char *frase2) {
  // Calcular la longitud total necesaria (frase1 + frase2 + '\0')
  int longitud = strlen(frase1) + strlen(frase2) + 1;

  // Asignar memoria dinámica para la frase concatenada
  char *resultado = (char *)malloc(longitud * sizeof(char));

  // Verificar que la asignación fue exitosa
  if (resultado == NULL) {
    printf("Error: No se pudo asignar memoria\n");
    return NULL;
  }

  // Copiar la primera frase
  strcpy(resultado, frase1);

  // Concatenar la segunda frase
  strcat(resultado, frase2);

  return resultado;
}

char *invertirFrase(char *frase) {
  int longitud = strlen(frase);

  char *invertida = (char *)malloc((longitud + 1) * sizeof(char));

  // Invertir los caracteres
  for (int i = 0; i < longitud; i++) {
    invertida[i] = frase[longitud - 1 - i];
  }

  // Agregar el carácter nulo al final
  invertida[longitud] = '\0';

  return invertida;
}

void liberarMemoria(char *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
}
