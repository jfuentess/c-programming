#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {

  printf("#########################################\n");
  printf("### Copia y contatenación de palabras ###\n");
  printf("#########################################\n\n");

  
  char texto1[104] = "El Premio Turing es un premio de las Ciencias de la Computacion que es otorgado anualmente por la ACM. ";
  char texto2[70] = "Rinde homenaje a Alan Turing y desde 2014 es patrocinado por Google. ";
  char texto3[70] = "Los ultimos galardonados (2019) fueron Edwin Catmull y Prat Hanrahan.";


  // Largo de las cadenas
  printf("Texto 1 tiene largo %lu\n", strlen(texto1));
  printf("Texto 2 tiene largo %lu\n", strlen(texto2));
  printf("Texto 3 tiene largo %lu\n\n", strlen(texto3));
  
  // texto4 = concatenación de texto1, texto2 y texto3
  // Inicializamos con una cadena vacía y con símbolo terminal '\0'
  char texto4[242] = "";
  char texto5[242] = "";
  char texto6[242] = "";

  // strncat(destino, fuente, largo)
  // Concatenación de los textos 1, 2 y 3 al final del texto 4. La función
  // strncat primero busca el final de la cadena antes de comenzar la copia de
  // los nuevos símbolos. En el proceso, elimina el final de cadena anterior e
  // inserta uno nuevo al final de la copia
  strncat(texto4, texto1, strlen(texto1));
  strncat(texto4, texto2, strlen(texto2));
  strncat(texto4, texto3, strlen(texto3));


  // strncpy(destino, fuente, largo)
  // Copia de los textos 1, 2 y 3 en el texto 5. A diferencia de strncat, la
  // función strncpy comienza a copiar desde el inicio del texto 5.
  strncpy(texto5, texto1, strlen(texto1)+1);
  strncpy(texto5, texto2, strlen(texto2)+1);
  strncpy(texto5, texto3, strlen(texto3)+1);

  // sprintf() funciona de manera similar a printf(), pero en lugar de imprimir
  // por la salida estándar (pantalla), imprimir en una cadena de salida.
  sprintf(texto6, "%s <ESPACIO> %s", texto1, texto2);
    
  printf("t1: %s\n", texto1);
  printf("t2: %s\n", texto2);
  printf("t3: %s\n", texto3);

  printf("\nt4: %s\n", texto4);
  printf("\nt5: %s\n", texto5);
  printf("\nt6: %s\n", texto6);

  printf("\nTexto 4 tiene largo %lu\n", strlen(texto4));
  printf("Texto 5 tiene largo %lu\n", strlen(texto5));
  printf("Texto 6 tiene largo %lu\n\n", strlen(texto6));

  // Comparación de cadenas de caracteres
  // int salida = strncmp(texto1, texto2, largo)
  //   - salida = 0 --> texto1 y texto2 son iguales
  //   - salida < 0 --> texto1 es menor lexicográficamente que texto2
  //   - salida > 0 --> texto1 es mayor lexicográficamente que texto2
  
  strncpy(texto1, "tangananica", 11);
  strncpy(texto2, "tanganana", 9);
  printf("\nComparación texto1 con texto2: %d\n", strncmp(texto1, texto2, 9));
  
  return 0;
}
