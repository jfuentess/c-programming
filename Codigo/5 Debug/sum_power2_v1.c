#include "sum_power2.h"


unsigned long sum_power2(int A[], int N) {
  unsigned long total = 0;

  for(int i=0; i < N; i++) {
    total += A[i]*A[i];
  }

  return total;
}
