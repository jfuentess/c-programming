#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura que representa un nodo
struct nodo {
  int v;
  struct nodo *next;
  struct nodo *prev;
};

// Estructura que representa una lista de nodos
struct lista {
  int n;
  struct nodo *P;
};

// Creación de un nodo
struct nodo * crear_nodo(int v) {
  struct nodo * nodo = malloc(sizeof(struct nodo));

  nodo->v = v;
  nodo->next = NULL;
  nodo->prev = NULL;

  return nodo;
}

struct lista * crear_lista() {
  struct lista *l = malloc(sizeof(struct lista));

  // Inicialmente la lista está vacía
  l->n = 0;
  l->P = NULL;

  return l;
}

// Insertar un nuevo nodo
void insertar_nodo_inicio(struct lista *l) {
  int v;
  printf("Inserte el valor del nuevo nodo: ");
  scanf("%d", &v);
  
  struct nodo * nd = crear_nodo(v);

  nd->next = l->P;
  nd->prev = NULL;

  // En caso de tener la lista vacía, esta instrucción de se debe ejecutar 
  if(l->P != NULL)
    l->P->prev = nd;

  l->P = nd;
  l->n++;
}

// Insertar un nuevo nodo
void insertar_nodo_final(struct lista *l) {
  int v;
  printf("Inserte el valor del nuevo nodo: ");
  scanf("%d", &v);
  
  struct nodo * nd = crear_nodo(v);
  // Comenzamos a recorrer desde el inicio de la lista hasta llegar al último
  // elemento
  struct nodo *actual = l->P;
  
  // En caso de tener la lista vacía, no necesitamos recorrerla
  if(l->P != NULL)
    while(actual->next != NULL)
      actual = actual->next;

  if(actual != NULL)
    actual->next = nd;
  nd->next = NULL;
  nd->prev = actual;
  l->n++;
}

// Eliminar un nodo de la lista
void eliminar_nodo(struct lista *l) {
  int v;
  printf("Inserte el valor del nodo a eliminar: ");
  scanf("%d", &v);

  // Tarea: Implementar esta función
}

void imprimir_lista(struct lista *l) {
  struct nodo *actual = l->P;

  printf("Lista: ");
  while(actual != NULL) {
    printf("%d <-> ", actual->v);
    actual = actual->next;
  }
  printf("NULL\n");
}


int main() {
  struct lista *l = crear_lista();
  imprimir_lista(l);

  // Insertamos 3 nodos al inicio de la lista
  for(int i=0; i < 3; i++) {
    insertar_nodo_inicio(l);
    imprimir_lista(l);
  }

  // Insertamos 3 nodos al final de la lista
  for(int i=0; i < 3; i++) {
    insertar_nodo_final(l);
    imprimir_lista(l);
  }
  
  return EXIT_SUCCESS;
}
