#include <stdio.h>

int factorial(int n) {
    int f = 1;

    for(int i = 1; i <= n; i++)
        f = f *i;

    return f;
}

int main() {
    int x;
    printf("Ingresa un entero entero: ");
    scanf("%d", &x);

    //Que pasa entre 16 y 17???????
    if(factorial(x) > 1e8) printf("%d \n", factorial(x));
    else printf("muy chicoooo");

    printf("\nFin del programa.\n");
    return 0;
}
