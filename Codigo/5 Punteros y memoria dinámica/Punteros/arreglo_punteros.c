#include <stdio.h>

int main(int argc, char **argv) {

  printf("##########################################\n");
  printf("### Matriz con filas de largo variable ###\n");
  printf("###        (Arreglo de punteros)       ###\n");
  printf("##########################################\n\n");


  char *langs[7]= {"c", "c++", "python", "perl", "php", "java", "bash"};

  for(int i=0; i<7; i++)
    printf("\t%s\n", *(langs+i));
  
  return 1;
}

