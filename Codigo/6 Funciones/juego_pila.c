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

void jugador1();
void jugador2();

int main (){
  sticks = 10 + rand() % 10;

  printf("¡Inicia el juego!\n");

  jugador1();
  
  return 0;
}

// Función que implementa la lógica del jugador 1
void jugador1() {
  int c;
  do {
    printf("\t[Jugador 1] Cuántos sticks sacarás (1, 2 o 3)? ");
    scanf("%d", &c);
    getchar();
  } while(c < 1 || c > 3);

  if((sticks - c) == 0) {
    printf("\t\t¡Felicitaciones jugador 1, eres el ganador!\n");
    return;
  }
  else if((sticks - c) < 0) {
    printf("\t\t¡Qué lástima jugador 1, has perdido!\n");
    return;
  }
  else
    sticks -= c;

  jugador2();
}

// Función que implementa la lógica del jugador 2
void jugador2() {
  int c;
  do {
    printf("\t[Jugador 2] Cuántos sticks sacarás (1, 2 o 3)? ");
    scanf("%d", &c);
    getchar();
  } while(c < 1 || c > 3);

  if((sticks - c) == 0) {
    printf("\t\t¡Felicitaciones jugador 2, eres el ganador!\n");
    return;
  }
  else if((sticks - c) < 0) {
    printf("\t\t¡Qué lástima jugador 2, has perdido!\n");
    return;
  }
  else
    sticks -= c;

  jugador1();
}









