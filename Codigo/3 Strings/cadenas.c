#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {

  printf("############################################\n");
  printf("### Declaración de cadenas de caracteres ###\n");
  printf("############################################\n\n");
		  
  char s1[11] = "Hola Mundo";
  char s2[11] = {'H', 'o', 'l', 'a', ' ', 'M', 'u', 'n', 'd', 'o', '\0'};
  char *s3 = "Chao Mundo"; // Cadena de caracteres constante
  char s4[] = "Chao Mundo";

  s1[5] = '-';
  s2[5] = '-';
  s4[5] = '-';

  // strlen() cuenta caracteres hasta el final de la cadena
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  int l3 = strlen(s3);
  int l4 = strlen(s4);
  
  printf("[cadena] %s (largo: %d)\n", s1, l1);
  printf("[cadena] %s (largo: %d)\n", s2, l2);
  printf("[cadena] %s (largo: %d)\n", s3, l3);
  printf("[cadena] %s (largo: %d)\n", s4, l4);

  printf("Ingrese una nueva cadena: ");
  scanf("%s", s1); // ¿Qué pasa si se introduce una cadena de más de 10
                   // caracteres? ¿Qué pasa si ingresamos palabras separadas por
                   // espacios?
                   // Para capturar espacios, usar scanf("%[^\n]s", s1);
  getchar(); // Captura el salto de línea
  
  l1 = strlen(s1);

  printf("[cadena] %s (largo: %d)\n", s1, l1);
  
  printf("\nIngrese una nueva cadena: ");
  scanf("%3s", s2); // Limitamos el ingreso a sólo 3 caracteres
  getchar(); // Captura el salto de línea
  
  l2 = strlen(s2);

  printf("[cadena] %s (largo: %d)\n", s2, l2);

  return 0;
}
