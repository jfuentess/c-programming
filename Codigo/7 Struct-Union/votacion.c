//http://www.catb.org/esr/structure-packing/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int candidatos = 3;

// Persona que emite un voto
struct votante {
  char rut[10];
  int voto; // voto=0  blanco, voto=-1 nulo
};

// Mesa electoral
struct mesa {
  int numero; // Número de la mesa
  struct votante votantes[10]; // lista de 10 votantes
};

// Distrito electoral
struct distrito {
  int numero; // Número del distrito
  struct mesa mesas[5]; // lista de 5 mesas
};

// Función para crear valores random en la votación
void simular_votacion(struct distrito * ccp) {
  ccp->numero = 20;

  // Recorremos las 5 mesas
  for(int i=0; i < 5; i++) {
    ccp->mesas[i].numero = i+1;
    // Recorremos los 10 votantes de cada mesa
    for(int j=0; j < 10; j++) {
      // Generamos un rut al azar (no necesariamente válido)
      int num = 6000000 + rand() % 20000000;
      int dv = rand() % 10;
      char rut[10];
      sprintf(rut, "%d-%d", num, dv);
      strcpy(ccp->mesas[i].votantes[j].rut, rut);
      
      // Usamos candidatos + 2 para considerar los 3 candidatos más votos nulos
      // y blancos
      ccp->mesas[i].votantes[j].voto = (rand() % (candidatos+2)) - 1;
    }
  }
}

// Función para imprimir todos los votos por mesa electoral
void imprimir_votacion(struct distrito * ccp) {
  printf("Distrito %d\n", ccp->numero);
  
  for(int i=0; i < 5; i++) {
    printf("\tMesa %d\n", ccp->mesas[i].numero);

    for(int j=0; j < 10; j++) {
      printf("\t\t%s votó por el candidato %d\n", ccp->mesas[i].votantes[j].rut,
	     ccp->mesas[i].votantes[j].voto);
    }
  }
}

// Función que obtiene el porcentaje de voto por candidato
void recuento_votos(struct distrito * ccp) {
  // Arreglo para almacenar el recuento por tipo de voto
  int rec_candidatos[candidatos+2];
  int total_votos = 0;

  for(int i=0; i < candidatos+2; i++)
    rec_candidatos[i] = 0;

  // Proceso de conteo
  for(int i=0; i < 5; i++) {
    for(int j=0; j < 10; j++) {
      int voto = ccp->mesas[i].votantes[j].voto;
      rec_candidatos[voto+1]++;

      total_votos++;
    }
  }

  // Impresión de los resultados
  printf("Distrito %d\n", ccp->numero);
  for(int i=0; i < candidatos+2; i++) {
    if(i==0) printf("Votos nulos: ");
    else if(i==1) printf("Votos blancos: ");
    else printf("Votos cantidado %d: ", i-1);

    printf("%d (%.2f%%)\n", rec_candidatos[i], ((float)rec_candidatos[i]/total_votos)*100);
  }
}

int main() {
  // ###########################################
  // ### Tamaño de las estructuras definidas ###
  // ###########################################
  printf("Tamaño de un votante: %ld bytes (deberían ser 12 bytes)\n", sizeof(struct votante));
  printf("Tamaño de una mesa: %ld bytes\n", sizeof(struct mesa));
  printf("Tamaño de un distrito: %ld bytes\n", sizeof(struct distrito));


  // ########################################################
  // ### Declaración de una variable tipo struct distrito ###
  // ########################################################
  struct distrito ccp;

  // ######################################################
  // ### Funciones para acceder/modificar la estructura ###
  // ######################################################
  simular_votacion(&ccp);
  imprimir_votacion(&ccp);
  recuento_votos(&ccp);

  return EXIT_SUCCESS;
}
