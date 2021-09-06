#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Cantidad total de puntos
  int total_puntos = 100000;
  int intervalo = 10000;

  // Variables utilizadas para generar puntos (x,y) al azar. En esta
  // implementación utilizaremos un plano de 1 por 1.
  double rand_x, rand_y;
  // Variable que almacenará el valor estimado de pi
  double pi;
  // Variable utilizada para medir la distancia del punto (x,y) al centro del círculo
  double dist_xy; 
  // Contadores de puntos en el círculo y el cuadrado
  int puntos_circulo = 0, puntos_cuadrado = 0; 

  // Añadimos la semilla al generador de número pseudo-aleatorios
  srand(time(NULL));

  for (int i = 0; i < total_puntos; i++) {    
    // Generación al azar del punto (x,y)
    rand_x = (double)(rand() % (intervalo + 1)) / intervalo;
    rand_y = (double)(rand() % (intervalo + 1)) / intervalo;
    
    // Distance between (x, y) from the origin
    dist_xy = rand_x * rand_x + rand_y * rand_y;

    // Número total de puntos dentro del círculo
    if (dist_xy <= 1)
      puntos_circulo++;

    // Número total de puntos generados
    puntos_cuadrado++;

    // Estimación de pi en la iteración actual
    pi = (double)(4 * puntos_circulo) / puntos_cuadrado;

    // Imprimimos el valor estimado de pi cada 100 iteraciones
    if (i % 100 == 0) {
      printf("Estimación de pi luego de %d iteraciones: %f\n", i, pi);
    }
  }

  printf("Valor estimado de pi: %f\n", pi);

  return 0;
}
