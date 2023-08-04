#include <math.h>
#include "sum_power2.h"


unsigned long sum_power2(int A[], int N) {
  unsigned long total = 0;

  for(int i=0; i < N; i++) {
    total += pow(A[i], 2);
  }

  return total;
}
