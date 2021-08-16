/*
 * Este ejemplo muestra el uso de la función rand(), utilizada en la
 * generación de números pseudo-aleatorizados. El código a continuación calcula
 * la probabilidad de que la función rand() genere números en el rango [0,
 * limite-1], considerando como rango máximo [0,99]
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// argc: cantidad de parámetros que se pasan por consola
// argv: los parámetros que se pasan por consola
void main(int argc, char** argv) {
  
  if(argc < 2) {
    printf("Uso: %s <limite>\n", argv[0]);
    exit(1);
  }
  
  /*
   * ¿Qué ocurre si no se ingresan argumentos (argv[1])?
   */
  
  int i;
  int contador = 0;
  int iteraciones = 1000;
  // argv[1]: primer parámetro del programa
  // atoi(): Transforma letras a números enteros
  int limite = atoi(argv[1]);

  srand(time(0)); // Semilla de la función rand() 
  
  for(i=0; i<iteraciones; i++) {
    int val = rand() % 100;
  
    if(val < limite)
      contador++;
  }

  // Casting de variables
  float prob =  ((float)contador/iteraciones)*100;
  
  printf("Probabilidad de obtener números menores a %d, en el rango [0,99], es %.2f%% \n", limite, prob);
}


