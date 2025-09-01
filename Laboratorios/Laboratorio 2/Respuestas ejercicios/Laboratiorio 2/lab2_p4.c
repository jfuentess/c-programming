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
	printf("La suma de los numeros pares es: ");
	int suma = 0;
	for (int i = 0; i < n; ++i)
	{
		if(array[i]%2 == 0){
			suma += array[i];
		}
	}
	printf("%d\n", suma);
	int multi = 1;
	printf("La multiplicacion de los numeros impares es: ");
	for (int i = 0; i < n; ++i)
	{
		if(array[i]%2 != 0){
			multi *= array[i];
		}
	}
	printf("%d\n", multi);
	return 0;
}