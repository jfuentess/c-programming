#include <stdio.h>
#include <stdlib.h>

struct X {
  char c; // 1 byte
  // 3 bytes de padding o relleno
  int d; // 4 bytes
  char e; // 1 byte
  // 3 bytes de padding o relleno
};

struct Y {
  char c; // 1 byte
  char e; // 1 byte
  // 2 bytes de padding o relleno
  int d; // 4 bytes
};

// Al usar __attribute__((__packed__)) le indicamos al compilador que no realice
// el padding (no añada relleno)
struct __attribute__((__packed__)) Z {
  char c; // 1 byte
  char e; // 1 byte
  int d; // 4 bytes
};

int main() {
  
  printf("Tamaño struct X: %ld bytes\n", sizeof(struct X));
  printf("Tamaño struct Y: %ld bytes\n", sizeof(struct Y));
  printf("Tamaño struct Z: %ld bytes\n", sizeof(struct Z));

  return 0;
}
