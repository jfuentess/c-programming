#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /* Limites de enteros y caracteres */
#include <float.h> /* Limites de números decimales */

void main() {

    printf("char:\t\t[%d, %d] \n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:\t[0, %u] \n", UCHAR_MAX);
    
    printf("short:\t\t[%d, %d] \n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:\t[0, %u] \n", USHRT_MAX);
    
    printf("int:\t\t[%d, %d] \n", INT_MIN, INT_MAX);
    printf("unsigned (int):\t[0, %u] \n", UINT_MAX);

    printf("long:\t\t[%li, %li] \n", LONG_MIN, LONG_MAX);
    printf("unsigned long:\t[0, %lu] \n", ULONG_MAX);

    printf("float:\t\t[%f, %f] \n", FLT_MIN, FLT_MAX);
    printf("double:\t\t[%f, %f] \n", DBL_MIN, DBL_MAX);


    printf("\n");
    printf("Cantidad de bytes de un char: %ld\n", sizeof(char));
    printf("Cantidad de bytes de un short: %ld\n", sizeof(short));
    printf("Cantidad de bytes de un int: %ld\n", sizeof(int));
    printf("Cantidad de bytes de un long int: %ld\n", sizeof(long int));
    printf("Cantidad de bytes de un long long int: %ld\n", sizeof(long long int));
    printf("Cantidad de bytes de un float: %ld\n", sizeof(float));
    printf("Cantidad de bytes de un double: %ld\n", sizeof(double));
    printf("Cantidad de bytes de un long double: %ld\n", sizeof(long double));
    
    return;
}
