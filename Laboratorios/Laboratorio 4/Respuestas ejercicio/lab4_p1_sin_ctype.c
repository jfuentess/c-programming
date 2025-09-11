#include <stdio.h>
#include <string.h>

#define MAX_FRASE 256

int main() {
	char frase[MAX_FRASE];

	printf("Ingrese una frase: ");
    scanf("%[^\n]s", frase);

	for (int i = 0; frase[i] != '\0'; i++)
    {
		if (frase[i] >= 'a' && frase[i] <= 'z')
        {
			frase[i] = frase[i] - 'a' + 'A';
		}
		else if (frase[i] >= 'A' && frase[i] <= 'Z')
        {
			frase[i] = frase[i] - 'A' + 'a';
		}
	}

	printf("Frase modificada: %s\n", frase);
	return 0;
}