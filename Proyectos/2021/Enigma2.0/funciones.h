#ifndef funciones
#define funciones
#include "variables.h"
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
#define FWD 1
#define BCK 0

void titulo_color(){
   /*funcion donde se crea el titulo y las intrucciones
   modos de formato -[1m letra en negrita
                    -[46m fondo cian
                    -[5m parpadear
                    -entre otros */
    printf("\n");
    printf("\t\t\e[46m                                                                      \e[0m\n");
    printf("\t\t\e[46m\e[1m\e[5m  █▄ ▄█ █▀▀█ █▀▀█  █  █ █ ██  █ █▀▀█    █▀▀▀ ██  █ █ █▀▀▀ █▄ ▄█ █▀▀█  \e[0m\n");
    printf("\t\t\e[46m\e[1m\e[5m  █ ▀ █ █▄▄█ █ ▄█  █  █ █ █ █ █ █▄▄█    █▄   █ █ █ █ █ ▄▄ █ █ █ █▄▄█  \e[0m\n");
    printf("\t\t\e[46m\e[1m\e[5m  █   █ █  █ █▄▄█▄ █▄▄█ █ █  ██ █  █    █▄▄▄ █  ██ █ █▄▄█ █   █ █  █  \e[0m\n");
    printf("\t\t\e[46m                                                                      \e[0m\n");
    printf("\n"); 
    printf("\n");
    printf(" \e[1m\e[48;5;126m MODOS DE USO:\e[0m  ");
    printf(" \e[36m\e[1m*\e[0m \e[4m\e[1m\e[93monline\e[0m: Debe ingresar la letra que desea encriptar\n");
    printf("\t\t  \e[36m\e[1m*\e[0m \e[4m\e[1m\e[93marchivo\e[0m: El texto que desea encriptar se encuentra en un archivo\n");
    printf("\n");
    printf("Ingrese el modo que desea usar ( \e[38;5;204monline\e[0m o \e[38;5;204marchivo\e[0m ): ");
}

