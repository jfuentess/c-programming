#include <stdio.h>

int main(){
	int n;
	printf("Escriba la cantidad de numeros a guardar: ");
	scanf("%d", &n);
	printf("Escriba los %d numeros a guardar:\n", n);
	int array[n];
	for (int i = 0; i < n; ++i)
	{
		//int aux = 0;
		//array[i] = aux;
		scanf("%d", &array[i]);
	}
	printf("Los numeros son: ");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}