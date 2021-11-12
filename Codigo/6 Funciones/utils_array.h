#include <stdio.h>

#define BOLD "\e[1m"
#define WHITE "\e[7m"
#define BLUE "\e[44m"
#define NORMAL "\e[0m"

void imprimir_arreglo(char *, int);
void guardar_arreglo(char *, int, const char *);
char * cargar_arreglo(const char *, int *);
