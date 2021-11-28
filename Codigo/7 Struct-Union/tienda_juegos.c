/*
 * [Ejercicios 16 y 17 - listado ensayo] Implemente las siguientes 3 estructuras:
 *
 *   - Estructura video juego, la cual estará conformada por los campos nombre
 *       del video juego, año de lanzamiento y consolas o plataformas. 
 *
 *   - Estructura compra, la cual estará conformada por los campos fecha de la
 *      compra, monto de la compra y puntero al video juego comprado.
 *
 *   - Estructura tienda, la cual estará conformada por los campos nombre de la
 *      tienda, dirección, arreglo de video juegos y arreglo de compras.
 *
 *  Utilizando las estructuras implemente las funciones para agregar video juegos
 *  a la tienda, registrar una nueva compra, imprimir registros de video juegos,
 *  imprimir registros de compras y eliminar un video juego. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct video_juego juego;
typedef struct compra compra;
typedef struct tienda tienda;

struct video_juego {
  char nombre[50]; // Nombre del video juego
  int lanzamiento; // Año de lanzamiento
  char consolas[255]; // Lista de consolas que soportan el video juego
  char activo; // Campo adicional utilizado para indicar si el juego está
  // vigente o eliminado de la tienda 
};

struct compra {
  char fecha[20]; // Fecha de la compra
  int monto; // Monto de la compra
  juego *vjuego; // Puntero al video juego comprado
};

struct tienda {
  char nombre[50]; // Nombre de la tienda
  char direccion[100]; // Dirección de la tienda
  juego *juegos; // Arreglo de video juegos disponibles
  compra *compras; // Registro de compras de la tienda
  int cap_juegos; // Capacidad máxima de video juegos
  int cap_compras; // Capacidad máxima de registros de compra
  int num_juegos; // Cantidad actual de video juegos
  int num_compras; // Cantidad actual de registros de compra
};

tienda* crear_tienda() {
  printf("####################################\n");
  printf("### Creación de una nueva tienda ###\n");
  printf("####################################\n\n");
  
  tienda *t = malloc(sizeof(tienda));

  printf("Nombre de la tienda: ");
  scanf("%49[^\n]s", t->nombre);
  printf("Dirección de la tienda: ");
  scanf(" %99[^\n]s", t->direccion);

  t->cap_juegos = 10; // Asumiremos que la tienda almacena máximo 10 video juegos
  t->cap_compras = 10; // Asumiremos que la tienda registra máximo 10 compras
  t->num_juegos = 0; // Inicialmente no hay video juegos ingresados
  t->num_compras = 0; // Inicialmente no hay compras ingresadas
  t->juegos = malloc(t->cap_juegos*sizeof(juego));
  t->compras = malloc(t->cap_compras*sizeof(compra));
}

void comprar_video_juego(tienda *t) {
  printf("\n*** Comprando un nuevo juego***\n");

  char nombre[50];
  juego *seleccionado = NULL; // Puntero al juego a comprar
  
  printf("\tIngrese el nombre del video juego que quiere comprar\n");
  printf("\t(El nombre debe coincidir de manera exacta): ");
  scanf(" %49[^\n]s", nombre);

  for(int i=0; i < t->num_juegos; i++) {
    // Si el i-ésimo juego tiene el mismo nombre que acabamos de ingresar,
    // entonces será el juego comprado 
    if(strcmp(nombre, t->juegos[i].nombre) == 0)
      seleccionado = &(t->juegos[i]);
  }

  if(seleccionado == NULL)
    printf("\t[[ No existe un juego con el nombre '%s']]\n", nombre);
  else {
    // Cantidad actual de compras registradas
    int n = t->num_compras;

    printf("\t¡Juego encontrado!\n");
    printf("\tFecha de la compra: ");
    scanf(" %19[^\n]s", t->compras[n].fecha);
    printf("\tMonto de la compra: ");
    scanf(" %d", &(t->compras[n].monto));
    t->compras[n].vjuego = seleccionado;

    // Incrementamos en 1 la cantidad total de compras
    t->num_compras++;

  }
}

void agregar_video_juego(tienda *t) {
  printf("\n*** Agregando un nuevo juego***\n");
  if(t->num_juegos == t->cap_juegos) {
    printf("\t[[ Se alcanzó la capacidad máxima de video juegos en esta tienda]]\n");
    return;
  }

  // Cantidad actual de video juegos ingresados
  int n = t->num_juegos;

  printf("\tNombre del video juego: ");
  scanf(" %49[^\n]s", t->juegos[n].nombre);
  printf("\tAño de lanzamiento: ");
  scanf(" %d", &(t->juegos[n].lanzamiento));
  printf("\tConsolas que soportan el juego: ");
  scanf(" %254[^\n]s", t->juegos[n].consolas);
  t->juegos[n].activo = 1;
  
  // Incrementamos en 1 la cantidad total de video juegos
  t->num_juegos++;
}

void eliminar_video_juego(tienda *t) {
  printf("\n*** Eliminando un nuevo juego***\n");

  char nombre[50];
  juego *seleccionado = NULL; // Puntero al juego a eliminar
  printf("\tIngrese el nombre del video juego que quiere eliminar\n");
  printf("\t(El nombre debe coincidir de manera exacta): ");
  scanf(" %49[^\n]s", nombre);

  for(int i=0; i < t->num_juegos; i++) {
    // Si el i-ésimo juego tiene el mismo nombre que acabamos de ingresar,
    // entonces será el juego comprado 
    if(strcmp(nombre, t->juegos[i].nombre) == 0)
      seleccionado = &(t->juegos[i]);
  }

  // Si el juego ya fue eliminado de manera lógica o no existe un juego con el
  // nombre recién ingresado, se reporta
  if(seleccionado->activo == 0 || seleccionado == NULL)
    printf("\t[[ No existe un juego con el nombre '%s']]\n", nombre);
  else {
    // Lo eliminados de manera lógica (sigue existiendo en el arreglo)
    seleccionado->activo = 0;
    printf("\tJuego eliminado\n");
  }
}

void registro_juegos(tienda *t) {
  printf("\nLista de video juegos de la tienda %s\n\n", t->nombre);

  for(int i=0; i < t->num_juegos; i++) {
    // Sólo se imprimen los juegos que están activos (no eliminaos)
    if(t->juegos[i].activo == 1)
      printf("Juego: %s\tLanzamiento: %d\tConsolas: %s\n", t->juegos[i].nombre,
	     t->juegos[i].lanzamiento, t->juegos[i].consolas); 
  }
}

void registro_compras(tienda *t) {
  printf("\nLista de compras de la tienda %s\n\n", t->nombre);

  for(int i=0; i < t->num_compras; i++) {
    printf("Fecha:%s\tJuego: %s\tMonto: %d\n", t->compras[i].fecha,
  t->compras[i].vjuego->nombre, t->compras[i].monto); 
  }
}

int main() {

  tienda *t = crear_tienda();

  for(int i=0; i < 3; i++)
    agregar_video_juego(t);

  registro_juegos(t);

  for(int i=0; i < 3; i++)
    eliminar_video_juego(t);
  
  registro_juegos(t);
  
  for(int i=0; i < 3; i++)
    comprar_video_juego(t);

  registro_compras(t);

  return EXIT_SUCCESS;
}