void rotoraleatorio(int li){// funcion donde se crean los rotores aleatorios tiene como paramero el numero de rotores

   srand(time(NULL));// semilla

   for (int i = 0; i <=li; ++i){
        for( int k = 0; k< 26; k++){
            
            aux = 'A'+rand()%(('Z'-'A')+1);//aux almacena la letra generada al azar
            aux2 = 0;

            while(aux2 < k){// mientras que la aux2 se manor que la iteracion de k se seguira con la instrucciones

                if(aux != arreglo[aux2]){ //si es distinta la letra generada con las letras que estan en el arreglo
                    aux2++;// aux2 aumentara en 1
                }else{// si la letra generada ya esta en el arreglo se vuelve a pedir otra letra aleatoria
                    aux = 'A'+rand()%(('Z'-'A')+1);
                    aux2 = 0;//aux2 volvera a ser 0
                }
            }
            arreglo[k] = aux; // en cada iteracion de k se guardara la letra aleatoria en el arreglo
            //mientras se cumplan estas condiciones cada letra generada se imprimira en el archivo correspondiente hasta obtener 26 letras  sin repetir

            if(i==0)fprintf(reflector, "%c\n",reflectorfijo[k]);// se imprime el reflector fijo que se encuentra en variables.h una letra a la vez
            if (i==1)fprintf(rotor1, "%c\n",arreglo[k]);
            if (i==2)fprintf(rotor2, "%c\n",arreglo[k]);
            if (i==3)fprintf(rotor3, "%c\n",arreglo[k]);
            if (i==4)fprintf(rotor4, "%c\n",arreglo[k]);
            if (i==5)fprintf(rotor5, "%c\n",arreglo[k]);

              
        }
    }     
}
//las funciones falatan3rotor,falatan4rotor,falatan5rotor son funciones donde se verifican si existen los archivos de los rotores ,tiene como parametros los nombres de dichos archivos.
//cada unas de estas funciones es llamada dependiendo de cuantos rotores se ingresaron
void faltan3rotor(int lim,char *r1,char *r2,char *r3,char *refl3){
    if (rotor1==NULL)rotor1=fopen(r1,"w");
    if (rotor2==NULL)rotor2=fopen(r2,"w");
    if (rotor3==NULL)rotor3=fopen(r3,"w"); 
    if (reflector==NULL)reflector=fopen(refl3,"w");
    rotoraleatorio(lim);

    fclose(rotor1);//se cierran los archivos
    fclose(rotor2);
    fclose(rotor3);
    fclose(reflector);

}
void faltan4rotor(int lim,char *r1,char *r2,char *r3,char *r4,char *refl4){
    if (rotor1==NULL)rotor1=fopen(r1,"w");
    if (rotor2==NULL)rotor2=fopen(r2,"w");
    if (rotor3==NULL)rotor3=fopen(r3,"w"); 
    if (rotor4==NULL)rotor4=fopen(r4,"w");
    if (reflector==NULL)reflector=fopen(refl4,"w");
    rotoraleatorio(lim);

    fclose(rotor1);
    fclose(rotor2);
    fclose(rotor3);
    fclose(rotor4);
    fclose(reflector);
}
void faltan5rotor(int lim,char *r1,char *r2,char *r3,char *r4,char *r5,char *refl5){
    if (rotor1==NULL)rotor1=fopen(r1,"w");
    if (rotor2==NULL)rotor2=fopen(r2,"w");
    if (rotor3==NULL)rotor3=fopen(r3,"w"); 
    if (rotor4==NULL)rotor4=fopen(r4,"w");
    if (rotor5==NULL)rotor4=fopen(r5,"w");
    if (reflector==NULL)reflector=fopen(refl5,"w");
    rotoraleatorio(lim);

    fclose(rotor1);
    fclose(rotor2);
    fclose(rotor3);
    fclose(rotor4);
    fclose(rotor5);
    fclose(reflector);
}
/*las funciones crear_matriz3,crear_matriz4,crear_matriz5 (es utilizada cada una de ellas dependiendo del numero de rotores) 
  leeran cada elemento que esta en cada archivo donde se encuentran los rotores y los almacenara en una matriz llamada ROTORS*/
void crear_matriz3(char *r1,char *r2,char *r3,char *re){

    rotor1=fopen(r1,"r");//se abre el archivo en modo lectura
    // Una vez que el archivo se ha abierto, este es leido caracter por caracter hasta llegar al final del archivo y a ques un contador sea menor que 26
    while(((ch=fgetc(rotor1))!=EOF && (a<26)) ){
        ROTORS[0][a]=ch;
        fgetc(rotor1);//descarta el salto de linea
        a++;//a aumenta en 1 
    }
    fclose(rotor1);//se cierra el archivo

    rotor2=fopen(r2, "r");

    a=0;
    while(((ch=fgetc(rotor2))!=EOF) && (a<26)){
        ROTORS[1][a]=ch;
        fgetc(rotor2);
        a++;
    }
    fclose(rotor2);

    rotor3=fopen(r3, "r");
      
    a=0;
    while(((ch=fgetc(rotor3))!=EOF) && (a<26)){
        ROTORS[2][a]=ch;
        fgetc(rotor3);
        a++;
    }
    fclose(rotor3);

    reflector=fopen(re, "r");

    a=0;
    while((ch=fgetc(reflector))!=EOF && a<26){
        ROTORS[3][a]=ch;
        fgetc(reflector);
        a++;
    }
    fclose(reflector);
   
}
void crear_matriz4(char *r1,char *r2,char *r3,char *r4,char *re){

    rotor1=fopen(r1,"r");

    while(((ch=fgetc(rotor1))!=EOF && (a<26)) ){
        ROTORS[0][a]=ch;
        fgetc(rotor1);
        a++;
    }
    fclose(rotor1);

    rotor2=fopen(r2, "r");

    a=0;
    while(((ch=fgetc(rotor2))!=EOF) && (a<26)){
        ROTORS[1][a]=ch;
        fgetc(rotor2);
        a++;
    }
    fclose(rotor2);
    
    rotor3=fopen(r3, "r");
    a=0;

    while(((ch=fgetc(rotor3))!=EOF) && (a<26)){
        ROTORS[2][a]=ch;
        fgetc(rotor3);
        a++;
    }
    fclose(rotor3);

    rotor4=fopen(r4, "r");
    
    a=0;
    while(((ch=fgetc(rotor4))!=EOF) && (a<26)){
        ROTORS[3][a]=ch;
        fgetc(rotor4);
        a++;
    }
    fclose(rotor4);

    reflector=fopen(re, "r");

    a=0;
    while((ch=fgetc(reflector))!=EOF && a<26){
        ROTORS[4][a]=ch;
        fgetc(reflector);
        a++;
    }
    fclose(reflector);

}

