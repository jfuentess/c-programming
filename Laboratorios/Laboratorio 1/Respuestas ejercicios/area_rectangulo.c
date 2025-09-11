#include <stdio.h>

int main() {
    float ancho, largo, area;

    printf("Ingrese el ancho del rectangulo: ");
    scanf("%f", &ancho);

    printf("Ingrese el largo del rectangulo: ");
    scanf("%f", &largo);

    area = ancho * largo;

    printf("El area del rectangulo es: %.2f\n", area);

    return 0;
}