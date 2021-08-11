/*****************************************************************
 ***   Proyecto: Implementación de una máquina Enigma   
 ***   Año     : 2020                                        
 ***   Autor   : Vicente Cser <vcser2018@udec.cl>          
 ***   Archivo : components.h
 *****************************************************************/

/*
 * En este archivo estan definidas las funciones map() y rotate(), y dos constantes FWD = 1 y BCK = 0 que son usadas en la funcion map.
 * Tambien estan definidos los rotores y el reflector en un arreglo de dos dimensiones.
 *
 */

#ifndef COMPONENTS
#define COMPONENTS
#define FWD 1
#define BCK 0
#include <stdio.h>

char ROTORS[4][26] = {{'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'},  // Rotor 1
                      {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'},  // Rotor 2
                      {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'},  // Rotor 3
                      {'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'}}; // Reflector

// Esta funcion necesita 3 parametros, el caracter a encriptar, el rotor que sera usado, y la direccion en la que sera encriptado.
char map(char letter, int rotor, int direction) {

    // Si se encripta con direccion == 1, se calcula la letra correspondiente usando el valor numerico del caracter y se le resta el valor numerico de la letra A, de esta forma se obtienen numeros del 0 al 25.
    if (direction)
        return ROTORS[rotor][letter - 'A'];

    // Si la direccion es 0, se busca a que letra corresponde la posicion en la que esta el caracter en el rotor. 0=A, 1=B, 2=C, ..., 25=Z.
    else
        for (int i = 0; i < 26; i++)
            if (ROTORS[rotor][i] == letter)
                return 'A' + (char) i;
        return letter;
}

// La funcion rotate solo necesita como parametro el rotor a ser rotado.
void rotate(int rotor) {
    char aux = ROTORS[rotor][25]; // Se guarda el ultimo caracter en una variable auxiliar.
    for (int i = 0; i < 25; i++)
        ROTORS[rotor][25 - i] = ROTORS[rotor][24 - i]; // Se copian los caracteres de la posicion 24 a la 25, de la 23 a la 24 y asi sucesivamente.
    ROTORS[rotor][0] = aux; // una vez se copia el caracter en la posicion 0 a la 1, se copia el caracter que estaba inicialmente en la posicion 25 a la 0.
}

#endif
