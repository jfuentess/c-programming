#include <stdio.h>

int main()
{
    char c = 'k';
    short s = 16;
    int i = 32;
    long l = 64;
    float f = 32.32f;
    double d = 64.64;
    char frase[15] = "Hola mundo";

    printf("c: %c, s: %d\n", c, s);
    printf("El valor de int i es: %d\n", i);
    printf("El valor de long l es: %ld\n", l);
    printf("f: %f, d: %lf\n", f, d);
    printf("%s\n", frase);

    return 0;
}