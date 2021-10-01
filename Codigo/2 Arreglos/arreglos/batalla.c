/*

A continuación se presenta una traducción del problema 1991 de Timus, llamado
"The battle near the swamp". URL: https://acm.timus.ru/problem.aspx?space=1&num=1991


  La batalla cerca del pantano


En la batalla con la Federación de Comercio, la reina Amidala solicitó la ayuda
de los gungans, Jar Jar Binks escoltó a la reina y a su gente hasta el lugar sagrado
de los gungans, donde llegaron a un acuerdo. Los gungans acordaron proveer su
ejército para liberar a la capital de los droides de la Federación. El lider de
los gungans, Boss Nass, estuvo tan agradecido con la unión de las naciones, que
nombró a Jar Jar general de su ejército.

Y esta es la situación: Dos ejércitos instalados al borde del pantano. Los
droides de la Federación son soldados bien entrenados. Cuando están formados, se
dividen en n bloques de k droides en cada bloque. Los gungans tienen un arma
infalible contra los droides, la cual es una pequeña bola de energía llamada
boom booms. Una de esas bolas de energía puede desactivar a un droide. 

Jar Jar Binks también decidió dividir su ejército en n secciones, donde cada
sección tiene la misión de destruir el bloque correspondiente de droides. Cada
sección recibió un cargamento de boom booms. Ayuda al general Binks a calcular
el número de boom booms que sobrarán y los droides sobrevivientes luego de un
ataque. Puedes asumir que cada vez que un boom boom es disparado, este siempre
da en el blanco, eliminando un droide. 

Entrada: La primera línea de la entrada contiene los números n y k (1<=n,
k<=10000). La segunda línea contiene n números a_i (0 <= a_i <= 100000) -- el
número de boom booms asignados a la i-ésima sección.

Salida: Imprimir dos enteros -- El número de boom booms sobrantes y el número de
droides sobrevivientes.

Ejemplo
=======

Entrada:
   4 5
   2 7 5 0

Salida:
   2 8

*/


/*
 * Problema: Resolver el problema N° 1991 de la plataforma Timus
 */

#include <stdio.h>
 
int main() {

  /* printf("##############################################\n"); */
  /* printf("### Batalla cerca del pantano (Timus 1991) ###\n"); */
  /* printf("##############################################\n\n"); */


  int n, k;
  // bbs: boom booms restantes
  // ds: droides sobrevivientes 
  int bbs = 0, ds = 0;

  // Pedimos el número de bloques (n) y la cantidad de droides (k) por bloque
  scanf("%d%d", &n, &k);

  // Verificamos que cumplan con las restricciones mínimas
  if(1 > n) return 0;
  if(k > 10000) return 0;

  // Por cada uno de los n bloques revisamos la cantidad de boom booms
  for(int i=0; i<n; i++) {
    // bal: Cantidad de boom booms asignados a la sección i
    int bal;
    scanf("%d", &bal);

    // Verificamos que se cumplan las condiciones mínimas
    if(bal < 0 || bal > 100000) return 0;

    // Si la cantidad de boom booms es menor a la cantidad de droides, entonces
    // aumentamos la cantidad de droides sobrevivientes
    if(bal < k)
      ds = ds + (k-bal); // ds += (k-bal)
    else // En caso contrario, aumentamos la cantidad de boom booms sobrantes
      bbs = bbs + (bal - k);
  }

  printf("%d %d\n", bbs, ds); 
  
  return 0;
}
