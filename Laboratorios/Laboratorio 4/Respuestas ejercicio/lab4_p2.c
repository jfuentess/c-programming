#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FRASE 256
#define MAX_PALABRA 64

int main() {
	char frase[MAX_FRASE];
	char palabra[MAX_PALABRA];
	int n;

	printf("Ingrese una frase: ");
    scanf("%[^\n]s", frase);

	printf("Ingrese una palabra: ");
	scanf("%s", palabra);

	int len_p = strlen(palabra);
	do
    {
		printf("Ingrese un número entero n (<= %d): ", len_p);
		scanf("%d", &n);
	} while (n > len_p || n <= 0);

	// Separar palabras de la frase
	char frase_copia[MAX_FRASE];
	strncpy(frase_copia, frase, MAX_FRASE);
	frase_copia[MAX_FRASE-1] = '\0';
	char *token = strtok(frase_copia, " ");
	char palabra_corta[MAX_PALABRA] = "";
	char palabra_larga[MAX_PALABRA] = "";
	int min_len = MAX_PALABRA, max_len = 0;
	int coincidencia = 0;

	while (token)
    {
		int len = strlen(token);
		if (len < min_len)
        {
			min_len = len;
			strncpy(palabra_corta, token, MAX_PALABRA);
			palabra_corta[MAX_PALABRA-1] = '\0';
		}
		if (len > max_len)
        {
			max_len = len;
			strncpy(palabra_larga, token, MAX_PALABRA);
			palabra_larga[MAX_PALABRA-1] = '\0';
		}
		if (strncmp(token, palabra, n) == 0) 
        {
			coincidencia = 1;
		}
		token = strtok(NULL, " ");
	}

    printf("\n");
	printf("Palabra más corta: %s\n", palabra_corta);
	printf("Palabra más larga: %s\n", palabra_larga);
	if (coincidencia)
    {
		printf("Existe coincidencia de los primeros %d caracteres de la palabra '%s' en la frase.\n", n, palabra);
	} else
    {
		printf("No existe coincidencia de los primeros %d caracteres de la palabra '%s' en la frase.\n", n, palabra);
	}

	return 0;
}
