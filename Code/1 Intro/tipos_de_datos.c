#include <stdio.h>
#include <stdlib.h>

void main() {

    // Caracteres y números pequeños con signo
    char c1 = 'a';
    // Caracteres y números pequeños sin signo
    unsigned char c2 = 97;
    
    // Enteros pequeños con signo
    short s1 = -350;
    // Enteros pequeños sin signo
    unsigned short s2 = 250;
    
    // Enteros con signo
    int i1 = -1234;
    // Enteros sin signo
    unsigned i2 = 10000;

    // Enteros grandes con signo
    long l1 = -1234567;
    // Enteros grandes sin signo
    unsigned long l2 = 89283;
    
    // Números punto flotante con precisión simple
    // 1 bit de signo, 7 bits de exponente y 24 bits de mantisa
    float f = 12.75;
    // Números punto flotante con precisión doble
    // 1 bit de signo, 11 bits de exponente y 52 bits de mantisa
    double d = 23.21123;
    // Números (grandes) punto flotante con precisión doble
    long double ld = 65.1209;

    printf("Cantidad de bytes de un \"char\" (%c) es %zu bytes\n", c1,
	   sizeof(c1)); 
    printf("Cantidad de bytes de un \"unsigned char\" (%c) es %zu bytes\n", c2,
	   sizeof(c2)); 
    
    printf("Cantidad de bytes de un \"short\" (%d) es %zu bytes\n", s1,
	   sizeof(s1)); 
    printf("Cantidad de bytes de un \"unsigned short\" (%d) es %zu bytes\n", s2,
	   sizeof(s2)); 

    printf("Cantidad de bytes de un \"int\" (%d) es %zu bytes\n", i1,
	   sizeof(i1)); 
    printf("Cantidad de bytes de un \"unsigned (int)\" (%u) es %zu bytes\n", i2,
	   sizeof(i2)); 

    printf("Cantidad de bytes de un \"long\" (%li) es %zu bytes\n", l1,
	   sizeof(l1)); 
    printf("Cantidad de bytes de un \"unsigned long\" (%lu) es %zu bytes\n", l2,
	   sizeof(l2)); 

    printf("Cantidad de bytes de un \"float\" (%f) es %zu bytes\n", f,
	   sizeof(f)); 
    printf("Cantidad de bytes de un \"double\" (%f) es %zu bytes\n", d,
	   sizeof(d)); 
    printf("Cantidad de bytes de un \"long double\" (%Lf) es %zu bytes\n", ld,
	   sizeof(ld));

    return;
}

