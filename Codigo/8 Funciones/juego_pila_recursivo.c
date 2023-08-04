/* El juego de la pila: El juego consiste en que dos jugadores toman varitas de
   una pila con una cantidad desconocida de varitas. Las reglas son las
   siguientes:
    - Los jugadores se van alternando turnos
    - En cada turno, el jugador debe tomar 1, 2 o 3 varitas
    - Pierde aquel jugador que intenta tomar más varitas de las que quedan en la pila
 */

#include <stdio.h>
#include <stdlib.h>

int sticks = 0;

void jugador();

int main (){
  sticks = 10 + rand() % 10;

  printf("¡Inicia el juego!\n");

  jugador(1);
  
  return 0;
}

// Función que implementa la lógica de un jugador
void jugador(int num) {
  int c;
  do {
    printf("\t[Jugador %d] Cuántos sticks sacarás (1, 2 o 3)? ", num);
    scanf("%d", &c);
    getchar();
  } while(c < 1 || c > 3);

  if((sticks - c) == 0) {
    printf("\t\t¡Felicitaciones jugador %d, eres el ganador!\n", num);
    return;
  }
  else if((sticks - c) < 0) {
    printf("\t\t¡Qué lástima jugador %d, has perdido!\n", num);
    return;
  }
  else
    sticks -= c;

  jugador(1 + (num%2));
}





