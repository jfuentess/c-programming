#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    // declaracion de matriz dinamica
    int **matr = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
        matr[i] = malloc(m*sizeof(int));

    // asignar valores a la matriz
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matr[i][j]=i*m+j;

    printf("Matriz antes:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ",matr[i][j]);
        printf("\n");
    }
    printf("\n");


    // swap que nos piden
    int aux = matr[2][3];
    matr[2][3] = matr[3][1];
    matr[3][1] = aux;

    aux = matr[3][m-2];
    matr[3][m-2] = matr[n-1][m-1];
    matr[n-1][m-1] = aux;

    
    printf("Matriz despues:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ",matr[i][j]);
        printf("\n");
    }
    printf("\n");

    // liberar matriz dinamica
    for (int i = 0; i < n; i++)
        free(matr[i]);
    free(matr);
    return 0;
}