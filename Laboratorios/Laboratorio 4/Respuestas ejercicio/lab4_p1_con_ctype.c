#include <stdio.h>
#include <ctype.h>

#define MAX_FRASE 256

int main() {
	char frase[MAX_FRASE];

	printf("Ingrese una frase: ");
    scanf("%[^\n]s", frase);

	for (int i = 0; frase[i] != '\0'; i++)
	{
		if (isalpha(frase[i]))
		{
			if (islower(frase[i]))
			{
				frase[i] = toupper(frase[i]);
			} else if (isupper(frase[i]))
			{
				frase[i] = tolower(frase[i]);
			}
		}
	}

	printf("Frase modificada: %s\n", frase);
	return 0;
}
