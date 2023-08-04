#include <stdlib.h>
#include <stdio.h>

// Llena un arreglo de lacon valores entre [a,b)
void fill_array(int *arr, int n, int a, int b);

// Imprime un arreglo de enteros
void print_array(int *arr, int n);

// Retorna la posición del mínimo elemento entre las posiciones a y b-1 del
// arreglo arr
int min_pos_range(int *arr, int a, int b);

// Retorna la posición del mínimo elemento de un arreglo
int min_pos(int *arr, int n);

// Retorna el mínimo elemento de un arreglo
int min_el(int *arr, int n);

// Intercambia el contenido de las variables pasadas por parámetro
void swap(int *a, int *b);
