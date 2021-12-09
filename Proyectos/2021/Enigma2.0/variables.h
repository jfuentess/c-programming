#ifndef variables
#define variables


FILE *rotor1,*rotor2,*rotor3,*rotor4,*rotor5,*reflector,*entrada, *salida;

char arreglo[26]={};//se usa en la funcion rotoraleatorio
int aux = 0,aux2;//variables auxiliares para generar letras aleatorias
int cant_rotor;//almacena el numero del argumento arg[1]
char modo[10]={};//para almacenar la palabra donde se indica el modo de us
char ch=0;
char m;
int j=0;//variables para crear la matriz de rotores
unsigned int c = 0; 
int a=0;//se usa en crearmatriz
char co[100];//almacenara la palabra que se quiere enciptar
char ROTORS[6][26]={{0}};//matriz donde se almacenaran los rotores
char reflectorfijo[]={'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'};
// en caso de que no exista el archivo reflector se usara este
int contador_rojo=0;//contador de letras minusculas en rojo






#endif