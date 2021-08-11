/*****************************************************************
 ***   Proyecto: Implementación de una máquina Enigma   
 ***   Año     : 2020                                        
 ***   Autor   : Vicente Cser <vcser2018@udec.cl>          
 ***   Archivo : main.c
 ***
 ***   Compilación: gcc -o enigma main.c
 ***   Ejecución  : ./enigma <archivo entrada> <archivo salida>
 *****************************************************************/

#include <stdio.h>
#include "components.h"

int main(int argc, char *argv[]) {
    /*
     * Primero se verifica que se hayan entregado exactamente 2 argumentos al programa.
     * Luego se inicializan las variables.
     * Despues se abren los archivos de texto que tienen el nombre de los argumentos entregados.
     * Se procede a leer caracter por caracter el archivo de entrada y se escribe inmediatamente en el archivo de salida la letra encriptada usando la funcion map() que esta definida en components.h
     * Cada vez que un caracter es encriptado se gira el rotor correspondiente usando la funcion rotate() que esta definida en components.h
     * Si un caracter no es una letra mayuscula de la A a la Z, este se escribe tal cual en el archivo de salida y los rotores no son rotados.
     * Una vez se llega al final del archivo de entrada, se cierran los archivos y el programa termina.
     *
     */
    if (argc != 3) {
        printf("modo de uso: %s <archivo entrada> <archivo salida>\n", argv[0]);
        return 0;
    }

    unsigned int c = 0; // Esta variable contara cuantas letras han sido encriptadas.
    char ch;  // Variable que almacena el caracter que esta siendo leido.
    FILE *encrypted, *unencrypted; // Punteros a los archivos de entrada y salida.
    
    // Se abren los archivos de entrada y salida. El archivo de entrada debe estar en la misma carpeta que el programa.
    unencrypted = fopen(argv[1], "r");
    encrypted = fopen(argv[2], "w");
    
    // Se verifica que el archivo de entrada exista, en caso contrario se imprime un aviso y el programa termina.
    if (unencrypted == NULL)
        printf("archivo no encontrado\n");
    else {
        // Una vez que el archivo se ha abierto, este es leido caracter por caracter hasta llegar al final del archivo.
        while( (ch = fgetc(unencrypted)) != EOF )

            // Se verifica que el caracter sea una letra mayuscula de la A a la Z.
            if (ch >= 'A' && ch <= 'Z') {

                // Se encripta el caracter usando la funcion map(), y se escribe inmediatamente al archivo de salida.
                fprintf(encrypted,"%c", map(map(map(map(map(map(map(ch, 0, FWD), 1, FWD), 2, FWD), 3, FWD), 2, BCK), 1, BCK), 0, BCK));
                rotate(2); // El tercer rotor es rotado. 
                c++; // Se cuenta cada vez que un caracter es encriptado.

                // Si el rotor 3 ha sido rotado 26 veces, se rota una vez el rotor 2.
                if (c%26 == 0 && c != 0)
                    rotate(1);

                // Si el rotor 2 ha sido rotado 26 veces, se rota una vez el rotor 1.
                if (c%676 == 0 && c != 0)
                    rotate(0);

            // Cualquier caracter que no sea una letra mayuscula es escrito tal cual al archivo de salida.
            } else
                fprintf(encrypted,"%c", ch);
    }
    // Se cierran los archivos y el programa termina.
    fclose(unencrypted);
    fclose(encrypted);
    return 0;
}
