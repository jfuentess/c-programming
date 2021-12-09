# Mejorando la seguridad de la Máquina Enigma

En el primer proyecto del curso continuaremos con la implementación de la
Máquina Enigma, desarrollada durante la versión 2020 del mismo curso. La máquina
enigma implementa un sistema de encriptación de mensajes, el cual permite
ocultar la información contenida en un mensaje, de tal manera que no puede ser
entendido por quien no conoce el mecanismo para revertir el proceso, recuperando
el mensaje original. Los sistemas de encriptación son utilizados para mejorar la
seguridad en la transmisión de mensajes, transacciones, etc, como es el caso de
los mensajes enviados por Whatsapp.

En el siguiente enlace: [link a enigma](../../2020/Enigma), está la
implementación de una máquina enigma simplificada, la cual fue desarrollada el
año pasado como el primer proyecto de este mismo curso. La implementación
provista está compuesta por los siguientes componentes: 

- **Panel de entrada**: Es el componente de entrada a la máquina, el cual captura la letra que queremos encriptar. Este componente también es utilizado como salida del proceso de encriptación.
- **Rotores**: La máquina consta de 3 rotores. En el diseño original de la máquina Enigma, cada rotor era un disco con dos caras y con 26 contactos eléctricos, uno por cada letra del alfabeto. Podemos entender un rotor como una permutación del alfabeto de 26 letras. De esta manera, cada letra será mapeada a una letra distinta. Los rotores tienen la cualidad de girar cada vez que son utilizados, de tal manera que cada vez se obtiene una nueva permutación de letras.
- **Reflector**: Como componente final, la máquina añade un reflector, el cual puede ser entendido como un rotor fijo (que no gira), y que tiene el objetivo de evitar que una letra sea mapeada a si misma. El reflector consta de 13 pares de letras. Por ejemplo, el par (A,Z) indica que la letra A será mapeada a la letra Z y viceversa.

Para más detalles de la implementación, revisar el enlace anterior. Para quienes
quieran saber más sobre la historia y funcionamiento de las máquinas Enigma, les
recomiendo el siguiente [video (con subtítulos)](https://www.youtube.com/watch?v=G2_Q9FoD-oQ&feature=emb_logo) y
[animación](https://observablehq.com/@tmcw/enigma-machine).

En este nuevo proyecto nos enfocaremos en aumentar la seguridad de la
implementación actual. Para ello, consideraremos los siguientes puntos: 

1. En la implementación actual la configuración (o permutación inicial) de los 3
rotores es fija. Por ejemplo, en la Figura 1a del enlace (Enlaces a un sitio
externo.), la letra A siempre será mapeada a la letra B en el primer rotor, a la
letra A para el segundo rotor y a la letra E en el tercer rotor. Esto genera un
problema de seguridad, ya que si queremos que nuestro mensaje encriptado sea
seguro, entonces la configuración de los rotores también debe ser secreta. 
2. En la versión original de la máquina enigma, se debían elegir 3 rotores entre
5 rotores disponibles, cada uno con una configuración o cableado fijo. Hay una
relación directa entre la cantidad de rotores y la seguridad de la
máquina. Entre más rotores, mayor es la cantidad de combinaciones que puede
generar la máquina, por lo que es más difícil obtener la configuración correcta
para desencriptar los mensajes. De esta manera, ya que la implementación actual
sólo usa 3 rotores, su seguridad podría aumentar si se usan más rotores. 

De manera concreta, para entre proyecto se piden los siguientes puntos:

A. Por cada rotor utilizado en la máquina, su configuración se debe cargar desde
un archivo de entrada. En el caso de que para un rotor no se indique ningún
archivo de entrada, entonces el programa deberá generar la configuración de
dicho rotor de manera aleatoria (usar función rand( ) ). Nótese que para el
proceso de desencriptación, la máquina Enigma necesita comenzar con los mismos
rotores utilizados en el proceso de encriptación. Es por ello que, de generarse
de manera aleatoria la configuración de un rotor, dicha configuración deberá ser
almacenada en un archivo para su uso posterior. 
B. El programa a implementar deberá permitir utilizar entre 3 y 5 rotores. La
cantidad de rotores se indicará como parámetro al momento de iniciar la
ejecución del programa. 
C. En la implementación actual, el mensaje a encriptar está almacenado en un
archivo de entrada. De esta manera, si usted quiere encriptar un mensaje, deberá
escribir dicho mensaje en un archivo de texto antes de poder encriptarlo. A esta
nueva versión se le añadirá un modo de encriptado online. Cada vez que se inicie
el programa se deberá consultar si se quiere encriptar un mensaje desde un
archivo (la implementación actual) o se desea entrar en modo online. En el modo
online, cada vez que se ingresa un nueva letra, automáticamente esa letra será
encriptada y el resultado mostrado por pantalla. 




## Solución propuesta
- Autor   : Yulissa Sanhueza (ysanhueza2019@udec.cl)          
- Archivos : main.c, funciones.h y variables.h
- Compilación: 
 ```
gcc -o enigma main.c
 ```
- Ejemplo ejecución  : 
 ```
./enigma 3 rotor1.txt rotor2.txt rotor3.txt reflector.txt entrada.txt salida.txt
 ```
 ```
./enigma 4 rotor1.txt rotor2.txt rotor3.txt rotor4.txt reflector.txt entrada.txt salida.txt
 ```
 ```
./enigma 5 rotor1.txt rotor2.txt rotor3.txt rotor4.txt rotor5.txt reflector.txt entrada.txt salida.txt
 ```
