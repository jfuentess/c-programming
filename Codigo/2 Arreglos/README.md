# Arreglos en C

Esta carpeta contiene programas sencillos para aprender a programar usando
arreglos en una y dos dimensiones (matrices). Está compuesta por los siguientes
archivos y carpetas:

### Arreglos en una dimensión

 - `arreglos/primer_arreglo.c`: Declaración de un arreglo básico.

 - `arreglos/inicializacion_arreglo.c`: Inicialización de un arreglo usando la
   función `scanf()`.

 - `arreglos/buscar_minimo.c`: Implementación de la búsqueda del menor elemento
   en un arreglo.

 - `arreglos/palindromo.c`: Implementación que verifica si una cadena de
   caracteres es un palíndromo.

 - `arreglos/selection_sort.c`: Implementación del algoritmo *selection sort*
   basada en la solución del archivo `arreglos/buscar_minimo.c`.

 - `arreglos/arreglo_insercion.c`: Implementación de la inserción de un nuevo
   elemento en un arreglo.

 - `arreglos/patrones.c`: Búsqueda de un patrón en un texto usando arreglos de caracteres.

 - `arreglos/permutaciones.c`: Búsqueda de todos los ciclos de una permutación

 - `arreglos/batalla.c`: Resolución del problema 1991 de la plataforma Timus


---

### Matrices

  - `matrices/matrices_2D_3D.c`: Declaración de matrices en 2 y 3 dimensiones.
  - `matrices/suma_matrices.c`: Implementación de la clásica suma de matrices
  - `matrices/mult_matrices.c`: Implementación de la clásica multiplicación de matrices. Incluye funciones para medir el tiempo de ejecución.
  - `matrices/transposicion.c`: Implementación de la transposición de una matriz
  - `matrices/mult_trans_matrices.c`: Implementación de la multiplicación de matrices basada en matriz transpuesta. Incluye funciones para medir el tiempo de ejecución.
  - `matrices/imagen_rgb.c`: Conversión de matrices R(ed), G(reen), B(lue) a una
     imagen en formato PNG. La implementción utiliza la función `svpng()` almacenada en el archivo `arreglos/svpng.inc`.
  - `matrices/escala_grises.c`: Conversión a escala de grises de una imagen RGB.
  - `matrices/propagacion.c`: Propagación de valores en una matriz de 2 dimensiones. Los valores son visualizados como una imagen RGB.
  - `matrices/matrices.h`: Declaración de matrices en 2 dimensiones. Las
      matrices corresponden a matrices RGB del personaje principal de Súper Mario.
  - `matrices/svpng.inc`: Implementación de una función para almacenar imágenes
    RGB en formato uncompressed PNG. La implementación pertenece a Milo Yip y
    puede ser vista en el siguiente [enlace](https://github.com/miloyip/svpng).

