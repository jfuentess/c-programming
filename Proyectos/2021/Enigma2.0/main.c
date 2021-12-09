/*****************************************************************
 ***   Proyecto: Mejorando la seguridad de la Máquina Enigma   
 ***   Año     : 2021                                        
 ***   Autor   : Yulissa Sanhueza <ysanhueza2019@udec.cl>        
 ***   Archivo : main.c
 ***
 ***   Compilación: gcc -o enigma main.c
 ***   Ejecución  : ./enigma <numero de rotores> <nombre de los archivos de cada rotor> <archivo reflector> <archivo entrada> <archivo salida>
 *****************************************************************/

#include <stdio.h>
#include "funciones.h"
#include "variables.h"
#include <stdlib.h>
#include<time.h>
#include <string.h>

/*-Compilación: gcc -o enigma main.c
  -Ejecución  : ./enigma (numero de rotores)( nombre de los archivos de cada rotor) (archivo reflector)(archivo entrada)(nombre archivo salida)
     EJEMPLO DE EJECUCION: ./enigma 3 rotor1.txt rotor2.txt rotor3.txt reflector.txt entrada.txt salida.txt 
     DATO: solo es necesario ingresar un archivo de entrada si se quiere usar el modo archivo 
*/   

int main(int argc, char *argv[]){

    //Se verifica la cantidad de argumentos que fueron ingresados 
    if (argc<6 || argc > 10) {
        printf("modo de uso: %s <numero de rotores> < nombre de los archivos de cada rotor> <archivo reflector> <archivo entrada> <archivo salida>\n", argv[0]);
        return 0;
    }

    cant_rotor=atoi(argv[1]); //convierte el argumento de la cadena argv[1] en un entero(tipo int)
    //verifica que la cantidad de rotores se encuentre entre 3 y 5 si esta no se cumple se termina el programa
    if (cant_rotor < 3){
        printf("Usted ingreso la cantidad de %d rotores que es menor a la cantidad minima de rotores.\n",cant_rotor);
        printf("Recuerde que la cantidad de rotores es de 3 a 5\n");
        return 0;
    }else if (cant_rotor > 5){
        printf("Usted ingreso la cantidad de %d rotores que es mayor a la cantidad maxima de rotores.\n",cant_rotor);
        printf("Recuerde que la cantidad de rotores es de 3 a 5\n");
        return 0;
    }
    // dependiendo de la cantidad de rotores entre 3 a 5 que fueron ingresados se comprueba si existen los archivos 
    if (cant_rotor == 3 ){  
        
        rotor1=fopen(argv[2], "r");
    	rotor2=fopen(argv[3], "r");
    	rotor3=fopen(argv[4], "r");
    	reflector=fopen(argv[5], "r");
        entrada = fopen(argv[6], "r");
        salida = fopen(argv[7], "w");// se crea el archivo de salida
      
        faltan3rotor(cant_rotor,argv[2],argv[3],argv[4],argv[5]);// esta funcion se encuentra en funciones.h si falta algun archivo (rotor o reflector) lo creeara de forma aleatoria
    }

    if (cant_rotor == 4){
        
    	rotor1=fopen(argv[2], "r");
    	rotor2=fopen(argv[3], "r");
    	rotor3=fopen(argv[4], "r");
    	rotor4=fopen(argv[5], "r");
    	reflector=fopen(argv[6], "r");
    	entrada = fopen(argv[7], "r");
    	salida = fopen(argv[8], "w");

        faltan4rotor(cant_rotor,argv[2],argv[3],argv[4],argv[5],argv[6]);
    }

    if (cant_rotor == 5){
     
    	rotor1=fopen(argv[2], "r");
    	rotor2=fopen(argv[3], "r");
    	rotor3=fopen(argv[4], "r");
    	rotor4=fopen(argv[5], "r");
    	rotor5=fopen(argv[6], "r");
    	reflector=fopen(argv[7], "r");
    	entrada = fopen(argv[8], "r");
    	salida = fopen(argv[9], "w");
    	
        faltan5rotor(cant_rotor,argv[2],argv[3],argv[4],argv[5],argv[6],argv[7]);
    }
    
    titulo_color();//funcion donde se crea el titulo y las instrucciones
    scanf("%s",modo);//se ingresa una cadena de caracteres por teclado
    
    char on[]="online";
    char ar[]="archivo";
    //se compara con la funcion (strcmmp) la palabra ingresada con la palabra archivo o online que se encuentran almacenadas en arreglos separados tipo char  

    int compo=strcmp(modo,on);
    int compa=strcmp(modo,ar);

    // se crea una matriz donde iran almacenados los elementos de cada archivo que contenga los rotores 
    if (cant_rotor == 3)crear_matriz3(argv[2],argv[3],argv[4],argv[5]);
    if (cant_rotor == 4)crear_matriz4(argv[2],argv[3],argv[4],argv[5],argv[6]);
    if (cant_rotor == 5)crear_matriz5(argv[2],argv[3],argv[4],argv[5],argv[6],argv[7]);

    if (compo==0){// se eligio el modo online
        printf("Ingrese la palabra a encriptar:\n");
        scanf(" %[^\n]s",co);// palabra que se quiere encriptar
        printf("Su palabra encriptada es:\n");

        for (int i = 0; i <strlen(co) ; ++i){
        // Se verifica que cada caracter de la palabra ingresada sea una letra mayuscula.
            if (co[i] >= 'A' && co[i] <= 'Z') {

                if (cant_rotor==3){
                    printf("%c", map(map(map(map(map(map(map(co[i], 0, FWD), 1, FWD), 2, FWD), 3, FWD), 2, BCK), 1, BCK), 0, BCK));
                    rotate(2);// El tercer rotor es rotado.
                    c++;// Se cuenta cada vez que un caracter es encriptado.
                    if (c%26 == 0 && c != 0) 
                        rotate(1);
                    if (c%676 == 0 && c != 0) 
                        rotate(0);
                    }

                if (cant_rotor==4){

                    printf("%c",map(map(map(map(map(map(map(map(map(co[i], 0, FWD), 1, FWD), 2, FWD), 3, FWD), 4, FWD), 3, BCK), 2, BCK), 1, BCK), 0, BCK));
                    rotate(3);
                    c++;
                    if (c%26 == 0 && c != 0) 
                        rotate(2);
                    if (c%676 == 0 && c != 0) 
                        rotate(1);
                    if (c%17576 == 0 && c != 0) 
                        rotate(0);
                    }

                if (cant_rotor==5){

                    printf("%c",map(map(map(map(map(map(map(map(map(map(map(co[i], 0, FWD), 1,FWD ), 2, FWD ),3, FWD), 4, FWD), 5, FWD), 4, BCK), 3, BCK), 2, BCK), 1, BCK), 0, BCK));
                    rotate(4);
                    c++;
                    if (c%26 == 0 && c != 0) rotate(3);
                    if (c%676 == 0 && c != 0) rotate(2);
                    if (c%17576 == 0 && c != 0) rotate(1);
                    if (c%26 ==456976 && c != 0) rotate(0);
                }
            }else{
                printf("\e[31m\e[1m%c\e[0m",co[i]);
                contador_rojo++;
            }
        }
        printf("\n");
        if(contador_rojo!=0)
            printf("\e[31m\e[1m\e[5mCUIDADO\e[0m las letras en rojo no son una letra mayúscula\n");
    }else if (compa==0){//se encriptara lo que esta en un archivo
        //Se verifica que el archivo de entrada exista, en caso contrario se imprime un aviso y el programa termina.

        if (entrada == NULL){
            printf("El archivo a encriptar no fue encontrado\n");
            return 0;

        }else {
            // Una vez que el archivo se ha abierto, este es leido caracter por caracter hasta llegar al final del archivo

            while( (m = fgetc(entrada)) != EOF )

                if (m >= 'A' && m <= 'Z') {

                    if (cant_rotor==3){
                       // Se encripta el caracter usando la funcion map(), y se escribe inmediatamente al archivo de salida.
                        fprintf(salida,"%c", map(map(map(map(map(map(map(m, 0, FWD), 1, FWD), 2, FWD), 3, FWD), 2, BCK), 1, BCK), 0, BCK));
                        rotate(2);// El tercer rotor es rotado.
                        c++;// Se cuenta cada vez que un caracter es encriptado.
                        // Si el rotor 3 ha sido rotado 26 veces, se rota una vez el rotor 2.
                        if (c%26 == 0 && c != 0) 
                            rotate(1);
                        // Si el rotor 2 ha sido rotado 26 veces, se rota una vez el rotor 1.
                        if (c%676 == 0 && c != 0) 
                            rotate(0);
                    }

                    if (cant_rotor==4){

                        fprintf(salida,"%c",map(map(map(map(map(map(map(map(map(m, 0, FWD), 1, FWD), 2, FWD), 3, FWD), 4, FWD), 3, BCK), 2, BCK), 1, BCK), 0, BCK));
                        rotate(3);
                        c++;
                        if (c%26 == 0 && c != 0) 
                            rotate(2);
                        if (c%676 == 0 && c != 0) 
                            rotate(1);
                        if (c%17576 == 0 && c != 0) 
                            rotate(0);
                    }

                    if (cant_rotor==5){

                        fprintf(salida,"%c",map(map(map(map(map(map(map(map(map(map(map(m, 0, FWD), 1,FWD ), 2, FWD ),3, FWD), 4, FWD), 5, FWD), 4, BCK), 3, BCK), 2, BCK), 1, BCK), 0, BCK));
                        rotate(4);
                        c++;
                        if (c%26 == 0 && c != 0) rotate(3);
                        if (c%676 == 0 && c != 0) rotate(2);
                        if (c%17576 == 0 && c != 0) rotate(1);
                        if (c%26 ==456976 && c != 0) rotate(0);
                    }
                } else// si no es una letra mayuscula se escribe igual en el archivo de salida
                  fprintf(salida,"%c", m);
            }
            fclose(entrada);//se cierran los archivos
            fclose(salida);
            printf("\e[42m\e[1mSu archivo ya fue encriptado.\e[0m\n");
    }else{// en caso que no se escriba online o archivo
        printf("\n");
        printf(" \e[101m¡¡ERROR!!\e[0m No ingreso ninguno de los modos indicados.\n");
        printf("\n");
        printf(" \e[46mVuelva a intentarlo :)\e[0m\n");
        printf("\n");
    }

    return 0;
}