void crear_matriz5(char *r1,char *r2,char *r3,char *r4,char*r5,char *re){

    rotor1=fopen(r1,"r");

    while(((ch=fgetc(rotor1))!=EOF && (a<26)) ){
        ROTORS[0][a]=ch;
        fgetc(rotor1);
        a++;
    }
    fclose(rotor1);

    rotor2=fopen(r2, "r");
    
    a=0;
    while(((ch=fgetc(rotor2))!=EOF) && (a<26)){
        ROTORS[1][a]=ch;
        fgetc(rotor2);
        a++;
    }
    fclose(rotor2);
        
    rotor3=fopen(r3, "r");
    
    a=0;
    while(((ch=fgetc(rotor3))!=EOF) && (a<26)){
        ROTORS[2][a]=ch;
        fgetc(rotor3);
        a++;
    }
    fclose(rotor3);


    rotor4=fopen(r4, "r");
        
    a=0;
    while(((ch=fgetc(rotor4))!=EOF) && (a<26)){
        ROTORS[3][a]=ch;
            fgetc(rotor4);
            a++;
    }
    fclose(rotor4);
    
    rotor5=fopen(r5, "r");
    a=0;

    while(((ch=fgetc(rotor5))!=EOF) && (a<26)){
        ROTORS[4][a]=ch;
        fgetc(rotor5);
        a++;
    }
    fclose(rotor5);

    reflector=fopen(re, "r");
    
    a=0;
    while((ch=fgetc(reflector))!=EOF && a<26){
        ROTORS[5][a]=ch;
        fgetc(reflector);
        a++;
    }
    fclose(reflector);
}

// la funcion map tiene 3 parametros, el caracter a encriptar, el rotor que sera usado, y la direccion en la que sera encriptado.
char map(char letter, int rotor, int direction) {
    
    // Si se encripta con direccion == 1, se calcula la letra correspondiente usando el valor numerico del caracter y se le resta el valor numerico de la letra A, de esta forma se obtienen numeros del 0 al 25.

    if (direction){
        return ROTORS[rotor][letter - 'A'];
    // Si la direccion es 0, se busca a que letra corresponde la posicion en la que esta el caracter en el rotor. 0=A, 1=B, 2=C, ..., 25=Z.
    }else{
        for (int i = 0; i < 26; i++)
            if (ROTORS[rotor][i] == letter)
                return 'A' + (char) i;
        return letter;
    }
}
// La funcion rotate solo necesita como parametro el rotor a ser rotado.
void rotate(int rotor) {
    
    char aux = ROTORS[rotor][25];// Se guarda el ultimo caracter en una variable auxiliar. 
    for (int i = 0; i < 25; i++)
        ROTORS[rotor][25 - i] = ROTORS[rotor][24 - i];// Se copian los caracteres de la posicion 24 a la 25, de la 23 a la 24 y asi sucesivamente.
    ROTORS[rotor][0] = aux; // una vez se copia el caracter en la posicion 0 a la 1, se copia el caracter que estaba inicialmente en la posicion 25 a la 0.
  
}



#endif
