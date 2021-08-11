# Implementación de una máquina Enigma para encriptación de mensajes

Para el primer proyecto del curso nos enfocaremos en el sistema de encriptación utilizado por la *Máquina Enigma*. Un sistema de encriptación o cifrado nos permite ocultar la información contenida
en un mensaje, de tal manera que no puede ser entendido por quien no conoce el mecanismo para revertir el proceso, recuperando el mensaje original. Es por ello que los sistemas de encriptación son
utilizados para mejorar la seguridad en la transmisión de mensajes, transacciones, etc, como es el caso de los mensajes enviados por Whatsapp.

En esta ocasión nos dedicaremos a estudiar la máquina enigma, un sistema de encriptación electro-mecánica de inicios del siglo XX. La máquina enigma fue desarrollada post-primera guerra mundial y
jugó un rol importante durante el desarrollo de la segunda guerra mundial. La máquina tiene la cualidad de encriptar y desencriptar mensajes, sin necesidad de utilizar una segunda máquina. Durante este
proyecto nos enfocaremos en una versión simplificada de la máquina. Esta versión simplicada consta de 3 componentes:

- **Panel de entrada**: Es el componente de entrada a la máquina, el cual captura la letra que queremos encriptar. Este componente también es utilizado como salida del proceso de encriptación.
- **Rotores**: La máquina consta de 3 rotores. En el diseño original de la máquina Enigma, cada rotor era un disco con dos caras y con 26 contactos eléctricos, uno por cada letra del alfabeto. Podemos entender un rotor como una permutación del alfabeto de 26 letras. De esta manera, cada letra será mapeada a una letra distinta. Los rotores tienen la cualidad de girar cada vez que son utilizados, de tal manera que cada vez se obtiene una nueva permutación de letras.
- **Reflector**: Como componente final, la máquina añade un reflector, el cual puede ser entendido como un rotor fijo (que no gira), y que tiene el objetivo de evitar que una letra sea mapeada a si misma. El reflector consta de 13 pares de letras. Por ejemplo, el par (A,Z) indica que la letra A será mapeada a la letra Z y viceversa.

La Figura 1 muestra la encriptación del mensaje "*HOLA*", además de detallar la configuración de los 3 rotores y el reflector. La Figura 1a muestra el caso de la letra “H”: La letra H entra al panel de entrada, el cual conecta con el rotor 1. El rotor 1 mapea H a P. Luego, utilizando el rotor 2, mapeamos P a C, para continuar con el mapeo de C a M en el rotor 3. Una vez llegados al rotor 3, se utiliza el reflector, en el cual se mapea la letra M a la letra O, iniciando el retorno a través de los rotores 3, 2 y 1 (en ese orden). Utilizando el rotor 3, se mapea la letra O a la letra M, luego el rotor 2 mapea M a O, para finalmente mapear O a Z en el rotor 1. De esta manera, la letra H será encriptada como Z. 

| ![Encriptación HOLA](img/enigma1.png) |
|:--:|
| <b>Figura 1.</b> Encriptación de la palabra "HOLA".|

Un paso muy importante ocurre luego de encriptar una letra: Cada vez que una letra es encriptada, el rotor 3 gira una vez, cambiando su permutación. Una vez que el rotor 3 ha girado 26 veces, el rotor 2 gira una vez. De igual manera, luego que el rotor 2 gire 26 veces, el rotor 1 girará una vez. (Nota: este mismo efecto se puede apreciar en el contador de kilometraje de los automóviles). Por ejemplo, luego de encriptar la letra H (Figura 1a), el rotor 3 giró una vez, como puede apreciarse en la Figura 1b. Siguiendo este procedimiento, podemos encriptar las letras O, L y A como A, X y P (ver Figuras 1b, 1c y 1d). De esta manera, la palabra "*HOLA*" será encriptada como "*ZAXP*".

Nótese que la posición de los rotores en la Figura 1a es diferente a la posición de los rotores en la Figura 1d, ya que hemos encriptado 4 letras.

La máquina enigma sigue un procedimiento simétrico para desencriptar mensajes. Como condición para iniciar el procedimiento de desencriptación, la posición de los rotores debe estar en la misma de cuando el mensaje fue encriptado. Podemos ver el procedimiento de desencriptación de la palabra "ZAXP" en la Figura 2. Notar que la posición inicial de los rotores en la Figura 2 es la misma posición de los rotores en la Figura 1. Esta condición es obligatoria para que la desencriptación sea exitosa. Una vez la posición inicial de los rotores es establecida, procedemos a desencriptar "ZAXP", siguiendo el mismo procedimiento de encriptación de la Figura 1. La Figura 2a muestra cómo la letra "Z" es mapeada a la letra "H". De manera similar, las Figuras 2b, 2c y 2d muestran el mapeo de "A", "X" y "P" a "O", "L", y "A". Así, sabemos que el mensaje cifrado "ZAXP" corresponde al mensaje original "HOLA".

Vale la pena mencionar que el giro de los rotores aumenta la seguridad de la máquina, ya que dos letras iguales y consecutivas nunca serán encriptadas con la misma letra. Por ejemplo, tomando la posición inicial de los rotores en la Figura 1a, la palabra "AAA" será encriptada como "UOH".

| ![Desencriptación ZAXP](img/enigma2.png) |
|:--:|
| <b>Figura 2.</b> Desencriptación de la palabra "ZAXP".|

En resumen, para este proyecto se pide simular el funcionamiento de una máquina Enigma utilizando el lenguaje de programación C. En el desarrollo de su proyecto considere los siguientes detalles:

1. Para la implementación de los rotores y el reflector, utilice la configuración (permutaciones) de la Figura 1a. No hay necesidad de crear nuevas permutaciones.
2. En frases compuestas por más de una palabra, los espacios no serán encriptados. Es decir, los espacio permanecerán como espacios.
3. Para la implementación, el mensaje a encriptar deberá estar contenido en un archivo de texto, el cual debe ser leído por su programa en C. De igual manera, el mensaje encriptado, resultante del proceso de encriptación, deberá ser escrito en un archivo de salida.
4. 4. Para el desarrollo del proyecto, considere sólo las 26 letras mayúsculas utilizadas en las Figuras 1 y 2.
5. Modularidad: En este proyecto se pedirá un mínimo de modularidad en el desarrollo del código. Como mínimo, la definición de los rotores y el reflector deberán estar almacenados en un archivo separado al resto del código. Para ello, utilice un archivo de cabecera .h.
6. Documentación: El código debe estar debidamente comentado. Cada sección del código debe contener comentarios que expliquen lo que hace. Sea lo más completo posible.
7. El proyecto se realizará de manera individual. Ante la existencia de dos o más proyectos idénticos, todos los proyectos involucrados serán calificados con NCR.
8. Es posible utilizar recursos de la Web. Si se utiliza código fuente de terceros, se debe referenciar de manera adecuada, dando crédito al/la autor/a. Se puede utilizar códigos de terceros en hasta un 30% del código final del proyecto. Porcentajes mayores pueden ser considerados plagio.
