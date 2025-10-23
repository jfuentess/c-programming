#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam = 3; // podemos iniciar con un tam pequeno
    int *arr = malloc(tam*sizeof(int));
    int input;
    int agregados = 0;
    do
    {
        printf("Ingresa un nuevo numero: ");
        scanf("%d", &input);
        if (input!=0)
        {
            if (agregados == tam)
            {
                tam *= 2; // cada vez que se llena, se ajusta al doble del tamano actual
                arr = realloc(arr, tam*sizeof(int));
            }
            
            arr[agregados] = input;
            agregados++;
        }

    } while (input!=0);

    printf("elementos:\n");
    for (int i = 0; i < agregados; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}